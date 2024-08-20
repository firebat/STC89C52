#include <reg52.h>
#include "DS1302.h"
#include "LCD1602.h"

void main()
{
	unsigned char Data;
	
	LCD_Init();

	DS1302_Init();
	DS1302_WriteByte(0x8C, 0x24); // Year
	DS1302_WriteByte(0x8A, 0x01); // Week
	DS1302_WriteByte(0x88, 0x01); // Month
	DS1302_WriteByte(0x86, 0x01); // Date
	DS1302_WriteByte(0x84, 0x00); // Hour
	DS1302_WriteByte(0x82, 0x00); // Minute
	DS1302_WriteByte(0x80, 0x00); // Second

	while(1)
	{
		Data = DS1302_ReadByte(0x8D);
		LCD_ShowHexNumber(1,1,Data,2);
		LCD_ShowChar(1,3,'-');
		Data = DS1302_ReadByte(0x89);
		LCD_ShowHexNumber(1,4,Data,2);
		LCD_ShowChar(1,6,'-');
		Data = DS1302_ReadByte(0x87);
		LCD_ShowHexNumber(1,7,Data,2);
		
		Data = DS1302_ReadByte(0x8B);
		LCD_ShowString(1,10,"Week");
		LCD_ShowHexNumber(1,15,Data,1);
		
		Data = DS1302_ReadByte(0x85);
		LCD_ShowHexNumber(2,1,Data,2);
		LCD_ShowChar(2,3,':');
		Data = DS1302_ReadByte(0x83);
		LCD_ShowHexNumber(2,4,Data,2);
		LCD_ShowChar(2,6,':');
		Data = DS1302_ReadByte(0x81);
		LCD_ShowHexNumber(2,7,Data,2);


		LCD_Delay(500);
	}
}