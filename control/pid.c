#include "control/pid.h"
#include <stdint.h>

static int kp=5, ki=1, kd=1;
static int integ=0, last_err=0;

void pid_init(void){ integ=0; last_err=0; }

int pid_compute(int target, int measured){
    int err = (int)target - (int)measured;
    integ += err;
    int deriv = err - last_err;
    last_err = err;
    int out = kp*err + ki*integ + kd*deriv;
    /* map to 0..1000 */
    if(out < 0) out = 0;
    if(out > 1000) out = 1000;
    return out;
}
