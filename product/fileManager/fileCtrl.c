#include "fileCtrl.h"

void FileCtrl_EnQueue_Real(ST_QUEUE_ELEMENT *el) {
    // register a queue in the file system of the microcontroller
    // ..
}
void (*FileCtrl_EnQueue)(ST_QUEUE_ELEMENT *el) = FileCtrl_EnQueue_Real;