#ifndef __TYPES_H
#define __TYPES_H

#include <stdint.h>

typedef uint32_t COLOR_T;
typedef uint8_t COLOR_COMPONENT_T;

typedef struct block_t {
    char* (*func)(const void* arg);
    const void* arg;
} block_t;

#endif /* ifndef __TYPES_H */
