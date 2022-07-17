#ifndef DEF_WIN
	#define DEF_WIN
	#include <windows.h>
#endif
#define BUFFER_SIZE 1024

typedef struct struct_port {
	HANDLE file;
	unsigned char out_buffer[BUFFER_SIZE];
	unsigned char in_buffer[BUFFER_SIZE];
	unsigned long receive;
} port_type;