#if 0
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <poll.h>
#include <errno.h>
#include "button_input.h"

static uint16_t buttons_state = 0;
static uint32_t combined_state = 0;

struct adc_key{
	uint8_t *name;
	uint8_t num;
	uint8_t state:1;
};

static int USBjoypad_fd;

uint32_t USBjoypad_process_event(struct js_event *pjs_event)
{
	uint16_t axis_state = 0;

	int pjs_event_type = pjs_event->type;
	uint32_t last_base;

	pjs_event_type = pjs_event_type & ~JS_EVENT_INIT;
	//printf("pjs_event_type : %d\n", pjs_event_type);
	switch(pjs_event_type){
	case JS_EVENT_BUTTON:
		
		if(pjs_event->value)
			buttons_state |= (1 << pjs_event->number);
		else
			buttons_state &= ~(1 << pjs_event->number);
		break;
		
	case JS_EVENT_AXIS:	
		if(pjs_event->value != 0){
			//printf("%d, %d\n", pjs_event->number,pjs_event->number + (int)(pjs_event->value>0?2:0));
			axis_state |= (1 << ((pjs_event->value>0?2:0) + pjs_event->number));
			//last_base = (pjs_event->value>0)?2:0;
		}
		else
			axis_state &= ~(1 << ((pjs_event->value>0?2:0) + pjs_event->number));			
		
		break;
		
	default:
		
		break;
		
	}

	printf("buttons : %d, axis : %d\n", buttons_state, axis_state);
	return (combined_state=(axis_state << 16 | buttons_state));
}

/*
void USBjoypad_sig_handler(int signal)
{
	while(read(USBjoypad_fd, &g_JsEvent,
            				  sizeof(struct js_event)) > 0)
            
    USBjoypad_probe_event();
	
}
*/

static uint32_t USBjoypadGet(void)
{	
	uint32_t state;
	
	while(read(USBjoypad_fd, &g_JsEvent, sizeof(struct js_event)) > 0){
		state = USBjoypad_process_event(&g_JsEvent);
		break;
	}
	/* EAGAIN is returned when the queue is empty */
	if (errno != EAGAIN) {
		/* error */
	}

	return state;
}

static int USBjoypadDevInit(void)
{
	int flag;	/* fcntl flag */
	
	/* device open */
	printf("%s, device open\n", DEFAULT_USB_JOYPAD_PATH);
	USBjoypad_fd = open(DEFAULT_USB_JOYPAD_PATH, O_RDONLY);
	if(-1 == USBjoypad_fd)
	{
		printf("%s device not found\n", DEFAULT_USB_JOYPAD_PATH);
		return -1;
	}
	
	/* device set */
	
	//signal(SIGIO, USBjoypad_sig_handler);	/* signal binding */
	//fcntl(USBjoypad_fd, F_SETOWN, getpid());	/* set the pid that will receive SIGIO  */
	//flag = fcntl(USBjoypad_fd, F_GETFL);
	//fcntl(USBjoypad_fd, F_SETFL, flag | FASYNC);

	printf("device init done\n");
	return 0;
}

static int USBjoypadDevExit(void)
{
	close(USBjoypad_fd);
	return 0;
}

#if 1

int
main(int argc, char **argv)
{
	int ret;
	uint32_t state;
	uint16_t buttons;
	uint16_t axis;
	
	uint8_t axis_high;
	uint8_t axis_low;
	
	USBjoypadDevInit();
	if(ret < 0)
		return -1;

	while(1){
	
		state = USBjoypadGet();

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
	
		
	}

	return 0;
}
#endif

#endif