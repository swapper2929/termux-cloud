#include "safety/safety.h"
#include "drivers/adc.h"
#include "ui/ui.h"
#include <stdint.h>

static int tripped = 0;

void safety_init(void){ tripped = 0; }

void safety_trip(const char *reason){ tripped = 1; ui_error(reason); }
int safety_is_tripped(void){ return tripped; }

void safety_poll(void){
    if(tripped) return;
    uint16_t bat = adc_read_battery();
    uint16_t temp = adc_read_temp();
    uint16_t coil = adc_read_coil();
    /* simple thresholds, adapt per-board */
    if(bat < 200) safety_trip("LOW_BATTERY");
    if(temp > 1000) safety_trip("OVER_TEMP");
    if(coil < 10) safety_trip("SHORT_CIRCUIT");
}
