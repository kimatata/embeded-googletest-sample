
#include <gtest/gtest.h>

#include "./testArmCtrl.cpp"
#include "./testCounter.cpp"
#include "./testFileManager.cpp"
#include "./testLedCtrl.cpp"
#include "./testLedImpl.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}