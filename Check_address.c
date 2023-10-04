#include <stdio.h>
#include <stdint.h>


uint8_t global =4;
static uint8_t S_global = 10;

uint8_t ancut(void)
{
	uint8_t local  = 5;
	printf("%x\n" ,&local);
	return local;
}


void main()
{
	uint8_t local = global;
    static uint8_t S_local;
    
	printf("%x  %x %x %x\n",&global,&S_global,&local,&S_local);
	printf("%x  ",&ancut);
	
}
