#include "vapeos/config.h"
#include "vapeos/board_config.h"
#include "scheduler/scheduler.h"
#include "drivers/uart.h"
#include "drivers/timer.h"
#include "ui/ui.h"
#include "control/control.h"
#include "safety/safety.h"
#include "terminal/terminal.h"

void SystemInit(void){
    board_systick_init();
}

int main(void){
    board_led_init();
    board_uart_init();
    board_pwm_init();

    ui_init();
    uart_init();
    timer_init();
    scheduler_init();
    control_init();
    safety_init();
    terminal_init();

    ui_status("VapeOS starting\n");

    /* Main cooperative loop */
    while(1){
        scheduler_run();
        terminal_poll();
        safety_poll();
        control_poll();
    }
    return 0;
}
