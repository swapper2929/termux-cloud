#ifndef CONTROL_H
#define CONTROL_H
#include <stdint.h>
void control_init(void);
void control_poll(void);
void control_fire_start(void);
void control_fire_stop(void);
void control_set_watt(uint16_t w);
void control_set_temp(uint16_t t);
uint16_t control_get_watt(void);
#endif
