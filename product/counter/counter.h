#ifndef COUNTER_H
#define COUNTER_H

#include "../board/board.h"

typedef struct {
    uint32_t value;
    uint32_t overflowCount;
} Counter;

void Counter_Init(Counter *counter);
void Counter_Update(Counter *counter);
uint32_t Counter_GetValue(Counter *counter);
uint32_t Counter_GetOverflowCount(Counter *counter);
void Counter_Reset(Counter *counter);
uint32_t Counter_GetElapsedCount(uint32_t startValue, uint32_t currentValue);

#endif // COUNTER_H
