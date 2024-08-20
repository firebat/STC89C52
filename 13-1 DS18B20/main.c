#include <reg52.h>
#include "LCD1602.h"
#include "DS18B20.h"


void main()
{
	float T;

	LCD_Init();
	LCD_ShowString(1,1,"Temp:");

	while(1)
	{
		DS18B20_ConvertT();
		T=DS18B20_ReadT();
		if (T<0)
		{
			LCD_ShowChar(2,1,'-');
			T=-T;
		} else {
			LCD_ShowChar(2,1,'+');
		}
		LCD_ShowNumber(2,2,T,3);
		LCD_ShowChar(2,5,'.');
		LCD_ShowNumber(2,6,(unsigned long)(T*1000)%1000,3);
		LCD_ShowChar(2,9,'C');
		LCD_Delay(2000);
	}
	
}