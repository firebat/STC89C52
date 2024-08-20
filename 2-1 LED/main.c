#include <reg52.h>
#include "Delay.h"

// JP1 - JP11

void main()
{
	while(1)
	{
		P2=0xFF;		// 1111 1111
		Delay(200);
		P2=0xFE;		// 1111 1110
		Delay(200);
		P2=0xFD;		// 1111 1101
		Delay(200);
		P2=0xFB;		// 1111 1011
		Delay(200);
		P2=0xF7;		// 1111 1011
		Delay(200);
		P2=0xEF;
		Delay(200);
		P2=0xDF;
		Delay(200);
		P2=0xBF;
		Delay(200);
		P2=0x7F;
		Delay(200);
	}
}