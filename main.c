#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include <linux/input.h>

#include "lvgl/lvgl.h"
#include "port/lv_port_disp_linux.h"
#include "port/lv_port_indev_linux.h"

#include "ui/ui.h"
/*
    Linux frame buffer like /dev/fb0
    which includes Single-board computers too like Raspberry Pi
*/

/*******************
*       DEFINE
********************/

/* error handler */
#define handle_error(msg) do {perror(msg);exit(-1);} \
    while(0)


#define DEFAULT_LINUX_TOUCHPAD_PATH "/dev/input/event1"

/*
* Input system read mode.
* 0     query
* 1     sleep
* 2     poll
* 3     async
*/
#define INPUT_READ_MODE 3

#ifndef INPUT_READ_MODE
#define INPUT_READ_MODE 1
#endif

/* Sleep mode Do nothing */
#if (INPUT_READ_MODE == 2)
#include <poll.h>
#define INPUT_SAMEPLING_TIME 1
#define SYSTEM_RESPONSE_TIME 4

/*
*  SIGNAL defines in "include\uapi\asm-generic\signal.h"
*/
#elif (INPUT_READ_MODE == 3)
#include <signal.h>
#endif

#define LV_HOR_RES_MAX 280
#define LV_VER_RES_MAX 240
#define DISP_BUF_SIZE ((LV_HOR_RES_MAX * LV_VER_RES_MAX) / 10)   /* LVGL DISP_BUF_SIZE */
//#define DISP_BUF_SIZE LV_HOR_RES_MAX * LV_VER_RES_MAX   /* LVGL DISP_BUF_SIZE */

#ifndef SYSTEM_RESPONSE_TIME
#define SYSTEM_RESPONSE_TIME 5  /* Default to 5 milliseconds to keep the system responsive */
#endif



/*******************
*     TYPEDEF
********************/



/* Input device */
typedef struct
{
    /*  */
    int tp_fd;

#ifndef DEFAULT_LINUX_TOUCHPAD_PATH
    char *event;
#endif

    /* Data of touch panel */
    bool touchdown;
    unsigned short last_x;  /* Abs_mt_x */
    unsigned short last_y;  /* Abs_mt_y */

#if (INPUT_READ_MODE == 0)
    /* query mode */

#elif (INPUT_READ_MODE == 2)
#define DEVICE_NUM 1
    /* poll mode */
    nfds_t nfds;
    struct pollfd mpollfd[DEVICE_NUM];


#elif (INPUT_READ_MODE == 3)
    /* signal mode */

#endif

    struct input_event indev_event;
} indev_struct;


/*******************
*       GLOBAL
********************/
static fbdev_struct fbdev_info;  /* framebuffer */
struct fb_fix_screeninfo finfo;

static screen_struct screen_info;    /* scree */
static indev_struct indev_info;  /* touchpad data */
#if (INPUT_READ_MODE==3)
int flags;
#endif


/*******************
*     PROTOTYPE
********************/
void my_fb_init(void);
void my_touchpad_init(void);

#if (INPUT_READ_MODE==0 || INPUT_READ_MODE == 1)
void my_toupad_default_handler(lv_task_t *task);
#endif /* my_toupad_default_handler */

#if (INPUT_READ_MODE==2)
void my_touchpad_poll_handler(lv_task_t *task);
#endif

#if (INPUT_READ_MODE==3)
void my_touchpad_sig_handler(int signal);
#endif

void my_touchpad_probe_event(void);
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
bool my_touchpad_read(lv_indev_drv_t *indev, lv_indev_data_t *data);


/**
 * Get the screen info.
 * mmap the framebuffer to memory.
 * clear the screen.
 * @param
 * @return
 */
void my_fb_init(void)
{
    fbdev_info.fd_fb = open(DEFAULT_LINUX_FB_PATH, O_RDWR);
    if(fbdev_info.fd_fb < 0)
    {
        handle_error("can not open framebuffer");
    }
    printf("Successfully opened framebuffer.\n");
    /* already get fd_fb */
    if(ioctl(fbdev_info.fd_fb, FBIOGET_VSCREENINFO, &fbdev_info.fb_var) < 0)
    {
        handle_error("can not ioctl");
    }
	if (ioctl(fbdev_info.fd_fb,FBIOGET_FSCREENINFO, &finfo))
	 {
		  handle_error("Error reading fixed information/n");
	 }
    /* already get the var screen info */
    screen_info.width = fbdev_info.fb_var.xres;
    screen_info.height = fbdev_info.fb_var.yres;
    screen_info.bpp = fbdev_info.fb_var.bits_per_pixel;
    screen_info.line_width = fbdev_info.fb_var.xres * fbdev_info.fb_var.bits_per_pixel / 8;
    screen_info.pixel_width = fbdev_info.fb_var.bits_per_pixel / 8;
    screen_info.screen_size = fbdev_info.fb_var.xres * fbdev_info.fb_var.yres * fbdev_info.fb_var.bits_per_pixel / 8;

    printf("screen info:\n Resolution:\t%dx%d\n Bits per pixel:\t%d\n",
           screen_info.width,screen_info.height,screen_info.bpp);
	printf("frame buffer size:%d\n", finfo.smem_len);
	
    /* mmap the fb_base */
    fbdev_info.fb_base = (unsigned char *)mmap(NULL, screen_info.screen_size, PROT_READ | PROT_WRITE, MAP_SHARED, fbdev_info.fd_fb, 0);
    if(fbdev_info.fb_base == (unsigned char *) -1)
    {
        handle_error("can not mmap frame buffer");
    }
    /* alreay get the start addr of framebuffer */
    printf("Successfully get the start address of framebuffer.\n");
    memset(fbdev_info.fb_base, 0x0, screen_info.screen_size); /* clear the screen */
    printf("Successfully clear the screen.\n");
}

/**
 * Just initialize the touchpad
 * @param
 * @return
 */
void my_touchpad_init(void)
{
#if INPUT_READ_MODE == 0
    indev_info.tp_fd = open(DEFAULT_LINUX_TOUCHPAD_PATH, O_RDWR | O_NDELAY | O_NONBLOCK); /* Query mode */
    printf("Successfully open device in nonblock mode.\n");

#else
    indev_info.tp_fd = open(DEFAULT_LINUX_TOUCHPAD_PATH, O_RDWR);  /* Other mode */
    printf("Successfully open device in normal mode.\n");

#endif


    if(indev_info.tp_fd < 0)    /* Returns -1 on error */
    {
        handle_error("can not open indev");
    }

#if (INPUT_READ_MODE == 2)  /* poll mode */
    indev_info.nfds = 1;
    indev_info.mpollfd[0].fd = indev_info.tp_fd;
    indev_info.mpollfd[0].events = POLLIN;
    indev_info.mpollfd[0].revents = 0;
    printf("Successfully run in poll mode.\n");
#elif (INPUT_READ_MODE == 3)
    signal(SIGIO, my_touchpad_sig_handler);
    fcntl(indev_info.tp_fd, F_SETOWN, getpid());
    flags = fcntl(indev_info.tp_fd, F_GETFL);
    fcntl(indev_info.tp_fd, F_SETFL, flags | FASYNC | O_NONBLOCK);
    printf("Successfully run in async mode.\n");

#endif

}

#if (INPUT_READ_MODE==0 || INPUT_READ_MODE == 1)
void my_toupad_default_handler(lv_task_t *task)
{
#if (INPUT_READ_MODE == 0 )
    while(read(indev_info.tp_fd, &indev_info.indev_event,
               sizeof(struct input_event)) > 0)
#else
	if(read(indev_info.tp_fd, &indev_info.indev_event,
				   sizeof(struct input_event)) > 0)
#endif			

    {
        my_touchpad_probe_event();
    }
}
#endif /* my_toupad_default_handler */

#if (INPUT_READ_MODE==3)
/**
 * async signal handler
 * @param
 * @return
 */
void my_touchpad_sig_handler(int signal)
{
    while(read(indev_info.tp_fd, &indev_info.indev_event,
            sizeof(struct input_event)) > 0)
        my_touchpad_probe_event();
}
#endif  /* my_touchpad_sig_handler */


#if (INPUT_READ_MODE==2)
/**
 * A thread to collect input data of screen.
 * @param
 * @return
 */
void my_touchpad_poll_handler(lv_task_t *task)
{
    (void)task;
    int len;
    len = poll(indev_info.mpollfd, indev_info.nfds, INPUT_SAMEPLING_TIME);
    if(len > 0)         /* There is data to read */
    {
        if(read(indev_info.tp_fd, &indev_info.indev_event,
                sizeof(indev_info.indev_event)) > 0)
        {
            my_touchpad_probe_event();
        }

    }
    else if(len == 0)     /* Time out */
    {
        /* Do nothing */
    }
    else     /* Error */
    {
        handle_error("poll error!");
    }
touchdown_err:      /* Do nothing. Just return and ready for next event come. */
    return;
}
#endif


void my_touchpad_probe_event(void)
{

    switch(indev_info.indev_event.type)
    {
        case EV_KEY:    /* Key event. Provide the pressure data of touchscreen*/
            if(indev_info.indev_event.code == BTN_TOUCH)          /* Screen touch event */
            {
                if(1 == indev_info.indev_event.value)         /* Touch down */
                {
                    indev_info.touchdown = true;
                }
                else if(0 == indev_info.indev_event.value)     /* Touch up */
                {
                    indev_info.touchdown = false;
                }
                else                            /* Unexcepted data */
                {
                    goto touchdown_err;
                }
            }
            break;
        case EV_ABS:    /* Abs event. Provide the position data of touchscreen*/
            if(indev_info.indev_event.code == ABS_MT_POSITION_X)
            {
                indev_info.last_x = indev_info.indev_event.value;
            }
            if(indev_info.indev_event.code == ABS_MT_POSITION_Y)
            {
                indev_info.last_y = indev_info.indev_event.value;
            }
            break;
        default:
            break;
    }
touchdown_err:      /* Do nothing. Just return and ready for next event come. */
    return;

}


/**
 * releated to disp_drv.flush_cb
 * @param disp
 * @param area
 * @param color_p
 * @return
 */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    int32_t x, y;
    for(y = area->y1; y <= area->y2; y++)
    {
        for(x = area->x1; x <= area->x2; x++)
        {
            memcpy(fbdev_info.fb_base + x * screen_info.pixel_width + y * screen_info.line_width,
                   &color_p->full, sizeof(lv_color_t));
            color_p++;
        }
    }
	
	/*if (ioctl(fbdev_info.fd_fb, FBIOPAN_DISPLAY, &fbdev_info.fb_var) < 0) {
		fprintf(stderr, "active fb swap failed\n");
	}*/
    lv_disp_flush_ready(disp);
}

/**
 * releated to indev_drv.readcb
 * @param indev
 * @param data
 * @return false
 */
bool my_touchpad_read(lv_indev_drv_t *indev, lv_indev_data_t *data)
{
    /* store the collected data */
    data->state = indev_info.touchdown ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
    if(data->state == LV_INDEV_STATE_PR)
    {
        data->point.x = indev_info.last_x;
        data->point.y = indev_info.last_y;
    }
    return false;
}

/* main thread of lvgl */
int main(void)
{
    lv_init();
	lv_port_disp_init();

/*    
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);
#if (INPUT_READ_MODE==2)
    lv_task_create(my_touchpad_poll_handler, 1, LV_TASK_PRIO_HIGH, NULL);
#elif (INPUT_READ_MODE==0 || INPUT_READ_MODE==1)
    lv_task_create(my_toupad_default_handler, 1, LV_TASK_PRIO_HIGHEST, NULL);
#endif
*/
    /* App here */
    ui_init();
    
    while(1)
    {
        lv_task_handler();
        usleep(SYSTEM_RESPONSE_TIME * 1000);
        lv_tick_inc(SYSTEM_RESPONSE_TIME);
    }
    return 0;
}

