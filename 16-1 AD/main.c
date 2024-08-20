#include <reg52.h>
#include "LCD1602.h"
#include "PCF8591.h"

void main()
{
	unsigned char Ch0, Ch1, Aout;

	LCD_Init();
	LCD_ShowString(1,1,"CH0 CH1 AOUT");
	
	while(1)
	{
		Ch0=PCF8591_ADC(0x90, 0x00);
		Ch1=PCF8591_ADC(0x90, 0x01);
		
		LCD_ShowNumber(2,1,Ch0,3);
		LCD_ShowNumber(2,5,Ch1,3);

		Aout=Ch1-Ch0;
		LCD_ShowNumber(2,9,Aout,4);
		PCF8591_DAC(0x90, Aout);

		LCD_Delay(1000);
	}
}