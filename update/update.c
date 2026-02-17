#include "update/update.h"
#include "drivers/uart.h"
#include "drivers/flash.h"
#include "vapeos/utils.c"
#include <stdint.h>
#include "vapeos/config.h"

/* Simple text-based chunk protocol:
   FW_CHUNK <addr> <hexlen> <hexdata>\n
   FW_DONE <crc>\n
*/

static uint32_t target_crc = 0;
static uint32_t current_crc = 0;

static int hexval(char c){ if(c>='0'&&c<='9') return c-'0'; if(c>='A'&&c<='F') return c-'A'+10; if(c>='a'&&c<='f') return c-'a'+10; return -1; }

void update_enter(void){
    uart_write("ENTER UPDATE MODE\n");
    uart_write("SEND CHUNKS: FW_CHUNK <addr> <hexlen> <hexdata>\n");
    /* For brevity: not implementing full parser here; in production implement robust framing. */
    uart_write("NOT IMPLEMENTED: use bootloader via SWD for safety.\n");
}
