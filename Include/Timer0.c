#include <reg52.h>

void Timer0_Init()		// 1毫秒@12.000MHz
{
	TMOD &= 0xF0;	// 工作模式 GATE=0, C/T=0(定时器), M1M0=01(16位)
	TMOD |= 0x01;
	TL0 = 0x18;		// 初始值 FFFF-FC18=1000us
	TH0 = 0xFC;
	TF0 = 0;		// 溢出标志
	TR0 = 1;		// 运行控制

	ET0=1;			// 外部中断标志
	PT0=0;			// 低优先级
	EA=1;			// 全局中断
}

//void Timer0_Routine() interrupt 1 
//{
//}
