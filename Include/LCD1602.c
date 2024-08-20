#include <reg52.h>

#define LCD_DataPort P0

sbit LCD_RS=P2^6;	// 指令/数据
sbit LCD_RW=P2^5;	// 读/写
sbit LCD_E=P2^7;	// 读写生效

void LCD_Delay(unsigned char xms)	//@12.000MHz
{
	unsigned char i, j;

	do
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	} while(--xms);
}

void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DataPort = Command;
	LCD_E=1;
	LCD_Delay(1);
	LCD_E=0;
	LCD_Delay(1);
}

void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DataPort = Data;
	LCD_E=1;
	LCD_Delay(1);
	LCD_E=0;
	LCD_Delay(1);
}

void LCD_Init()
{
	LCD_WriteCommand(0x38);	// 八位数据接口，两行显示，5*7点阵
	LCD_WriteCommand(0x0C);	// 显示开，光标关，闪烁关
	LCD_WriteCommand(0x06);	// 数据读写操作后，光标自动加一，画面不动
	LCD_WriteCommand(0x01); // 清屏
}

void LCD_SetCursor(unsigned char Line, Column)
{
	if (Line == 1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	} else {
		LCD_WriteCommand(0x80|(Column-1) + 0x40);
	}
}

void LCD_ShowChar(unsigned char Line, Column, unsigned char Char)
{
	LCD_SetCursor(Line, Column);
	LCD_WriteData(Char);
}

void LCD_ShowString(unsigned char Line, Column, unsigned char *String)
{
	unsigned char i;
	LCD_SetCursor(Line, Column);
	for (i=0;String[i]!='\0';i++)
	{
		LCD_WriteData(String[i]);
	}
}

unsigned int LCD_Pow(int X, Y)
{
	unsigned char i;
	int result=1;
	for(i=0;i<Y;i++)
	{
		result=result*X;
	}
	return result;
}


void LCD_ShowNumber(unsigned char Line, Column, unsigned int Number, unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Line, Column);

	for (i=Length;i>0;i--)
	{
		LCD_WriteData('0' + (Number / LCD_Pow(10, i-1) % 10)) ;
	}
}

void LCD_ShowSignedNumber(unsigned char Line, Column, int Number, unsigned char Length)
{
	unsigned char i;
	unsigned int Data;

	LCD_SetCursor(Line, Column);
	if (Number>0)
	{
		LCD_WriteData('+');
		Data=Number;
		
	} else {
		LCD_WriteData('-');
		Data=-Number;
	}

	for (i=Length;i>0;i--)
	{
		LCD_WriteData('0' + Data/LCD_Pow(10,i-1)%10) ;
	}
}

void LCD_ShowHexNumber(unsigned char Line, Column, unsigned int Number, unsigned char Length)
{
	unsigned char i;
	unsigned char Single;
	LCD_SetCursor(Line, Column);

	for (i=Length;i>0;i--)
	{
		Single = Number/LCD_Pow(16,i-1)%16;
		if(Single<10)
		{
			LCD_WriteData('0' + Single);
		} else {
			LCD_WriteData('A' + Single - 10) ;
		}
	}
}

void LCD_ShowBinNumber(unsigned char Line, Column, unsigned int Number, unsigned char Length)
{
	unsigned char i;

	LCD_SetCursor(Line, Column);
	for (i=Length;i>0;i--)
	{
		LCD_WriteData('0' + (Number / LCD_Pow(2, i-1) % 2)) ;
	}
}
