#ifndef __JOYPAD_INPUT_H
#define __JOYPAD_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif
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

#define JOYPAD_KEY_RIGHT   BIT(16)
#define JOYPAD_KEY_DOWN    BIT(17)

#define JOYPAD_KEY_LEFT  BIT(18)
#define JOYPAD_KEY_TOP   BIT(19)


#define JOYPAD_KEY_SELECT BIT(8)
#define JOYPAD_KEY_START  BIT(9)

#define DEBUG 1

#if DEBUG
#define pr_debug(fmt, ...) printf("%s: "fmt, __func__, ##__VA_ARGS__);
#else
#define pr_debug
#endif

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#ifndef container_of
/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({			\
	const typeof(((type *)0)->member) * __mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })
#endif

#define MULTI_KEY_DETECT(state, key1, key2) (state == (key1 | key2))

/**********************
 *      TYPEDEFS
 **********************/
struct joypad_data {
    int joypad_fd;

    uint16_t buttons_state;
    uint16_t axis_state;
    uint32_t combined_state;

    struct js_event jsevent;
};

struct joypad_operations {
    int (*init)(struct joypad_data *pdev);
    int (*exit)(struct joypad_data *pdev);
    unsigned int (*get_event)(struct joypad_data *pdev);
};


struct joypad_device {
    uint8_t number;
    char *name;
    uint8_t type;
    pthread_t tid;

    struct joypad_data data;
    struct joypad_operations ops;

    struct joypad_device *p_next;
};

struct joypad_key {
    uint8_t num:7;
    uint8_t state:1;
};
/**********************
 * GLOBAL PROTOTYPES
 **********************/
int joypad_input_init(void);
int joypad_input_exit(void);
struct joypad_data joypad_input_get_data(void);

/**********************
 * GLOBAL VALUES
 **********************/
enum {
    JOYPAD_TYPE_USB = 0x00,
};

enum {
    AXIS_AREA_LEFT_DOWN  = 0x00,
    AXIS_AREA_TOP_RIGHT  = 0x01,
    AXIS_AREA_LEFT_TOP   = 0x02,
    AXIS_AREA_DOWN_RIGHT = 0x03,
    AXIS_AREA_SINGLE     = 0x04,
};

enum {
    AXIS_KEY_RIGHT = BIT(0),
    AXIS_KEY_DOWN  = BIT(1),
    AXIS_KEY_LEFT  = BIT(2),
    AXIS_KEY_TOP   = BIT(3),
};

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
