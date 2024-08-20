#include <reg52.h>
#include "Delay.h"

#define MatrixLED_Port P0

sbit RCK = P3^5;	// RCLK	  ����
sbit SCK = P3^6;	// SERCLK ��λ
sbit SER = P3^4;	// SER	  ����


void MatrixLED_Init()
{	
	SCK=0;
	RCK=0;
}


// �������棬�������룬�������
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

void MatrixLED_ShowColumn(unsigned char Column, Data)
{
	_74HC595_WriteByte(Data);
	MatrixLED_Port=~(0x80>>Column);
	Delay(1);
	MatrixLED_Port=0xFF;
}
