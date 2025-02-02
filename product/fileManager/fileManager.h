

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "../board/board.h"

#define OPEN_LOG_FILE 1
#define WRITE_LOG_HEADER 2
#define WRITE_LOG_PAYLOAD 3
#define CLOSE_LOG_FILE 4

typedef struct {
    uint8_t id;
    uint32_t *src;
    uint32_t size;
    uint32_t offset;
} ST_QUEUE_ELEMENT;

int8_t FileManager_CreateLogFile(uint32_t *headerSrc, uint32_t headerSize, uint32_t *payloadSrc, uint32_t payloadSize);
int8_t FileManager_OpenLogFile(void);
int8_t FileManager_WriteLogHeader(uint32_t *src, uint32_t size, uint32_t offset);
int8_t FileManager_WriteLogPayload(uint32_t *src, uint32_t size, uint32_t offset);
int8_t FileManager_CloseLogFile(void);

#endif /* FILE_MANAGER_H */
