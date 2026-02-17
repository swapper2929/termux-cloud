VapeOS - Minimal freestanding firmware for ARM Cortex-M

Build (requires arm-none-eabi toolchain):

  make

Flash via OpenOCD or vendor tools to 0x08000000.

Memory targets (compile-time): 128 KB Flash, 64 KB RAM.

Wiring (generic):
- Coil PWM -> MOSFET gate (via gate driver)
- Coil sense -> ADC channel
- Battery sense -> ADC channel (voltage divider)
- Temp sensor -> ADC channel (NTC)
- Button -> GPIO input
- LED -> GPIO output
- UART TX/RX -> USB-UART

Commands (UART terminal):
- help, status, fire, lock, unlock, set_watt <v>, set_temp <v>, engineering, recovery, update

Safety:
- Over-temperature cutoff
- Low battery cutoff
- Short-circuit detection
- Max puff time (enforced in control)

Note: This repository provides a minimal, portable core. Board-specific functions in `vapeos/board_config.h` must be implemented for your MCU (flash write/erase, UART and GPIO).
# termux-cloud