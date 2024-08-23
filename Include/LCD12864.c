#include <reg52.h>

#define LCD12864_DataPort P0

sbit LCD12864_EN=P2^7;
sbit LCD12864_RS=P2^6;
sbit LCD12864_RW=P2^5;
sbit LCD12864_PSB=P3^2;


void LCD12864_Delay(unsigned int xms)	//@12.000MHz
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

void LCD12864_WriteCommand(unsigned char Command)
{
	LCD12864_RS=0;
	LCD12864_RW=0;
	LCD12864_EN=0;
	LCD12864_DataPort = Command;
	LCD12864_EN=1;
	LCD12864_Delay(1);
	LCD12864_EN=0;
	LCD12864_Delay(1);
}

void LCD12864_WriteData(unsigned char Data)
{
	LCD12864_RS=1;
	LCD12864_RW=0;
	LCD12864_EN=0;
	LCD12864_DataPort = Data;
	LCD12864_EN=1;
	LCD12864_Delay(1);
	LCD12864_EN=0;
	LCD12864_Delay(1);
}

void LCD12864_Init()
{
	LCD12864_PSB=1;
	
	LCD12864_WriteCommand(0x30);
	LCD12864_WriteCommand(0x0C);	// 显示开，光标关，闪烁关
	LCD12864_WriteCommand(0x06);	// 数据读写操作后，光标自动加一，画面不动
	LCD12864_WriteCommand(0x01); 	// 清屏
}

void LCD12864_Clear()
{
	LCD12864_WriteCommand(0x01);
}

void LCD12864_ShowString(unsigned char x, unsigned char y, unsigned char *String)
{
	if (x<0) x=0;
	if (y<0) y=0;
	if (y>3) y=3;
	x &= 0x0f;
	
	if (y==0) {
		x |= 0x80;
	}else if (y==1) {
		x |= 0x90;
	}else if (y==2) {
		x |= 0x88;
	}else if (y==3) {
		x |= 0x98;
	}
	LCD12864_WriteCommand(x);
	while(*String != '\0') {
		LCD12864_WriteData(*String);
		String++;
	}
}
