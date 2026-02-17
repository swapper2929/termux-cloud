#ifndef FLASH_H
#define FLASH_H
#include <stdint.h>
int flash_erase(uint32_t addr, uint32_t len);
int flash_write(uint32_t addr, const uint8_t *data, uint32_t len);
#endif
