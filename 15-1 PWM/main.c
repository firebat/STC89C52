#include <reg52.h>
#include "Delay.h"
#include "Timer0.h"

sbit LED=P2^0;

unsigned char Counter, Compare;

void main()
{
	Counter=0;
	Timer0_Init();
	
	while(1)
	{
		for(Compare=0;Compare<90;Compare++)
		{
			Delay(5);
		}
		for(Compare=90;Compare>0;Compare--)
		{
			Delay(5);
		}
	}
}

void Timer0_Routine() interrupt 1
{
	TL0 = 0x9C;	// 100us
	TH0 = 0xFF;
	
	Counter++;
	Counter%=100;
	if(Counter > Compare)
	{
		LED=0;
	}
	else 
	{
		LED=1;
	}
}