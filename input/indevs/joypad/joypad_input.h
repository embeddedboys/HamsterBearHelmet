#ifndef __JOYPAD_INPUT_H
#define __JOYPAD_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif
/*********************
 *      DEFINES
 *********************/
#if DEVICE_HAMSTERBEAR
#define DEFAULT_USB_JOYPAD_PATH "/dev/input/event1"
#else if DEVICE_PC
#define DEFAULT_USB_JOYPAD_PATH "/dev/input/js0"
#endif
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
 
/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
