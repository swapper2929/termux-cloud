#include "vapeos/board_config.h"
#include <stdint.h>
#include "drivers/uart.h"

static uint8_t rxbuf[128];
static unsigned rxwp=0, rxrp=0;

void uart_init(void){ board_uart_init(); }

void uart_putc(char c){
    board_uart_tx((uint8_t)c);
}

int uart_getc_nb(void){
    int b = board_uart_rx_nonblocking();
    if(b<0) return -1;
    return b;
}

void uart_write(const char *s){
    while(*s) board_uart_tx((uint8_t)*s++);
}
