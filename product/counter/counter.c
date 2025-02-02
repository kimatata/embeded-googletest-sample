#include "counter.h"

void Counter_Init(Counter *counter) {
    counter->value = 0;
    counter->overflowCount = 0;
}

void Counter_Update(Counter *counter) {
    counter->value++;

    // when overflows
    if (counter->value == 0) {
        counter->overflowCount++;
    }
}

void Counter_Reset(Counter *counter) {
    counter->value = 0;
    counter->overflowCount = 0;
}

uint32_t Counter_GetValue(Counter *counter) {
    return counter->value;
}

uint32_t Counter_GetOverflowCount(Counter *counter) {
    return counter->overflowCount;
}

uint32_t Counter_GetElapsedCount(uint32_t startValue, uint32_t currentValue) {
    return currentValue - startValue;
}
