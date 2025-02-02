#include <gtest/gtest.h>

extern "C" {
#include "../../product/counter/counter.h"
}

TEST(Counter, CounterInitialValueIsZero) {
    Counter counter;
    Counter_Init(&counter);
    EXPECT_EQ(Counter_GetValue(&counter), 0);
    EXPECT_EQ(Counter_GetOverflowCount(&counter), 0);
}

TEST(Counter, CounterValueIncrements) {
    Counter counter;
    Counter_Init(&counter);
    Counter_Update(&counter);
    EXPECT_EQ(Counter_GetValue(&counter), 1);
}

TEST(Counter, CounterOverflows) {
    Counter counter;
    Counter_Init(&counter);

    counter.value = UINT32_MAX - 1;
    Counter_Update(&counter);
    EXPECT_EQ(Counter_GetValue(&counter), UINT32_MAX);
    EXPECT_EQ(Counter_GetOverflowCount(&counter), 0);

    // trigger overflow
    Counter_Update(&counter);
    EXPECT_EQ(Counter_GetValue(&counter), 0);
    EXPECT_EQ(Counter_GetOverflowCount(&counter), 1); // overflow count will be 1
}

TEST(Counter, CounterResetsProperly) {
    Counter counter;
    Counter_Init(&counter);

    Counter_Update(&counter);
    counter.value = UINT32_MAX;
    counter.overflowCount = 3;

    Counter_Reset(&counter);
    EXPECT_EQ(Counter_GetValue(&counter), 0);
    EXPECT_EQ(Counter_GetOverflowCount(&counter), 0);
}

TEST(Counter, CanCalculateElapsedTimeCorrectlyEvenWithOverflow) {
    uint32_t startValue = 0xffffffff;
    uint32_t currentValue = 0x9;
    EXPECT_EQ(10, Counter_GetElapsedCount(startValue, currentValue));
}