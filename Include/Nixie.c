#include <reg52.h>
#include "Delay.h"

sbit P2_2=P2^2;
sbit P2_3=P2^3;
sbit P2_4=P2^4;

const unsigned char NixieTable[]={
	0xFC, //1111 1100 0
	0x60, //0110 0000 1
	0xDA, //1101 1010 2
	0xF2, //1111 0010 3
	0x66, //0110 0110 4
	0xB6, //1011 0110 5
	0xBE, //1011 1110 6
	0xE0, //1110 0000 7
	0xFE, //1111 1110 8
	0xF6, //1111 0110 9
};


void Nixie(unsigned char Location, Number)
{
	switch (Location)
	{
		case 1: P2_4=0;P2_3=0;P2_2=0;break;
		case 2: P2_4=0;P2_3=0;P2_2=1;break;
		case 3: P2_4=0;P2_3=1;P2_2=0;break;
		case 4: P2_4=0;P2_3=1;P2_2=1;break;
		case 5: P2_4=1;P2_3=0;P2_2=0;break;
		case 6: P2_4=1;P2_3=0;P2_2=1;break;
		case 7: P2_4=1;P2_3=1;P2_2=0;break;
		case 8: P2_4=1;P2_3=1;P2_2=1;break;
	}
	P0=NixieTable[Number];
	Delay(2);
	P0=0x00;
}
