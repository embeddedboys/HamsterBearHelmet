#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ui/ui_handlers/ui_handlers.h"
#include "lvgl/lvgl.h"

extern lv_obj_t *ui_ChartSensorValue;
pthread_t tid_chart_sensors;

static void *ui_charts_sensor_update_thread_function( void *privdata )
{
    lv_chart_series_t *ser1 = ( lv_chart_series_t * )privdata;
    
    while( 1 ) {
        lv_chart_set_next_value( ui_ChartSensorValue, ser1, rand() % 10 + 20 );
        lv_chart_refresh( ui_ChartSensorValue ); /*Required after direct set*/
        sleep( 1 );
    }
    
    return NULL;
}

static int ui_charts_init( void )
{
    int ret;
    
    /*Add two data series*/
    pr_debug( "%s\n", __func__ );
    lv_chart_set_range( ui_ChartSensorValue, LV_CHART_AXIS_PRIMARY_Y, 0, 50 );
    lv_chart_set_axis_tick( ui_ChartSensorValue, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 6,
                            2, true, 20 );
                            
    lv_chart_series_t *ser1 = lv_chart_add_series( ui_ChartSensorValue,
                                                   lv_palette_main( LV_PALETTE_RED ), LV_CHART_AXIS_PRIMARY_Y );
    // lv_chart_series_t * ser2 = lv_chart_add_series(ui_ChartSensorValue, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_SECONDARY_Y);
    
    /*Set the next points on 'ser1'*/
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 17 );
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 20 );
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 23 );
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 25 );
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 27 );
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 26 );
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 23 );
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 19 );
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 12 );
    lv_chart_set_next_value( ui_ChartSensorValue, ser1, 11 );
    
    /*Directly set points on 'ser2'*/
    // ser2->y_points[0] = 90;
    // ser2->y_points[1] = 70;
    // ser2->y_points[2] = 65;
    // ser2->y_points[3] = 65;
    // ser2->y_points[4] = 65;
    // ser2->y_points[5] = 65;
    // ser2->y_points[6] = 65;
    // ser2->y_points[7] = 65;
    // ser2->y_points[8] = 65;
    // ser2->y_points[9] = 65;
    
    ret = pthread_create( &tid_chart_sensors, NULL,
                          ui_charts_sensor_update_thread_function, ( void * )ser1 );
                          
    if( ret != 0 ) {
        pr_debug( "%s: pthread_create failed\n", __func__ );
        return -1;
    }
    
    return 0;
}

static int ui_charts_exit( void )
{
    int ret = -1;
    
    ret = pthread_cancel( tid_chart_sensors );
    
    if( ret != 0 ) {
        pr_debug( "%s: pthread_cancel failed\n", __func__ );
        return -1;
    }
    
    return 0;
}

static void ui_charts_update( void )
{
    lv_chart_refresh( ui_ChartSensorValue ); /*Required after direct set*/
}


UI_HANDLER_REGISTER( ui_charts );