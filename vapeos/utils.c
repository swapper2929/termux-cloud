#include <stdint.h>

/* Minimal freestanding implementations of small libc routines used across firmware */
void *memcpy(void *dst, const void *src, unsigned long n){
    unsigned char *d = (unsigned char*)dst;
    const unsigned char *s = (const unsigned char*)src;
    while(n--) *d++ = *s++;
    return dst;
}

void *memset(void *s, int c, unsigned long n){
    unsigned char *p = (unsigned char*)s;
    while(n--) *p++ = (unsigned char)c;
    return s;
}

int memcmp(const void *a, const void *b, unsigned long n){
    const unsigned char *x = a, *y = b;
    while(n--){ if(*x != *y) return *x - *y; x++; y++; }
    return 0;
}

unsigned long strlen(const char *s){
    unsigned long n=0; while(*s++) n++; return n;
}

int strcmp(const char *a, const char *b){
    while(*a && (*a==*b)){ a++; b++; }
    return *(const unsigned char*)a - *(const unsigned char*)b;
}

int strncmp(const char *a, const char *b, unsigned long n){
    while(n--){ if(*a!=*b) return *(unsigned char*)a - *(unsigned char*)b; if(*a==0) break; a++; b++; }
    return 0;
}

int atoi(const char *s){
    int sign=1; int v=0; if(*s=='-'){ sign=-1; s++; }
    while(*s>='0' && *s<='9'){ v = v*10 + (*s - '0'); s++; }
    return v*sign;
}

/* Simple CRC32 (IEEE) */
uint32_t crc32_update(uint32_t crc, const uint8_t *data, unsigned long len){
    crc = ~crc;
    while(len--){
        uint32_t byte = *data++;
        crc ^= byte;
        for(int i=0;i<8;i++){
            uint32_t mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
    }
    return ~crc;
}
