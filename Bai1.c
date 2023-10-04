#include <stdio.h>
#include <stdint.h>
#include <math.h>
 
#define CHUVI(A,B,C)   (A) + (B) + (C)
#define DIENTICH(A,B,C)  ((A) + (B) + (C)) *  ((A) + (B) - (C)) *  ((B) + (C) - (A)) *  ((C) + (A) - (B)) 
typedef struct
{
	float  A,B,C;
	float chuvi;
	float dientich;
}triangle_t;

uint8_t Check_dientich(triangle_t * cal)
{
	float  data;
	data  = DIENTICH(cal->A ,cal->B,cal->C );
	data =  (float)1/4  *  (float)sqrt( data  );
	if(data == cal->dientich ) return 1;
	return 0;
}

uint8_t Check_chuvi(triangle_t * cal)
{
	float  data;
	data  =CHUVI(cal->A ,cal->B,cal->C );
	if(data == cal->chuvi ) return 1;
	return 0;
}

uint8_t Check_triangle(triangle_t* cal)
{
	if(Check_dientich(cal)  == 1 && Check_chuvi(cal) == 1 ) return 1;
	return 0;
}


void input_triangle(triangle_t* cal)
{
	cal->chuvi    = CHUVI(cal->A ,cal->B,cal->C );
	float data     =      DIENTICH(cal->A ,cal->B,cal->C );  
	cal->dientich    = (float)1/4  *  (float)sqrt( data  );
	
}



void main()
{
	triangle_t var1 = {34,45,79,0,0};
	input_triangle(&var1);
    printf("%.2f  %.2f\n", var1.chuvi , var1.dientich);
    if( Check_triangle( &var1 ) == 1)
    {
    	printf(" correct ");
	}
   else{
   	 printf(" incorrect ");
   }
}
