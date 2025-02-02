#ifndef DOUBLE_BOARD_H
#define DOUBLE_BOARD_H

#include <stdint.h>
#include <stdio.h>

void eepromReadBlock(void *dst, const void *src, size_t size);

#endif /* DOUBLE_BOARD_H */