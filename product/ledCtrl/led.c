
#include "led.h"

static uint8_t led_value;
static volatile uint8_t *ledResisterAdr;

void Led_ON(uint8_t ledNo) {
    led_value = led_value | (1 << ledNo);
    *ledResisterAdr = led_value;
}

void Led_OFF(uint8_t ledNo) {
    led_value = led_value & ~(1 << ledNo);
    *ledResisterAdr = led_value;
}

uint8_t Led_IsOn(uint8_t ledNo) {
    if (led_value & (1 << ledNo)) {
        return 1; // ON
    } else {
        return 0; // OFF
    }
}
