#include <stdio.h>
#include <stdint.h>
#define MAX_TIMER 300000000
#define MIN_TIMER 0
#define LOAD_VALUE 700
#define START_TIMER 30000
#define STOP_TIMER 100000000

uint8_t Flag_ISR= 0;
uint8_t Flag_Load_Value  = 0;
uint32_t Load_value = 0;
uint32_t Counter =0;
uint32_t periodic = 0;
uint32_t Start_timer, Stop_timer;
uint8_t Close_timer = 0;

void Callback()
{
	printf(" %d ", Start_timer);
	if(Start_timer == Stop_timer )	Close_timer = 1;
}
void (*Fuc_ptr)(void);

void Timer_SoftWare()
{
	while(Counter <= MAX_TIMER )         // khi counter dang dem
	{
		Counter++;
		Start_timer++;
		if(Load_value = LOAD_VALUE )
		{
			Flag_Load_Value = 1;
		}
	}
	Counter = 0; // khi counter dem xong thi reset ve 0
	Flag_ISR = 1;
	

}



void main()
{
	uint32_t A = 10,B=20;
	Fuc_ptr = &Callback;
	Start_timer = START_TIMER;
	Stop_timer =  STOP_TIMER;
	while(Close_timer != 1)
	{
	Timer_SoftWare(); // delay 1s
	if(Flag_ISR == 1 )  // co` ngat xay ra thi vao goi ham
	{
		periodic++;  // tang chu ki cua timer 
		Fuc_ptr();
		Flag_ISR = 0;
	}
	
	
	if(	Flag_Load_Value == 1)Flag_Load_Value = 0;
	}
	
}
