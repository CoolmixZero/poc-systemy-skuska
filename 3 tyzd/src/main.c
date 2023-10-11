#include <stdio.h>
#include "rs232.h"
#include <string.h>

#define BUFFER_SIZE 512

void master_main(struct rs232_obj* port);
void slave_main(struct rs232_obj* port);

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

    // master or slave?
    printf("Are you master or slave (m/s)? ");
    char c = (char)getchar();
    // clear buffer
    int tmp;
    while((tmp = getchar()) != '\n' && tmp != EOF);

    // run subroutine
    if (c == 'm')
        master_main(&port);
    else if (c == 'm')
        slave_main(&port);
    else 
        printf("Wrong letter!");

    // close port
    if (!rs232_close(&port)) {
        fprintf(stderr, "Failed to close serial port!\n");
        return 1;
    }

    return 0;
}

void master_main(struct rs232_obj* port){
    // validate 
    if (!port || port->port == INVALID_HANDLE_VALUE) 
        return;

    // wait for CTS
    if (!rs232_wait_for_rts(port)) {
        fprintf(stderr, "master: Failed to wait for CTS signal!\n");
        return;
    }

    // send data to slave
    char buffer[BUFFER_SIZE] = "Hello world from master!";
    if (!rs232_write(port, (uint8_t*)buffer, strlen(buffer))) {
        fprintf(stderr, "Failed to send data to slave!\n");
        return;
    }

    // receive response from slave
    uint32_t bytes;
    if(!rs232_read(port, (uint8_t*)buffer, sizeof(buffer), &bytes)) {
        fprintf(stderr, "Failed to receive data from slave!\n");
        return;
    }

    printf("master: received from slave: %.&s\n", (int)bytes, buffer);
}

void slave_main(struct rs232_obj* port) {
    // validate 
    if (!port || port->port == INVALID_HANDLE_VALUE) 
        return;
    
    // set RTS signal
    if (!rs232_set_rts(port, true)) {
        fprintf(stderr, "slave: Failed to set RTS signal!\n");
        return;
    }

    // receive data from master
    char buffer[BUFFER_SIZE];
    uint32_t bytes;
    if(!rs232_read(port, (uint8_t*)buffer, sizeof(buffer), &bytes)) {
        fprintf(stderr, "Failed to receive data from master!\n");
        return;
    }

    printf("slave: received from master: %.&s\n", (int)bytes, buffer);

    // set response to master
    strcpy(buffer, "I'm slave :(");
    if (!rs232_write(port, (uint8_t*)buffer, strlen(buffer))) {
        fprintf(stderr, "Failed to send data to master!\n");
        return;
    }

    // clear RTS signal
    if (!rs232_set_rts(port, false)) {
        fprintf(stderr, "slave: Failed to set RTS signal!\n");
        return;
    }
}