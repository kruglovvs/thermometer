#ifndef DEF_WIN
	#define DEF_WIN
	#include <windows.h>
#endif
#ifndef DEF_STDIO
	#define DEF_STDIO
	#include <stdio.h>
#endif
#ifndef DEF_PORT
	#define DEF_PORT
	#include "port.h"
#endif

void main(void) {
	port_type port;
	port.file = CreateFile("\\\\.\\COM3", GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    port.in_buffer[0] = 0;
	port.out_buffer[0] = 0;
    port.receive = 0;
   
	COMMTIMEOUTS CommTimeOuts;
	CommTimeOuts.ReadIntervalTimeout = 5;
	CommTimeOuts.ReadTotalTimeoutMultiplier = 2;
	CommTimeOuts.ReadTotalTimeoutConstant = 2;
	CommTimeOuts.WriteTotalTimeoutMultiplier = 1;
	CommTimeOuts.WriteTotalTimeoutConstant = 1;

    if(SetCommTimeouts(port.file, &CommTimeOuts) == 0) {
        fputs("Error of SetCommTimeouts", stdout);
    } 
    if(port.file != INVALID_HANDLE_VALUE){
		while(1) {
			GetT(&port);
		}
		getchar();
    } else {
        fputs("Error of Handler - INVALID_HANDLE_VALUE", stdout);
    }
}
 