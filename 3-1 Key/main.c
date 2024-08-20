#include <reg52.h>
#include "Delay.h"

// JP5 - JP10
// JP1 - JP11

sbit P0_0=P0^0;
sbit P0_1=P0^1;
sbit P2_0=P2^0;

void main()
{
	unsigned char Num=0;
	while(1)
	{
		if (P0_0 == 0)
		{
			Delay(20);
			while(P0_0==0);
			Delay(20);
			
			Num++;
			if (Num>=8)
				Num=0;
		}
		
		if (P0_1 == 0)
		{
			Delay(20);
			while(P0_1==0);
			Delay(20);

			if (Num==0)
				Num=7;
			else
				Num--;
		}
		P2 = ~(0x01 << Num);
	}
}