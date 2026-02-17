#ifndef UART_H
#define UART_H
#include <stdint.h>
void uart_init(void);
void uart_putc(char c);
int uart_getc_nb(void);
void uart_write(const char *s);
#endif
