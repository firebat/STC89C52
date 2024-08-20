#include <reg52.h>
#include "Timer0.h"
#include "Int0.h"
#include "LCD1602.h"

unsigned int IR_Time;
unsigned char IR_State;

unsigned char IR_Data[4];
unsigned char IR_pData;

unsigned char IR_DataFlag;
unsigned char IR_RepeatFlag;

unsigned char IR_Address;
unsigned char IR_Command;

void IR_Init()
{
	Timer0_Init();
	Int0_Init();
}

unsigned char IR_GetDataFlag()
{
	if(IR_DataFlag)
	{
		IR_DataFlag=0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetRepeatFlag()
{
	if(IR_RepeatFlag)
	{
		IR_RepeatFlag=0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetAddress()
{
	return IR_Address;
}

unsigned char IR_GetCommand()
{
	return IR_Command;
}

void Int0_Routine() interrupt 0
{
	// 状态0，空闲状态
	if (IR_State == 0)
	{
		Timer0_SetCounter(0);
		Timer0_Run(1);
		IR_State=1;
	} 

	// 状态1，等待Start或Repeat
	else if (IR_State==1)
	{
		IR_Time=Timer0_GetCounter();
		Timer0_SetCounter(0);
		// 13500
		if(IR_Time>13500-500 && IR_Time<13500+500)
		{
			IR_State=2;
		}
		// 11250
		else if(IR_Time>11250-500 && IR_Time<11250+500)
		{
			IR_RepeatFlag=1;
			IR_State=0;
			Timer0_Run(0);
		}
		// 接收出错
		else
		{
			IR_State=1;
			LCD_ShowString(1,9,"ERR1");
			LCD_ShowNumber(2,9,IR_Time,6);
		}
	}
	// 状态2, 接收数据
	else if (IR_State==2)
	{	
		IR_Time=Timer0_GetCounter();
		Timer0_SetCounter(0);
		// 1120
		if(IR_Time>1120-500 && IR_Time<1120+500)		// 收到0, 560-560
		{
			IR_Data[IR_pData/8]&=~(0x01<<(IR_pData%8));
			IR_pData++;
		}
		// 2250
		else if (IR_Time>2250-500 && IR_Time<2250+500)	// 收到1, 560-1690
		{
			IR_Data[IR_pData/8]|=(0x01<<(IR_pData%8));
			IR_pData++;
		}
		// 接收出错
		else
		{
			IR_pData=0;
			IR_State=1;
			LCD_ShowString(1,9,"ERR2");
			LCD_ShowNumber(2,9,IR_Time,6);
		}

		// 数据接收完毕
		if(IR_pData>=32)
		{
			IR_pData=0;
			if ((IR_Data[0]==~IR_Data[1]) && (IR_Data[2]==~IR_Data[3]))
			{
				IR_Address=IR_Data[0];
				IR_Command=IR_Data[2];
				IR_DataFlag=1;
			}
			else
			{
				LCD_ShowString(1,9,"ERR3");
			}
			Timer0_Run(0);
			IR_State=0;
		}
	}
}
