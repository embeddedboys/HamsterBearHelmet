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
#include <pthread.h>

#include "ui_handlers.h"

static struct ui_handler *g_pt_ui_handler = NULL;
static uint32_t g_handler_id = 0;

/* called by each handler like statusbar,chart ... */
int register_handler(struct ui_handler *handler)
{
    struct ui_handler *p_tmp;

    if (!handler)
        return -EINVAL;

    printf("register handler: %s\n", handler->name);

    if(!g_pt_ui_handler) {
        pr_debug("first handler\n");
        g_pt_ui_handler = handler;  /* first node */
    } else {
        p_tmp = g_pt_ui_handler;
        while(p_tmp->p_next) {
            p_tmp = p_tmp->p_next;
        }
        p_tmp->p_next = handler;
    }
    handler->id = g_handler_id++;
    handler->p_next = NULL;

    return 0;
}

void ui_handlers_init(void)
{
    struct ui_handler *p_tmp = g_pt_ui_handler;

    if(!p_tmp) {
        pr_debug("no handler\n");
        return;
    }

    if(!p_tmp->p_next && p_tmp->ops.init) {
        pr_debug("only one handler, calling it's init func\n");
        p_tmp->ops.init();
        return;
    }

    pr_debug("more than one handler, calling all init func\n");
    while(p_tmp) {
        pr_debug("init handler %s, id: %d\n", p_tmp->name, p_tmp->id);
        if(p_tmp->ops.init && p_tmp->ops.init()) {
            pr_debug("init handler %s failed\n", p_tmp->name);
            return;
        }
        p_tmp = p_tmp->p_next;
    }
}

void ui_handlers_exit(void)
{
    struct ui_handler *p_tmp = g_pt_ui_handler;

    if(!p_tmp) {
        pr_debug("no handler\n");
        return;
    }

    if(!p_tmp->p_next && p_tmp->ops.exit) {
        pr_debug("only one handler, calling it's exit func\n");
        p_tmp->ops.exit();
        return;
    }

    pr_debug("more than one handler, calling all exit func\n");
    while(p_tmp) {
        pr_debug("exit handler %s, id: %d\n", p_tmp->name, p_tmp->id);
        if(p_tmp->ops.exit && p_tmp->ops.exit()) {
            pr_debug("exit handler %s failed\n", p_tmp->name);
            return;
        }
        p_tmp = p_tmp->p_next;
    }
}
