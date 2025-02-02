#ifndef LED_DATA_H
#define LED_DATA_H

#include "../board/board.h"

#define LED_INFO_NUM 10
#define LED_COLOR_RED 0
#define LED_COLOR_GREEN 1
#define LED_COLOR_BLUE 2

typedef struct {
    uint8_t ledNo;
    uint8_t isOn;       // 0: OFF, 1: ON
    uint8_t brightness; // 0 (dark) - 255 (bright)
    uint8_t color;      // red, green, blue
} ST_LED_INFO;

int8_t LedCtrl_GetBrightestBlueLedNo(ST_LED_INFO *pList);
void LedCtrl_TurnOnRedLedsOnly(void);
ST_LED_INFO *LedCtrl_GetCurrentLedState(void);
uint8_t LedCtrl_GetLedNum(void);

#endif /* LED_DATA_H */
