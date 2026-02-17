#include "ui/ui.h"
#include "vapeos/board_config.h"
#include "drivers/uart.h"

void ui_init(void){ board_led_init(); }

void ui_status(const char *s){
    /* send via UART for simple status */
    uart_write(s);
}

void ui_error(const char *s){
    /* Blink LED and print message */
    uart_write("ERROR: ");
    uart_write(s);
    uart_write("\n");
    for(volatile int i=0;i<100000;i++);
    board_led_set(1);
    for(volatile int i=0;i<500000;i++);
    board_led_set(0);
}
