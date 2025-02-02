#ifndef LED_H
#define LED_H

#include "../board/board.h"

void Led_ON(uint8_t ledNo);
void Led_OFF(uint8_t ledNo);
uint8_t Led_IsOn(uint8_t ledNo);

#endif /* LED_H */
