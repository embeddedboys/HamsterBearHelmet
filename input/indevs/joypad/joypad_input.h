#ifndef __JOYPAD_INPUT_H
#define __JOYPAD_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif
/*********************
 *      DEFINES
 *********************/
#define DEVICE_PC 1

#if DEVICE_HAMSTERBEAR
#define DEFAULT_USB_JOYPAD_PATH "/dev/input/event1"
#elif DEVICE_PC
#define DEFAULT_USB_JOYPAD_PATH "/dev/input/js0"
#endif

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
 
/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
