#include "rs232.h"
#include <stdio.h>


bool rs232_open(struct rs232_obj *port, uint8_t portNumber, uint32_t baudRate)
{
    if (!port)
        return false;

    port->baudRate = baudRate;
    snprintf(port->portName, sizeof(port->portName), "\\\\.\\COM%d", (int)portNumber);
    port->handle = INVALID_HANDLE_VALUE;

    HANDLE handle = CreateFileA(
        port->portName,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (handle == INVALID_HANDLE_VALUE)
        return false;
    
    // set rs-232 params
    DCB params = { 0 };
    // SecureZeroMemory(&params, sizeof(DCB));
    params.DCBlength = sizeof(DCB);

    if (!GetCommState(handle, &params))
    {
        CloseHandle(handle);
        return false;
    }
    
    params.BaudRate = port->baudRate;
    params.ByteSize = 8;
    params.StopBits = ONESTOPBIT;
    params.Parity = NOPARITY;
    params.fDtrControl = DTR_CONTROL_ENABLE;
    params.fRtsControl = RTS_CONTROL_ENABLE;

    if (!SetCommState(handle, &params))
    {
        CloseHandle(handle);
        return false;
    }

    // set timeouts
    COMMTIMEOUTS timeouts = { 0 };
    timeouts.ReadIntervalTimeout = 0;
    timeouts.ReadTotalTimeoutConstant = 1;
    timeouts.ReadTotalTimeoutMultiplier = 1;
    timeouts.WriteTotalTimeoutConstant = 1;
    timeouts.WriteTotalTimeoutMultiplier = 1;

    if (!SetCommTimeouts(handle, &timeouts))
    {
        CloseHandle(handle);
        return false;
    }
    
    port->handle = handle;
    return true;
}

bool rs232_close(struct rs232_obj *port)
{
    if (!port)
        return false;

    if (port->handle == INVALID_HANDLE_VALUE)
        return false;

    CloseHandle(port->handle);
    port->handle = INVALID_HANDLE_VALUE;
    return true;
}

bool rs232_write(struct rs232_obj *port, uint8_t *buffer, uint32_t bufferLength)
{
    if (!port)
        return false;

    if (port->handle == INVALID_HANDLE_VALUE)
        return false;

    DWORD bytesWritten = 0;
    if (!WriteFile(port->handle, buffer, bufferLength, &bytesWritten, NULL))
        return false;

    return true;
}

bool rs232_read(struct rs232_obj *port, uint8_t *buffer, uint32_t bufferLength, uint32_t *count)
{
    if (!port)
        return false;

    if (port->handle == INVALID_HANDLE_VALUE)
        return false;

    DWORD bytesRead = 0;
    if (!ReadFile(port->handle, buffer, bufferLength, &bytesRead, NULL))
        return false;

    *count = bytesRead;
    return true;
}