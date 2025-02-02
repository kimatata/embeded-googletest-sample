#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

extern "C" {
#include "../../product/fileManager/fileCtrl.h"
#include "../../product/fileManager/fileManager.h"
}

// ******************************************************************
// Mock class
// ******************************************************************
class MockFileManager {
  public:
    MOCK_METHOD(void, EnQueue, (ST_QUEUE_ELEMENT * el), ());
};

MockFileManager *g_mockFileManager;

void (*FileCtrl_EnQueue)(ST_QUEUE_ELEMENT *el);
void (*FileCtrl_EnQueue_Saved)(ST_QUEUE_ELEMENT *el);
void FileCtrl_EnQueue_Mock(ST_QUEUE_ELEMENT *el) {
    g_mockFileManager->EnQueue(el);
}

// ******************************************************************
// Test class
// ******************************************************************
class TestFileManager : public ::testing::Test {
  protected:
    void SetUp() override {
        g_mockFileManager = new MockFileManager();
        FileCtrl_EnQueue_Saved = FileCtrl_EnQueue;
        FileCtrl_EnQueue = FileCtrl_EnQueue_Mock;
    }

    void TearDown() override {
        FileCtrl_EnQueue = FileCtrl_EnQueue_Saved;
        delete g_mockFileManager;
    }
};

// ******************************************************************
// Test
// ******************************************************************
TEST_F(TestFileManager, WriteLogHeader_EnQueueShouldBeCalledOnce) {
    uint32_t buffer[8];
    buffer[0] = 0x00;
    buffer[1] = 0x11;
    buffer[2] = 0x22;

    EXPECT_CALL(*g_mockFileManager, EnQueue(_)).WillOnce(Invoke([&](ST_QUEUE_ELEMENT *el) {
        EXPECT_EQ(el->id, 2);
        EXPECT_EQ(el->src, buffer);
        EXPECT_EQ(el->size, 32);
        EXPECT_EQ(el->offset, 0);
    }));

    FileManager_WriteLogHeader(&buffer[0], sizeof(buffer), 0);
}

TEST_F(TestFileManager, CreateLogFile_EnQueueShouldBeCalledFourTimes) {
    uint32_t header[8];
    header[0] = 0x00;
    header[1] = 0x11;
    header[2] = 0x22;

    uint32_t payload[32];
    payload[0] = 0x00;
    payload[1] = 0x11;
    payload[2] = 0x22;

    EXPECT_CALL(*g_mockFileManager, EnQueue(_))
        .Times(4)
        .WillOnce(Invoke([&](ST_QUEUE_ELEMENT *el) {
            EXPECT_EQ(el->id, 1);
            EXPECT_EQ(el->size, 0);
            EXPECT_EQ(el->offset, 0);
        }))
        .WillOnce(Invoke([&](ST_QUEUE_ELEMENT *el) {
            EXPECT_EQ(el->id, 2);
            EXPECT_EQ(el->src, header);
            EXPECT_EQ(el->size, 32);
            EXPECT_EQ(el->offset, 0);
        }))
        .WillOnce(Invoke([&](ST_QUEUE_ELEMENT *el) {
            EXPECT_EQ(el->id, 3);
            EXPECT_EQ(el->src, payload);
            EXPECT_EQ(el->size, 128);
            EXPECT_EQ(el->offset, 0);
        }))
        .WillOnce(Invoke([&](ST_QUEUE_ELEMENT *el) {
            EXPECT_EQ(el->id, 4);
            EXPECT_EQ(el->size, 0);
            EXPECT_EQ(el->offset, 0);
        }));

    FileManager_CreateLogFile(&header[0], sizeof(header), &payload[0], sizeof(payload));
}
