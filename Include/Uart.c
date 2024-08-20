#include <reg52.h>

void Uart_Init(void)	//4800bps@12.000MHz
{
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xF3;			//���ö�ʱ��ʼֵ
	TH1 = 0xF3;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	TR1 = 1;			//��ʱ��1��ʼ��ʱ

	ES = 1;				//���������ж�(������)
	EA = 1;				//���������ж�
}

void Uart_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;			// �����ж�
}
