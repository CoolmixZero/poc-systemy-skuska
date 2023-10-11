#pragma once

#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>
#include <Windows.h>

struct rs232_obj {
  HANDLE port;
  char port_name[16]; // \\.\COM8
  uint32_t baudrate;
};

// Opens a serial port.
//
// Parameters:
//   port: A pointer to the serial port object.
//   port_number: The port number (COM1, COM2, etc.).
//   baudrate: The desired baud rate.
//
// Returns:
//   true on success, false on failure.
bool rs232_open(
  struct rs232_obj* port, 
  uint8_t port_number,
  uint32_t baudrate
);

// Closes a serial port.
//
// Parameters:
//   port: A pointer to the serial port object.
//
// Returns:
//   true on success, false on failure.
bool rs232_close(struct rs232_obj* port);

// Reads data from a serial port.
//
// Parameters:
//   port: A pointer to the serial port object.
//   buffer: A pointer to the buffer where the data will be read.
//   buffer_size: The size of the buffer.
//   bytes_read: A pointer to a variable where the number of bytes read will be stored.
//
// Returns:
//   true on success, false on failure.
bool rs232_read(
  struct rs232_obj* port, 
  uint8_t* buffer,
  uint32_t buffer_size,
  uint32_t* bytes_read
);

// Writes data to a serial port.
//
// Parameters:
//   port: A pointer to the serial port object.
//   buffer: A pointer to the buffer containing the data to be written.
//   buffer_size: The size of the buffer.
//
// Returns:
//   true on success, false on failure.
bool rs232_write(
  struct rs232_obj* port, 
  uint8_t* buffer,
  uint32_t buffer_size
);