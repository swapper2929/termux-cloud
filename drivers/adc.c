#include "vapeos/board_config.h"
#include <stdint.h>

uint16_t adc_read_battery(void){ return board_adc_read_battery(); }
uint16_t adc_read_temp(void){ return board_adc_read_temp(); }
uint16_t adc_read_coil(void){ return board_adc_read_coil(); }
