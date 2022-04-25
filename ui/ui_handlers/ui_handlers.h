#ifndef __UI_HANDLERS_H
#define __UI_HANDLERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* ui_handler operations */
struct ui_handler_ops {
    int ( *init )( void );
    int ( *exit )( void );
    void ( *update )( void );
};

struct ui_handler {
    uint32_t id;    /*  */
    char *name;
    
    struct ui_handler_ops ops;
    
    struct ui_handler *p_next;
};

#define DEBUG 1

#if DEBUG
#define pr_debug(fmt, ...) printf("%s: "fmt, __func__, ##__VA_ARGS__);
#else
#define pr_debug
#endif

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define UI_HANDLER_REGISTER(handler) \
    static struct ui_handler handler##_handler = { \
        .name = #handler, \
        .ops = { \
                .init = handler##_init, \
                .exit = handler##_exit, \
                .update = handler##_update, \
        }, \
    }; \
    static void __attribute__((constructor)) handler##_register(void) \
    { \
        register_handler(&handler##_handler); \
    }

int register_handler( struct ui_handler *handler );
void ui_handlers_init( void );
void ui_handlers_exit( void );

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif