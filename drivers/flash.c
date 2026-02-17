#include "vapeos/board_config.h"
#include <stdint.h>

int flash_erase(uint32_t addr, uint32_t len){
    return board_flash_erase(addr, len);
}

int flash_write(uint32_t addr, const uint8_t *data, uint32_t len){
    return board_flash_write(addr, data, len);
}
