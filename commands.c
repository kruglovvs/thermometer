#ifndef DEF_STDIO
	#define DEF_STDIO
	#include <stdio.h>
#endif
#ifndef DEF_PORT
	#define DEF_PORT
	#include "port.h"
#endif

void GetT(port_type *port) {
	WriteFile(port->file, "!GetT\r", 6, &(port->receive), NULL);
	FILE *file = fdopen((int)(port->file), "r");
	if(ReadFile(port->file, port->in_buffer, 1024, &(port->receive), NULL)) {
		fputs("\ngot: ", stdout);
		fputs(port->in_buffer, stdout);
	} else {
		fputs("Readfile fail->\n", stdout);
	}
	fputs("!!", stdout);
}





/*#include <time.h>
#define TEMP_A 0
void SetA(port_type *port) {    
	struct tm *time_struct;
	const time_t timer = time(NULL);
	time_struct = localtime(&timer);
	printf("%ld -> ", timer);
	printf("%02d:%02d ", time_struct->tm_hour, time_struct->tm_min);
	  
	WriteFile(port->file, "!SetA", 5, &port->receive, NULL);
	if((port->receive == 6) && ReadFile(port->file, port->out_buffer, 1024, &port->receive, NULL))
		fputs(port->out_buffer, stdout);
	else 
		fputs("Readfile fail->\n", stdout);
	
}*/
/*#include <stdio.h>  // Для printf
#include <time.h>   // Для time, ctime
int main (void) {    
  struct tm *time_struct;
  //system("chcp 1251");
  fputs("lol",stdout);
  FILE *fd_in = open("\\\\.\\COM3", "rw");
  HANDLE hFile  = CreateFile("\\\\.\\COM3", GENERIC_READ | GENERIC_WRITE, 0, NULL,
                            OPEN_EXISTING, 0, NULL);
	int    handle = _open_osfhandle((LONG)hFile, _mode);
	FILE*  f      = fdopen(handle, szMode);
  if (а==NULL) printf(" kek ");
  fputs("!GetT\r",f);
fgets()  
  //const time_t timer = time(NULL);
  //time_struct = localtime(&timer);
  //printf("%ld -> ", timer);
  //printf("%02d:%02d ", time_struct->tm_hour, time_struct->tm_min);
  getchar();
  return 0;
}*/