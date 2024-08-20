#include <reg52.h>
#include "Timer0.h"
#include "Nixie.h"

// JP10(P0) - JP12
unsigned char Number;

void main()
{
	Timer0_Init();
	while(1)
	{
		Nixie(8, Number	    % 10);
		Nixie(7, Number/10  % 10);
		Nixie(6, Number/100 % 10);
	}
}


void Timer0_Routine() interrupt 1 
{
	static unsigned int T0Count;
	TH0 = 0xFC;
	TL0 = 0x18;
	T0Count++;
	if (T0Count>=1000)	// 1s
	{
		T0Count=0;
		Number++;
	}
}
