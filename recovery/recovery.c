#include "recovery/recovery.h"
#include "drivers/uart.h"
#include "drivers/flash.h"
#include "drivers/adc.h"
#include "vapeos/config.h"
#include <stdint.h>

void recovery_enter(void){
    uart_write("RECOVERY MODE\n");
    uart_write("Options:\n");
    uart_write(" - reflash (use update)\n");
    uart_write(" - factory_reset\n");
    uart_write(" - diag\n");
    /* Minimal interactive functionality omitted for safety reasons */
}
