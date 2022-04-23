#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ui/ui_handlers/ui_handlers.h"
#include "lvgl/lvgl.h"


struct statusbar_state {
    struct timeval tv;
    struct tm tm_res;

    uint8_t hour;
    uint8_t minute;
    uint8_t second;

    uint8_t wifi;
    uint8_t bt;
    uint8_t battry;
};

extern lv_obj_t * ui_LabelTime;
extern lv_obj_t * ui_LabelTime1;

// extern lv_obj_t * ui_LabelBattery;
// extern lv_obj_t * ui_LabelBattery1;

struct statusbar_state *g_state;
pthread_t tid;

void ui_statusbar_update_thread_function(void *privdata)
{
    char time_buf[10];
    struct statusbar_state *state = (struct statusbar_state *)privdata;

    // state->hour = state->tm_res.tm_hour;
    // state->minute = state->tm_res.tm_min;
    // state->second = state->tm_res.tm_sec;


    while(1){
        
        /* time */
        gettimeofday(&state->tv, NULL);
        localtime_r(&state->tv.tv_sec, &state->tm_res);
        state->minute = state->tm_res.tm_min;

        snprintf(time_buf, sizeof(time_buf), "%02d:%02d", state->tm_res.tm_hour,
                                                                                            state->tm_res.tm_min);

        lv_label_set_text(ui_LabelTime, time_buf);
        lv_label_set_text(ui_LabelTime1, time_buf);

        /* battery */
        

        /* switch */
        
        sleep(60);
    }



}

void ui_statusbar_init(void)
{
    printf("ui_statusbar init.\n");
    g_state = (struct statusbar_state *)malloc(sizeof(struct statusbar_state));

    pthread_create(&tid, NULL, ui_statusbar_update_thread_function, (void *)g_state);
}

void ui_statusbar_exit(void)
{
    free(g_state);
    pthread_cancel(&tid);
}