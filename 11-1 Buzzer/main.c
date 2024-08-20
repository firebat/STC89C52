#include <reg52.h>
#include "Delay.h"
#include "Timer0.h"
#include "music.h"

#define SPEED 500

sbit Buzzer=P1^5;

unsigned int code FreqTable[]={
	0,
	63625, 63732, 63833, 63929, 64019, 64104, 64185, 64260, 64332, 64400, 64463, 64524,
	64580, 64634, 64685, 64732, 64778, 64820, 64860, 64898, 64934, 64968, 65000, 65030,
	65058, 65085, 65110, 65134, 65157, 65178, 65198, 65217, 65235, 65252, 65268, 65283
};

unsigned char code Music[]={
	// 1
	L0,4,
	L0,4,
	L0,4,
	M6,2,
	M7,2,
	
	H1,4+2,
	M7,2,
	H1,4,
	H3,4,
	
	M7,4+4+4,
	M3,2,
	M3,2,

	// 2
	M6,4+2,
	M5,2,
	M6,4,
	H1,4,
	
	M5,4+4+4,
	M3,4,

	M4,4+2,
	M3,2,
	M4,4,
	H1,4,

	// 3
	M3,4+4,
	L0,2,
	H1,2,
	H1,2,
	H1,2,
	
	M7,4+2,
	M4_,2,
	M4_,4,
	M7,4,
	
	M7,4+4,
	L0,4,
	M6,2,
	M7,2,
	
	// 4
	H1,4+2,
	M7,2,
	H1,4,
	H3,4,
	
	M7,4+4+4,
	M3,2,
	M3,2,

	M6,4+2,
	M5,2,
	M6,4,
	H1,4,

	//5
	M5,4+4+4,
	M2,2,
	M3,2,
	
	M4,4,
	H1,2,
	M7,2+2,
	H1,2+4,
	
	H2,2,
	H2,2,
	H3,2,
	H1,2,
	H1,2+4+4,
	
	// 6
	H1,2,
	M7,2,
	M6,2,
	M6,2,
	M7,4,
	M5_,4,
	
	M6,4+4+4,
	H1,2,
	H2,2,

	H3,2+4,
	H2,2,
	H3,4,
	H5,4,
	
	0xFF
};

unsigned char FreqSelect, MusicSelect;

void main()
{
	Timer0_Init();

	FreqSelect=0;
	while(1)
	{
		FreqSelect=Music[MusicSelect];
		if (FreqSelect == 0xFF)
		{
			break;
		}

		MusicSelect++;
		Delay(SPEED / 4 * Music[MusicSelect]);
		MusicSelect++;
		TR0=0;
		Delay(5);
		TR0=1;
	}
}


void Timer0_Routine() interrupt 1 
{
	if (FreqSelect>0)
	{
		TL0 = FreqTable[FreqSelect] % 265;
		TH0 = FreqTable[FreqSelect] / 265;
		Buzzer=!Buzzer;
	}
}