#include <stdio.h>
#include <stdint.h>
#include <math.h>


#define SWAP_ENDIAN(x) (((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000)
void main()
{
	uint8_t  Block_data[8] = {0x12,0x34,0x56,0x78,0xAB,0xCD,0xEF,0xFF};
	uint32_t  data[2];
	uint32_t *ptr;
	uint8_t  i;
	ptr =  &Block_data[0];
	printf("data little - endian : ");
	for(i = 0; i < 2; i++)
	{	
		data[i] =(ptr[i]);
		printf(" %x ",data[i]);
	}
	printf("\ndata big - endian    : ");
	for(i = 0; i < 2; i++)
	{
		data[i] = SWAP_ENDIAN(ptr[i]);
		printf(" %x ",data[i]);
	}
	
	
}
