#include <reg52.h>

// TCON 定时器控制
// - TF1 定时器/计数器1 溢出标记 TF1=1溢出
// - TR1 定时器/计数器1 启停标记 TR1=1启动
// - TF0 定时器/计数器0 溢出标记
// - TR1 定时器/计数器1 启停标记
// - IE1 外部中断1 请求标记 IE1=1有中断
// - IT1 外部中断1 触发方式 IT1=1低电平触发, IT=0下降沿触发
// - IE0 外部中断0 请求标记
// - IT0 外部中断0 触发方式

// IE 中断允许控制
// - EA 总开关
// - ET2 定时器/计数器2 允许
// - ES 串口中断		允许
// - ET1 定时器/计数器1 允许
// - EX1 外部中断1		允许
// - ET0 定时器/计数器0 允许
// - EX0 外部中断0		允许

// IP 优先级控制
// - PT2, PS, PT1, PX1, PT0, PX0

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
