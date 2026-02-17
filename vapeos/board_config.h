/* Board hooks and weak implementations. Adapt for specific MCU. */
#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <stdint.h>

/* LED pin control - must be implemented per board */
void board_led_init(void);
void board_led_set(int on);

/* Button input */
int board_button_pressed(void);

/* Low-level flash primitives - must be implemented for target MCU */
int board_flash_erase(uint32_t addr, uint32_t len);
int board_flash_write(uint32_t addr, const uint8_t *data, uint32_t len);

/* ADC read channels */
uint16_t board_adc_read_battery(void);
uint16_t board_adc_read_temp(void);
uint16_t board_adc_read_coil(void);

/* PWM control for coil */
void board_pwm_init(void);
void board_pwm_set_duty(uint16_t duty); /* 0..1000 */
void board_pwm_disable(void);

/* UART low level */
void board_uart_init(void);
int board_uart_tx(uint8_t c);
int board_uart_rx_nonblocking(void); /* -1 if none, else byte */

/* Timer init for SysTick (millisecond) */
void board_systick_init(void);

/* Default weak stubs (linker will allow overrides) */
__attribute__((weak)) void board_led_init(void) {}
__attribute__((weak)) void board_led_set(int on) {}
__attribute__((weak)) int board_button_pressed(void) { return 0; }
__attribute__((weak)) int board_flash_erase(uint32_t addr, uint32_t len) { return -1; }
__attribute__((weak)) int board_flash_write(uint32_t addr, const uint8_t *data, uint32_t len) { return -1; }
__attribute__((weak)) uint16_t board_adc_read_battery(void) { return 0; }
__attribute__((weak)) uint16_t board_adc_read_temp(void) { return 0; }
__attribute__((weak)) uint16_t board_adc_read_coil(void) { return 0; }
__attribute__((weak)) void board_pwm_init(void) {}
__attribute__((weak)) void board_pwm_set_duty(uint16_t duty) {}
__attribute__((weak)) void board_pwm_disable(void) {}
__attribute__((weak)) void board_uart_init(void) {}
__attribute__((weak)) int board_uart_tx(uint8_t c) { return -1; }
__attribute__((weak)) int board_uart_rx_nonblocking(void) { return -1; }
__attribute__((weak)) void board_systick_init(void) {}

#endif
