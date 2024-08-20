#include <reg52.h>

void Timer0_Init()		// 1����@12.000MHz
{
	TMOD &= 0xF0;	// ����ģʽ GATE=0, C/T=0(��ʱ��), M1M0=01(16λ)
	TMOD |= 0x01;
	TL0 = 0x18;		// ��ʼֵ FFFF-FC18=1000us
	TH0 = 0xFC;
	TF0 = 0;		// �����־
	TR0 = 1;		// ���п���

	ET0=1;			// �ⲿ�жϱ�־
	PT0=0;			// �����ȼ�
	EA=1;			// ȫ���ж�
}

//void Timer0_Routine() interrupt 1 
//{
//}
