#ifndef DOUBLE_LED_H
#define DOUBLE_LED_H

#include <stdint.h>
#include <stdio.h>

void Led_ON(uint8_t ledNo);
void Led_OFF(uint8_t ledNo);
uint8_t Led_IsOn(uint8_t ledNo);

#endif /* DOUBLE_LED_H */
