#include <gtest/gtest.h>

extern "C" {
#include "../../product/ledCtrl/ledImpl.h"
}

TEST(ledImpl, RetrievesTheLedNoOfTheBrightestBlueLed) {
    ST_LED_INFO ledInfoRecords[5] = {
        {1, 1, 100, LED_COLOR_BLUE}, // {ledNo, isOn, brightness, color}
        {2, 1, 170, LED_COLOR_RED},  // {ledNo, isOn, brightness, color}
        {3, 1, 90, LED_COLOR_BLUE},  // {ledNo, isOn, brightness, color}
        {4, 1, 150, LED_COLOR_BLUE}, // {ledNo, isOn, brightness, color}
        {5, 1, 130, LED_COLOR_BLUE}, // {ledNo, isOn, brightness, color}
    };

    int8_t ret = LedImpl_GetBrightestBlueLedNo(ledInfoRecords, 5);
    EXPECT_EQ(4, ret);
}

TEST(ledImpl, ReturnsMinusIfNoBlueLed) {
    ST_LED_INFO ledInfoRecords[4] = {
        {1, 1, 100, LED_COLOR_RED},   // {ledNo, isOn, brightness, color}
        {2, 1, 170, LED_COLOR_RED},   // {ledNo, isOn, brightness, color}
        {3, 1, 90, LED_COLOR_GREEN},  // {ledNo, isOn, brightness, color}
        {4, 1, 150, LED_COLOR_GREEN}, // {ledNo, isOn, brightness, color}
    };

    int8_t ret = LedImpl_GetBrightestBlueLedNo(ledInfoRecords, 4);
    EXPECT_EQ(-1, ret);
}
