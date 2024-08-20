#include <reg52.h>

// Timer0 ��ʱ��
void Timer0_Init()		//1����@12.000MHz
{
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0x00;				//���ö�ʱ��ʼֵ
	TH0 = 0x00;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 0;				//��ʱ��0����ʱ
}

void Timer0_SetCounter(unsigned int Counter)
{
	TH0=Counter/256;
	TL0=Counter%256;
}

unsigned int Timer0_GetCounter()
{
	return (TH0<<8)|TL0;
}

void Timer0_Run(unsigned char Flag)
{
	TR0=Flag;
}
