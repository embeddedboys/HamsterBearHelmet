/**
 * @file lv_port_disp_linux.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_disp_linux.h"
#include "../../lvgl.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
 /* Framebuffer info */
typedef struct
{
    int fd_fb;
    unsigned char *fb_base;

    struct fb_var_screeninfo fb_var;
} fbdev_struct;

/* Lcd info */
typedef struct
{
    int width;
    int height;
    int screen_size;
    int line_width;
    int bpp;
    int pixel_width;
} screen_struct;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);

static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p);
//static void gpu_fill(lv_disp_drv_t * disp_drv, lv_color_t * dest_buf, lv_coord_t dest_width,
//        const lv_area_t * fill_area, lv_color_t color);

/**********************
 *  STATIC VARIABLES
 **********************/
static fbdev_struct fbdev_info;  /* framebuffer */
struct fb_fix_screeninfo finfo;

static screen_struct screen_info;    /* scree */

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*-----------------------------
     * Create a buffer for drawing
     *----------------------------*/

    /**
     * LVGL requires a buffer where it internally draws the widgets.
     * Later this buffer will passed to your display driver's `flush_cb` to copy its content to your display.
     * The buffer has to be greater than 1 display row
     *
     * There are 3 buffering configurations:
     * 1. Create ONE buffer:
     *      LVGL will draw the display's content here and writes it to your display
     *
     * 2. Create TWO buffer:
     *      LVGL will draw the display's content to a buffer and writes it your display.
     *      You should use DMA to write the buffer's content to the display.
     *      It will enable LVGL to draw the next part of the screen to the other buffer while
     *      the data is being sent form the first buffer. It makes rendering and flushing parallel.
     *
     * 3. Double buffering
     *      Set 2 screens sized buffers and set disp_drv.full_refresh = 1.
     *      This way LVGL will always provide the whole rendered screen in `flush_cb`
     *      and you only need to change the frame buffer's address.
     */

    /* Example for 1) */
    //static lv_disp_draw_buf_t draw_buf_dsc_1;
    //static lv_color_t buf_1[MY_DISP_HOR_RES * 10];                          /*A buffer for 10 rows*/
    //lv_disp_draw_buf_init(&draw_buf_dsc_1, buf_1, NULL, MY_DISP_HOR_RES * 10);   /*Initialize the display buffer*/

    /* Example for 2) */
    static lv_disp_draw_buf_t draw_buf_dsc_2;
    static lv_color_t buf_2_1[MY_DISP_HOR_RES * 10];                        /*A buffer for 10 rows*/
    static lv_color_t buf_2_2[MY_DISP_HOR_RES * 10];                        /*An other buffer for 10 rows*/
    lv_disp_draw_buf_init(&draw_buf_dsc_2, buf_2_1, buf_2_2, MY_DISP_HOR_RES * 10);   /*Initialize the display buffer*/

    /* Example for 3) also set disp_drv.full_refresh = 1 below*/
    //static lv_disp_draw_buf_t draw_buf_dsc_3;
    //static lv_color_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*A screen sized buffer*/
    //static lv_color_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*Another screen sized buffer*/
    //lv_disp_draw_buf_init(&draw_buf_dsc_3, buf_3_1, buf_3_2,
    //                      MY_DISP_VER_RES * LV_VER_RES_MAX);   /*Initialize the display buffer*/

    /*-----------------------------------
     * Register the display in LVGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = 280;
    disp_drv.ver_res = 240;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.draw_buf = &draw_buf_dsc_1;

    /*Required for Example 3)*/
    //disp_drv.full_refresh = 1

    /* Fill a memory array with a color if you have GPU.
     * Note that, in lv_conf.h you can enable GPUs that has built-in support in LVGL.
     * But if you have a different GPU you can use with this callback.*/
    //disp_drv.gpu_fill_cb = gpu_fill;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
    /*You code here*/
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

/*Flush the content of the internal buffer the specific area on the display
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_disp_flush_ready()' has to be called when finished.*/
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

    int32_t x;
    int32_t y;
    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            /*Put a pixel to the display. For example:*/
            /*put_px(x, y, *color_p)*/
			memcpy(fbdev_info.fb_base + x * screen_info.pixel_width + y * screen_info.line_width,
                   &color_p->full, sizeof(lv_color_t));
            color_p++;
        }
    }

    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);
}

/*OPTIONAL: GPU INTERFACE*/

/*If your MCU has hardware accelerator (GPU) then you can use it to fill a memory with a color*/
//static void gpu_fill(lv_disp_drv_t * disp_drv, lv_color_t * dest_buf, lv_coord_t dest_width,
//                    const lv_area_t * fill_area, lv_color_t color)
//{
//    /*It's an example code which should be done by your GPU*/
//    int32_t x, y;
//    dest_buf += dest_width * fill_area->y1; /*Go to the first line*/
//
//    for(y = fill_area->y1; y <= fill_area->y2; y++) {
//        for(x = fill_area->x1; x <= fill_area->x2; x++) {
//            dest_buf[x] = color;
//        }
//        dest_buf+=dest_width;    /*Go to the next line*/
//    }
//}


#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
