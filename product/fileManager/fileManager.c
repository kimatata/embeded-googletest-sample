#include "fileManager.h"
#include "fileCtrl.h"

int8_t FileManager_CreateLogFile(uint32_t *headerSrc, uint32_t headerSize, uint32_t *payloadSrc, uint32_t payloadSize) {
    // first create file
    ST_QUEUE_ELEMENT openFileEl = {
        OPEN_LOG_FILE, // id
        NULL,          // src
        0,             // size
        0              // offset
    };
    FileCtrl_EnQueue(&openFileEl);

    // then, write header
    ST_QUEUE_ELEMENT writeHeaderEl = {
        WRITE_LOG_HEADER, // id
        headerSrc,        // src
        headerSize,       // size
        0                 // offset
    };
    FileCtrl_EnQueue(&writeHeaderEl);

    // then, write payload
    ST_QUEUE_ELEMENT writePayloadEl = {
        WRITE_LOG_PAYLOAD, // id
        payloadSrc,        // src
        payloadSize,       // size
        0                  // offset
    };
    FileCtrl_EnQueue(&writePayloadEl);

    // finally close file
    ST_QUEUE_ELEMENT closeFileEl = {
        CLOSE_LOG_FILE, // id
        NULL,           // src
        0,              // size
        0               // offset
    };
    FileCtrl_EnQueue(&closeFileEl);

    return 0;
}

int8_t FileManager_OpenLogFile(void) {
    // resister queue to close file
    // ..
}

int8_t FileManager_WriteLogHeader(uint32_t *src, uint32_t size, uint32_t offset) {
    ST_QUEUE_ELEMENT el = {
        WRITE_LOG_HEADER, // id
        src,              // src
        size,             // size
        offset            // offset
    };

    FileCtrl_EnQueue(&el);
    return 0;
}

int8_t FileManager_WriteLogPayload(uint32_t *src, uint32_t size, uint32_t offset) {
    // resister queue to write file payload
    // ..
}

int8_t FileManager_CloseLogFile(void) {
    // resister queue to close file
    // ..
}
