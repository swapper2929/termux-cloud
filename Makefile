TARGET = vapeos
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m3 -mthumb -std=c99 -O2 -ffreestanding -fno-builtin -Wall -Wextra -I.
LDSCRIPT = startup/linker.ld

SRCS = \
  vapeos/main.c \
  vapeos/utils.c \
  scheduler/scheduler.c \
  drivers/gpio.c drivers/adc.c drivers/pwm.c drivers/uart.c drivers/flash.c drivers/timer.c \
  control/control.c control/pid.c \
  safety/safety.c \
  terminal/terminal.c \
  update/update.c \
  recovery/recovery.c \
  engineering/engineering.c \
  ui/ui.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET).elf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS) startup/startup.o
	$(CC) $(CFLAGS) -T $(LDSCRIPT) $(OBJS) startup/startup.o -o $@

clean:
	rm -f $(OBJS) startup/startup.o $(TARGET).elf
