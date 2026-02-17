#ifndef PID_H
#define PID_H
void pid_init(void);
int pid_compute(int target, int measured);
#endif
