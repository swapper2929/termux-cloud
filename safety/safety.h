#ifndef SAFETY_H
#define SAFETY_H
#include <stdint.h>
void safety_init(void);
void safety_poll(void);
int safety_is_tripped(void);
void safety_trip(const char *reason);
#endif
