#include <reg52.h>
#include "Uart.h"
#include "Delay.h"

// JP1 - JP11
void main()
{
	unsigned int i=0;
	Uart_Init();

	while(1)
	{
		Delay(300);
	}
}

void Uart_Routine() interrupt 4
{
	if (RI == 1)		//Ω” ’÷–∂œ
	{
		P2=SBUF;
		Uart_SendByte(SBUF);
		RI=0;
	}
}