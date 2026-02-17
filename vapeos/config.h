/* Global configuration for VapeOS */
#ifndef VAPEOS_CONFIG_H
#define VAPEOS_CONFIG_H

#define VAPEOS_MAX_WATT 80
#define VAPEOS_MIN_WATT 1
#define VAPEOS_MAX_TEMP 300
#define VAPEOS_MIN_TEMP 100

#define SYSTICK_HZ 1000 /* 1ms tick */

#define FW_PRIMARY_ADDR 0x08002000
#define FW_SECONDARY_ADDR 0x08040000
#define FW_MAX_SIZE (96*1024)

#endif
