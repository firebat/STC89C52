#include <reg52.h>

void Uart_Init(void)	//4800bps@12.000MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF3;			//设置定时初始值
	TH1 = 0xF3;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时

	ES = 1;				//开启串口中断(接收用)
	EA = 1;				//开启所有中断
}

void Uart_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;			// 发送中断
}
