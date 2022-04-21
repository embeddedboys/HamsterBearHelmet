#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h> 
#include <poll.h>
#include <signal.h>
#include <errno.h>
#include <linux/joystick.h>
#include <linux/kernel.h>
#include <pthread.h>
#include "joypad_input.h"

static struct joypad_device *g_pt_joypad_head = NULL;
static struct joypad_data g_joypad_data;

static pthread_mutex_t g_mutex  = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  g_cond   = PTHREAD_COND_INITIALIZER;

uint32_t joypad_process_event(struct joypad_data *data)
{

	int pjs_event_type = data->jsevent.type;
	static uint8_t axis_area;

	pjs_event_type = pjs_event_type & ~JS_EVENT_INIT;

	switch (pjs_event_type)
	{
	case JS_EVENT_BUTTON:

		if (data->jsevent.value)
		{
			data->buttons_state |= (1 << data->jsevent.number);
		}
		else
		{
			data->buttons_state &= ~(1 << data->jsevent.number);
		}
		break;

	case JS_EVENT_AXIS:	/* Only two adjacent keys can be pressed at the same time */
		if (data->jsevent.value != 0)
		{
			data->axis_state |= (1 << (data->jsevent.number + (data->jsevent.value > 0 ? 0:2)));

			if(MULTI_KEY_DETECT(data->axis_state, AXIS_KEY_DOWN, AXIS_KEY_RIGHT))
				axis_area = AXIS_AREA_DOWN_RIGHT;	
			else if(MULTI_KEY_DETECT(data->axis_state, AXIS_KEY_RIGHT, AXIS_KEY_TOP))
				axis_area = AXIS_AREA_TOP_RIGHT;
			else if(MULTI_KEY_DETECT(data->axis_state, AXIS_KEY_DOWN, AXIS_KEY_LEFT))
				axis_area = AXIS_AREA_LEFT_DOWN;
			else if(MULTI_KEY_DETECT(data->axis_state, AXIS_KEY_LEFT, AXIS_KEY_TOP))
				axis_area = AXIS_AREA_LEFT_TOP;
			else
				axis_area = AXIS_AREA_SINGLE;

			pr_debug("axis area : %d\n",axis_area);
		}
		else
		{
			switch(axis_area){
			case AXIS_AREA_LEFT_DOWN:
				if(data->jsevent.number == 0) /* AXIS LEFT RELEASE */
					data->axis_state &= ~(AXIS_KEY_LEFT);
				else if(data->jsevent.number == 1)	/* AXIS DOWN RELEASE */
					data->axis_state &= ~(AXIS_KEY_DOWN);
				break;

			case AXIS_AREA_TOP_RIGHT:
				if(data->jsevent.number == 0) /* AXIS RIGHT RELEASE */
					data->axis_state &= ~(AXIS_KEY_RIGHT);
				else if(data->jsevent.number == 1)	/* AXIS TOP RELEASE */
					data->axis_state &= ~(AXIS_KEY_TOP);
				break;

			case AXIS_AREA_LEFT_TOP:
				if(data->jsevent.number == 0) /* AXIS RIGHT RELEASE */
					data->axis_state &= ~(AXIS_KEY_LEFT);
				else if(data->jsevent.number == 1)	/* AXIS TOP RELEASE */
					data->axis_state &= ~(AXIS_KEY_TOP);
				break;

			case AXIS_AREA_DOWN_RIGHT:
				if(data->jsevent.number == 0) /* AXIS RIGHT RELEASE */
					data->axis_state &= ~(AXIS_KEY_RIGHT);
				else if(data->jsevent.number == 1)	/* AXIS TOP RELEASE */
					data->axis_state &= ~(AXIS_KEY_DOWN);
				break;

			case AXIS_AREA_SINGLE:
				data->axis_state = 0;
				break;

			default:
				data->axis_state = 0;
				break;
			}
		}
		break;

	default:
		break;
	}

	pr_debug("axis : %d, button : %d\n", data->axis_state, data->buttons_state);
	return (data->combined_state = (data->axis_state << 16 | data->buttons_state));
}


static unsigned int usb_joypad_get_event(struct joypad_data *pdata)
{
	uint32_t state = 0;

	if (!pdata)
	{
		pr_debug("joypad_data has no memory!\n");
		return -1;
	}

	if (-1 == pdata->joypad_fd)
	{
		pr_debug("joypad has not been opened!\n");
	}

	if(read(pdata->joypad_fd, &pdata->jsevent, sizeof(struct js_event)) > 0)
	{
		joypad_process_event(pdata);

		pr_debug("time : %u\n",pdata->jsevent.time)
		pr_debug("value : %d\n",pdata->jsevent.value)
		pr_debug("type : %d\n",pdata->jsevent.type)
		pr_debug("number : %d\n",pdata->jsevent.number)
	}
	/* EAGAIN is returned when the queue is empty */
	if (errno != EAGAIN)
	{
		/* error */
	}

	return state;
}

static int usb_joypad_init(struct joypad_data *pdata)
{
	int flag;	/* fcntl flag */
	struct joypad_device *pdev = container_of(pdata, struct joypad_device, data);

	/* device open */
	pr_debug("%s, device opening\n", DEFAULT_USB_JOYPAD_PATH);
	pdata->joypad_fd = open(DEFAULT_USB_JOYPAD_PATH, O_RDONLY);
	if (-1 == pdata->joypad_fd)
	{
		pr_debug("%s device not found\n", DEFAULT_USB_JOYPAD_PATH);
		return -ENODEV;
	}

	pr_debug("device init done\n");
	return 0;
}

static int usb_joypad_exit(struct joypad_data *pdata)
{
	if (pdata)
	{
		close(pdata->joypad_fd);
		free(pdata);
	}
	pr_debug("device exit done\n");
	return 0;
}

static struct joypad_device joypad_devs[] = {
	[0] = {
		.name = "usb_joypad",
		.number = 0,
		.type = JOYPAD_TYPE_USB,
		.ops = {
			.init = usb_joypad_init,
			.exit = usb_joypad_exit,
			.get_event = usb_joypad_get_event,
		},
	},
};

static void *joypad_input_thread_function(void *privdata)
{
	struct joypad_device *pdev = (struct joypad_device *)privdata;

	while(1){
		pdev->ops.get_event(&pdev->data);
		pthread_mutex_lock(&g_mutex);
		g_joypad_data = pdev->data;
		pthread_cond_signal(&g_cond);
		pthread_mutex_unlock(&g_mutex);
	}
}

static int register_joypad_device(struct joypad_device *pdev)
{
	struct joypad_device *p_tmp;

	pr_debug("registing %s\n", pdev->name);

	if (!pdev)
	{
		return -EINVAL;
	}

	/* call current device init*/
	if (pdev->ops.init && pdev->ops.init(&pdev->data))
	{
		pr_debug("device init failed, %s\n", pdev->name);
		return -ENODEV;
	}

	/* create a thread to read event */
	pthread_create(&pdev->tid, NULL, joypad_input_thread_function, (void *)pdev);

	if (!g_pt_joypad_head)
	{ /* first node */
		g_pt_joypad_head = pdev;
	}
	else
	{
		p_tmp = g_pt_joypad_head;
		while (p_tmp->p_next)
		{
			p_tmp = p_tmp->p_next;
		}
		p_tmp->p_next = pdev;
	}
	pdev->p_next = NULL;

	return 0;
}

static int unregister_joypad_devices()
{
	int ret;
	struct joypad_device *p_tmp;

	if (!g_pt_joypad_head){
		return -1;
	}

	p_tmp = g_pt_joypad_head;
	while(p_tmp){
		/* because joydevs was alloc staticly, so we can't free it */
		/* call each device exit */
		if (p_tmp->ops.exit && p_tmp->ops.exit(&p_tmp->data))
		{
			pr_debug("device exit failed, %s\n", p_tmp->name);
		}


		p_tmp = p_tmp->p_next;
	}

	/* list head remove */
	g_pt_joypad_head = NULL;

	return 0;
}

int joypad_input_init(void)
{
	int ret = 0;

	for (int i = 0; i < ARRAY_SIZE(joypad_devs); i++)
	{
		ret = register_joypad_device(&joypad_devs[i]);
		if(ret < 0)
			pr_debug("failed to  register %s\n", joypad_devs[i].name);
	}

	return ret;
}

int joypad_input_exit(void)
{
	int ret = 0;

	ret = unregister_joypad_devices();

	return ret;
}

struct joypad_data joypad_input_get_event(void)
{
	pthread_mutex_lock(&g_mutex);
	pthread_cond_wait(&g_cond, &g_mutex);
	pthread_mutex_unlock(&g_mutex);

	return g_joypad_data;
}

#if 1

int main(int argc, char **argv)
{
	int ret;
	uint32_t state;
	uint16_t buttons;
	uint16_t axis;

	uint8_t axis_high;
	uint8_t axis_low;

	ret = joypad_input_init();
	if (ret < 0)
		return -1;


	while (1)
	{
		/*
			state = USBjoypadGet();
	`
			buttons = state & 0xffff;
			axis = state >> 16;

			printf("state: %d, buttons: %d, axis: %d\n", state, buttons, axis);
			if(state & JOYPAD_KEY_X){
				printf("key X pressed!\n");
			}
			if(state & JOYPAD_KEY_A){
				printf("key A pressed!\n");
			}
			if(state & JOYPAD_KEY_B){
				printf("key B pressed!\n");
			}
			if(state & JOYPAD_KEY_Y){
				printf("key Y pressed!\n");
			}
			if(state & JOYPAD_KEY_NL){
				printf("key NL pressed!\n");
			}
			if(state & JOYPAD_KEY_NR){
				printf("key NR pressed!\n");
			}
			if(state & JOYPAD_KEY_DOWN){
				printf("key DOWN pressed!\n");
			}
			if(state & JOYPAD_KEY_START){
				printf("key START pressed!\n");
			}
		*/
	}

	joypad_input_exit();
	return 0;
}
#endif
