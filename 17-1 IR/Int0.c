#include <reg52.h>

void Int0_Init()
{
	IT0=1;	// 0: 低电平触发; 1: 边沿触发
	IE0=0;	// 外部中断0申请标志
	EX0=1;	// 外部中断0允许
	EA=1;	// 全部中断允许
	PX0=1;	// 中断0优先级
}

//void Int0_Routine() interrupt 0
//{
//}
