#include "scheduler/scheduler.h"
#include <stdint.h>
#include "vapeos/board_config.h"

static volatile uint32_t ms_ticks = 0;
static task_fn task_1ms = 0;
static task_fn task_10ms = 0;
static uint16_t counter_10ms = 0;

void scheduler_init(void){
    ms_ticks = 0;
}

void scheduler_register_1ms(task_fn t){ task_1ms = t; }
void scheduler_register_10ms(task_fn t){ task_10ms = t; }

/* Called from SysTick interrupt in startup.s via weak hook */
void systick_hook(void){
    ms_ticks++;
    if(task_1ms) task_1ms();
    counter_10ms++;
    if(counter_10ms>=10){ counter_10ms=0; if(task_10ms) task_10ms(); }
}

void scheduler_run(void){
    /* cooperative: nothing here for now; tasks run in tick hooks */
}
