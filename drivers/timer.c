#include "vapeos/board_config.h"
#include "scheduler/scheduler.h"

/* board_systick_init should configure the SysTick to call systick_hook() every 1ms */
void timer_init(void){ board_systick_init(); }

/* weak hook: board should call this from actual systick ISR */
__attribute__((weak)) void systick_isr_forward(void){
    systick_hook();
}
