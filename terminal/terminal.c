#include "terminal/terminal.h"
#include "drivers/uart.h"
#include "control/control.h"
#include "safety/safety.h"
#include "update/update.h"
#include "recovery/recovery.h"
#include "engineering/engineering.h"
#include <stdint.h>

static char linebuf[128];
static unsigned wp=0;

static void handle_line(char *l){
    if(!l[0]) return;
    if(strcmp(l,"help")==0){ uart_write("help status fire lock unlock set_watt <v> set_temp <v> engineering recovery update\n"); return; }
    if(strcmp(l,"status")==0){ uart_write("STATUS: nominal\n"); return; }
    if(strcmp(l,"fire")==0){ control_fire_start(); uart_write("Firing\n"); return; }
    if(strcmp(l,"lock")==0){ uart_write("Locked\n"); return; }
    if(strcmp(l,"unlock")==0){ uart_write("Unlocked\n"); return; }
    if(strncmp(l,"set_watt ",9)==0){ int v = atoi(l+9); control_set_watt(v); uart_write("OK\n"); return; }
    if(strncmp(l,"set_temp ",9)==0){ int v = atoi(l+9); control_set_temp(v); uart_write("OK\n"); return; }
    if(strcmp(l,"engineering")==0){ engineering_enter(); return; }
    if(strcmp(l,"recovery")==0){ recovery_enter(); return; }
    if(strcmp(l,"update")==0){ update_enter(); return; }
    uart_write("unknown cmd\n");
}

void terminal_init(void){ wp=0; }

void terminal_poll(void){
    int c = uart_getc_nb();
    if(c<0) return;
    if(c=='\r') c='\n';
    if(c=='\n'){
        linebuf[wp]=0; wp=0; handle_line(linebuf);
    } else if(c==8 || c==127){ if(wp) wp--; }
    else { if(wp < sizeof(linebuf)-1) linebuf[wp++]= (char)c; }
}
