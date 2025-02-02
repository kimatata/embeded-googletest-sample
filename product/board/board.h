#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>
#include <stdio.h>

void eepromReadBlock(void *dst, const void *src, size_t size);

#endif /* BOARD_H */