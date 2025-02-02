#include "ledCtrl.h"
#include "led.h"
#include "ledImpl.h"

static ST_LED_INFO ledInfoRecords[LED_INFO_NUM];
static ST_LED_INFO eepromLedInfoRecords[LED_INFO_NUM];

int8_t LedCtrl_GetBrightestBlueLedNo(ST_LED_INFO *pList) {
    // read data from ROM to RAM
    eepromReadBlock((void *)&ledInfoRecords[0], (const void *)eepromLedInfoRecords, LED_INFO_NUM * sizeof(ST_LED_INFO));

    // find brightest blue led
    int8_t ret = LedImpl_GetBrightestBlueLedNo(ledInfoRecords, LED_INFO_NUM);

    return ret;
}

void LedCtrl_TurnOnRedLedsOnly(void) {
    // Turn off all LEDs
    for (uint8_t i = 0; i < LED_INFO_NUM; i++) {
        if (ledInfoRecords[i].isOn == 1) {
            Led_OFF(ledInfoRecords[i].ledNo);
            ledInfoRecords[i].isOn = 0;
        }
    }

    // Turn on red LEDs
    for (uint8_t i = 0; i < LED_INFO_NUM; i++) {
        if (ledInfoRecords[i].color == LED_COLOR_RED) {
            Led_ON(ledInfoRecords[i].ledNo);
            ledInfoRecords[i].isOn = 1;
        }
    }
}

ST_LED_INFO *LedCtrl_GetCurrentLedState(void) {
    return ledInfoRecords;
}
uint8_t LedCtrl_GetLedNum(void) {
    return LED_INFO_NUM;
}
