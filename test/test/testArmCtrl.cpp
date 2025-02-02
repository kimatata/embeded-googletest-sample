#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

extern "C" {
#include "../../product/armCtrl/armCtrl.h"
}

class MockArmCtrl {
  public:
    MOCK_METHOD(void, mockRotate, (int angle), ());
    MOCK_METHOD(void, mockGrab, (), ());
};

MockArmCtrl *g_mockArmCtrl = nullptr;

void rotate(int angle) {
    g_mockArmCtrl->mockRotate(angle);
}

void grab() {
    g_mockArmCtrl->mockGrab();
}

TEST(ArmControllerTest, armWillRotateThenCatchObject) {
    MockArmCtrl mockArmCtrl;
    g_mockArmCtrl = &mockArmCtrl;

    // Expect rotate(), grab() will be called in catchObject()
    EXPECT_CALL(mockArmCtrl, mockRotate(90)).Times(1);
    EXPECT_CALL(mockArmCtrl, mockGrab()).Times(1);
    ArmCtrl_CatchObject();
}
