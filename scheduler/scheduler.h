#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

typedef void (*task_fn)(void);

void scheduler_init(void);
void scheduler_run(void);
void scheduler_register_1ms(task_fn t);
void scheduler_register_10ms(task_fn t);

/* tick called from SysTick - weak hook */
void systick_hook(void);

#endif
