#include "control/control.h"
#include "control/pid.h"
#include "drivers/pwm.h"
#include "drivers/adc.h"
#include "safety/safety.h"
#include <stdint.h>

static uint16_t target_watt = 20;
static uint16_t target_temp = 200;
static int firing = 0;

void control_init(void){ pwm_init(); pid_init(); }

void control_set_watt(uint16_t w){ if(w < VAPEOS_MIN_WATT) w = VAPEOS_MIN_WATT; if(w>VAPEOS_MAX_WATT) w=VAPEOS_MAX_WATT; target_watt = w; }
void control_set_temp(uint16_t t){ if(t < VAPEOS_MIN_TEMP) t=VAPEOS_MIN_TEMP; if(t>VAPEOS_MAX_TEMP) t=VAPEOS_MAX_TEMP; target_temp = t; }
uint16_t control_get_watt(void){ return target_watt; }

void control_fire_start(void){ firing = 1; }
void control_fire_stop(void){ firing = 0; pwm_disable(); }

void control_poll(void){
    if(!firing) return;
    if(safety_is_tripped()) { control_fire_stop(); return; }
    /* read coil temperature proxy */
    uint16_t temp_adc = adc_read_temp();
    uint16_t coil = adc_read_coil();
    /* compute duty from PID (temperature mode) */
    int duty = pid_compute(target_temp, temp_adc);
    if(duty < 0) duty = 0; if(duty>1000) duty=1000;
    pwm_set_duty((uint16_t)duty);
}
