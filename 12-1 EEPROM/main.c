#include <reg52.h>
#include "LCD1602.h"
#include "AT24C02.h"

void main()
{
	unsigned char Data[]="Hello", Byte, i;

	LCD_Init();
	LCD_ShowString(1,1,Data);
	
	for(i=0;i<5;i++)
	{
		AT24C02_WriteByte(i, Data[i]);
	}

	for(i=0;i<5;i++)
	{
		Byte=AT24C02_ReadByte(i);
		LCD_ShowChar(2,i+1,Byte);
	}

	while(1)
	{
	}
}
