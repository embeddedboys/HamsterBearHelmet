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

extern lv_obj_t *ui_LabelTime;
extern lv_obj_t *ui_LabelTime1;
extern lv_obj_t *ui_LabelTime2;

extern lv_obj_t *ui_LabelHint;

struct statusbar_state *g_state;
pthread_t tid_status_bar;

static char *hints[] = {
    [0] = "Good night",
    [1] = "Good morning",
    [2] = "Good afternoon",
    [3] = "Good evening",
};

#define USER_NAME "IotaHydrae"

static void *ui_statusbar_update_thread_function( void *privdata )
{
    char time_buf[10];
    char hint_buf[48];
    struct statusbar_state *state = ( struct statusbar_state * )privdata;
    
    // state->hour = state->tm_res.tm_hour;
    // state->minute = state->tm_res.tm_min;
    // state->second = state->tm_res.tm_sec;
    
    while( 1 ) {
    
        /* time */
        gettimeofday( &state->tv, NULL );
        localtime_r( &state->tv.tv_sec, &state->tm_res );
        state->minute = state->tm_res.tm_min;
        
        snprintf( time_buf, sizeof( time_buf ), "%02d:%02d", state->tm_res.tm_hour,
                  state->tm_res.tm_min );
                  
        lv_label_set_text( ui_LabelTime, time_buf );
        lv_label_set_text( ui_LabelTime1, time_buf );
         lv_label_set_text( ui_LabelTime2, time_buf );
        
        /* battery */
        
        /* switch */

        /* Hint */
        snprintf(hint_buf, sizeof(hint_buf), "%s, %s", hints[state->tm_res.tm_hour / 6], USER_NAME);
        lv_label_set_text( ui_LabelHint, hint_buf );
        
        sleep( 10 );
    }
    
    return NULL;
}

static int ui_statusbar_init( void )
{
    pr_debug( "%s\n", __func__ );
    g_state = ( struct statusbar_state * )malloc( sizeof( struct
                                                          statusbar_state ) );
                                                          
    pthread_create( &tid_status_bar, NULL, ui_statusbar_update_thread_function,
                    ( void * )g_state );
    return 0;
}

static int ui_statusbar_exit( void )
{
    free( g_state );
    pthread_cancel( tid_status_bar );
    
    return 0;
}

static void ui_statusbar_update( void )
{
}

UI_HANDLER_REGISTER( ui_statusbar );