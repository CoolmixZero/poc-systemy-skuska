#include "rs232.h"

bool rs232_open(
  struct rs232_obj* port,       // Pointer to the serial port object.
  uint8_t port_number,          // Port number (e.g., COM1, COM2, etc.).
  uint32_t baudrate            // Desired baud rate.
) {
  if (!port)
    return false;

  // save communication parameters
  port->baudrate = baudrate;
  snprintf(port->port_name, sizeof(port->port_name), "\\\\.\\COM%d", (int)port_number);

  port->port = INVALID_HANDLE_VALUE;

  // open serial port
  HANDLE handle = CreateFileA(
    port->port_name,
    GENERIC_READ | GENERIC_WRITE,
    0,
    NULL,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    NULL
  );

  if (handle == INVALID_HANDLE_VALUE) {
    return false;
  }
  
  // load serial port parameters
  DCB dcb;
  SecureZeroMemory(&dcb, sizeof(DCB));
  dcb.DCBlength = sizeof(DCB);

  if (!GetCommState(handle, &dcb)) {
    CloseHandle(handle);
    return false;
  }

  // set serial port params
  dcb.BaudRate = (DWORD)baudrate;
  dcb.Parity = NOPARITY;
  dcb.ByteSize = 8;
  dcb.StopBits = ONESTOPBIT;

  if (!SetCommState(handle, &dcb)) {
    CloseHandle(handle);
    return false;
  }

  // set timeoutss
  COMMTIMEOUTS timeouts = {
    .ReadIntervalTimeout = 0,
    .ReadTotalTimeoutMultiplier = 1,
    .ReadTotalTimeoutConstant = 10,
    .WriteTotalTimeoutMultiplier = 1,
    .WriteTotalTimeoutConstant = 1
  };

  if (!SetCommTimeouts(handle, &timeouts)) {
    CloseHandle(handle);
    return false;
  }

  // success
  port->port = handle;
  return true;

};

bool rs232_close(struct rs232_obj* port) {
  // validate params
  if (!port || port->port == INVALID_HANDLE_VALUE) 
    return false;

  // close serial port
  CloseHandle(port->port);
  port->port = INVALID_HANDLE_VALUE;
  return true;
};

bool rs232_read(
  struct rs232_obj* port, 
  uint8_t* buffer,
  uint32_t buffer_size,
  uint32_t* bytes_read
) {
  // validate params
  if (!port || port->port == INVALID_HANDLE_VALUE) 
    return false;

  // read data
  DWORD bytes;
  if (!ReadFile(
    port->port,
    buffer,
    buffer_size,
    &bytes,
    NULL
  )) {
    return false;
  }

  // success
  *bytes_read = (uint32_t)bytes;
  return true;
};

bool rs232_write(
  struct rs232_obj* port, 
  uint8_t* buffer,
  uint32_t buffer_size
) {
  // validate params
  if (!port || port->port == INVALID_HANDLE_VALUE) 
    return false;

  // write data
  DWORD bytes;
  if (!WriteFile(
    port->port,
    buffer,
    buffer_size,
    &bytes,
    NULL
  )) {
    return false;
  }

  // success 
  return bytes == buffer_size;
};

bool rs232_set_rts(
  struct rs232_obj* port, 
  bool set
) {
  // validate
  if (!port || !set || port->port == INVALID_HANDLE_VALUE) 
    return false;

  return EscapeCommFunction(port->port, set ? SETRTS : CLRRTS);
}

bool rs232_get_rts(
  struct rs232_obj* port, 
  bool* set
) {
  // validate
  if (!port || !set || port->port == INVALID_HANDLE_VALUE) 
    return false;

  DWORD status;
  if (!GetCommModemStatus(port->port, &status))
    return false;

  *set = !!(status & MS_CTS_ON); // (...) != 0

  return true;
}

bool rs232_wait_for_rts(
  struct rs232_obj* port
) {
  // validate
  if (!port || port->port == INVALID_HANDLE_VALUE) 
    return false;

  // set mask
  DWORD mask;
  if (!GetCommMask(port->port, &mask))
    return false;

  mask |= EV_CTS;
  if (!SetCommMask(port->port, mask))
    return false;

  // wait
  mask = 0;
  while(WaitCommEvent(port->port, &mask, NULL) && !!(mask & EV_CTS));

  return !!(mask & EV_CTS);
}