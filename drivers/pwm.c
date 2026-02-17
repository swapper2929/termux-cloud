#include "vapeos/board_config.h"

void pwm_init(void){ board_pwm_init(); }
void pwm_set_duty(uint16_t duty){ board_pwm_set_duty(duty); }
void pwm_disable(void){ board_pwm_disable(); }
