#include <gtest/gtest.h>

extern "C" {
#include "../../product/ledCtrl/ledCtrl.h"
}

TEST(LedCtrl, RetrievesTheLedNoOfTheBrightestBlueLed) {
    LedCtrl_TurnOnRedLedsOnly();

    // check led state
    uint8_t ledNum = LedCtrl_GetLedNum();
    ST_LED_INFO *array = LedCtrl_GetCurrentLedState();
    for (uint8_t i = 0; i < ledNum; i++) {
        if (array[i].color == LED_COLOR_RED) {
            EXPECT_EQ(array[i].isOn, 1);
        } else {
            EXPECT_EQ(array[i].isOn, 0);
        }
    }
}
