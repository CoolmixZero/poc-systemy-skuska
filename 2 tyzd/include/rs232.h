#pragma once

#include <stdbool.h>
#include <inttypes.h>
#include <Windows.h>

struct rs232_obj
{
    HANDLE handle;
    char portName[32];
    uint32_t baudRate;
};

bool rs232_open(struct rs232_obj *port, uint8_t portNumber, uint32_t baudRate);
bool rs232_close(struct rs232_obj *port);
bool rs232_write(struct rs232_obj *port, uint8_t *buffer, uint32_t bufferLength);
bool rs232_read(struct rs232_obj *port, uint8_t *buffer, uint32_t bufferLength, uint32_t *count);