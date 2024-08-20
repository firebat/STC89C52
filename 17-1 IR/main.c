#include <reg52.h>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"
#include "IR.h"

#define IR_Power	0x45
#define IR_Mode		0x46
#define IR_Mute		0x47
#define IR_Pause	0x44
#define IR_Back		0x40
#define IR_Forward	0x43
#define IR_EQ		0x07
#define IR_Vol_		0x15
#define IR_Vol		0x09
#define IR_0		0x16
#define IR_RPT		0x19
#define IR_USD		0x0D
#define IR_1		0x0C
#define IR_2		0x18
#define IR_3		0x5E
#define IR_4		0x08
#define IR_5		0x1C
#define IR_6		0x5A
#define IR_7		0x42
#define IR_8		0x52
#define IR_9		0x4A

sbit P1_4=P1^4;

unsigned char Address, Command;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ADR CMD");
	LCD_ShowString(2,1,"00  00 ");

	IR_Init();

	while(1)
	{
		if(IR_GetDataFlag())
		{
			Address = IR_GetAddress();
			Command = IR_GetCommand();
			
			LCD_ShowHexNumber(2,1,Address, 2);
			LCD_ShowHexNumber(2,5,Command, 2);
			
			switch (Command) 
			{
				case IR_Power: {
					P1_4=!P1_4;
					break;
				}
			}
		}
		Delay(500);
	}
}
