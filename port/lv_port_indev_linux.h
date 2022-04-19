
/**
 * @file lv_port_indev_linux.h
 *
 */

/*Copy this file as "lv_port_indev.h" and set this value to "1" to enable content*/
#if 1

#ifndef LV_PORT_INDEV_LINUX_H
#define LV_PORT_INDEV_LINUX_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl/lvgl.h"

/*********************
 *      DEFINES
 *********************/
#define DEFAULT_USB_JOYPAD_PATH "/dev/input/js0"

#define BIT(x) (1 << x)
#define JOYPAD_KEY_X BIT(0)
#define JOYPAD_KEY_A BIT(1)
#define JOYPAD_KEY_B BIT(2)
#define JOYPAD_KEY_Y BIT(3)
#define JOYPAD_KEY_NL BIT(4)
#define JOYPAD_KEY_NR BIT(5)



#define JOYPAD_KEY_LEFT   BIT(16)
#define JOYPAD_KEY_TOP    BIT(17)

#define JOYPAD_KEY_RIGHT  BIT(18)
#define JOYPAD_KEY_DOWN   BIT(19)


#define JOYPAD_KEY_SELECT BIT(8)
#define JOYPAD_KEY_START  BIT(9)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void lv_port_indev_init(void);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_PORT_INDEV_TEMPL_H*/

#endif /*Disable/Enable content*/
