#include "engineering/engineering.h"
#include "drivers/uart.h"
#include "drivers/adc.h"
#include "drivers/pwm.h"
#include <stdio.h>

void engineering_enter(void){
    uart_write("ENGINEERING MODE\n");
    uart_write("ADC BATTERY: ");
    /* print numeric value without printf */
    char buf[32];
    int v = adc_read_battery();
    int n = 0; if(v==0) buf[n++]='0'; else { int t=v, p=0; char tmp[16]; while(t){ tmp[p++]= '0' + (t%10); t/=10; } while(p--) buf[n++]=tmp[p]; }
    buf[n]=0; uart_write(buf); uart_write("\n");
}
