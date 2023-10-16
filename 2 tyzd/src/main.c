#include <stdio.h>
#include "rs232.h"
#include <string.h>

int main()
{
    // select serial port
    int port_no;
    printf("Select serial port: COM");
    if (scanf("%d", &port_no) != 1) {
        fprintf(stderr, "Not a number!\n");
        return 1;
    }
    if (port_no < 0 || port_no > 255) {
        fprintf(stderr, "invalid port number!\n");
        return 1;
    }

    // open serial port
    struct rs232_obj port;
    if (!rs232_open(&port, (uint8_t)port_no, 115200)) {
        fprintf(stderr, "Failed to open serial port! (busy / not existing)\n");
        return 1;
    }

    // write data
    char* message = "Hello world!\r\n";
    if (!rs232_write(&port, (uint8_t*)message, strlen(message))) {
        fprintf(stderr, "Failed to write data to port!\n");
    }

    // read data
    char buffer[256];
    uint32_t bytes;
    if(!rs232_read(&port, (uint8_t*)buffer, sizeof(buffer), &bytes)) {
        fprintf(stderr, "Failed to read data from serial port!\n");
    }

    // close port
    if (!rs232_close(&port)) {
        fprintf(stderr, "Failed to close serial port!\n");
        return 1;
    }

    return 0;
}


// int main()
// {
//     struct rs232_obj port = { 0 };
//     if (!rs232_open(&port, 3, 115200))
//     {
//         printf("rs232_open failed\n");
//         return 1;
//     }

//     uint8_t buffer[256] = { 0 };
//     uint32_t count = 0;
//     if (!rs232_read(&port, buffer, sizeof(buffer), &count))
//     {
//         printf("rs232_read failed\n");
//         return 1;
//     }

//     printf("read %d bytes\n", count);

//     if (!rs232_close(&port))
//     {
//         printf("rs232_close failed\n");
//         return 1;
//     }
    
//     return 0;
// }