#include <reg52.h>

void Int0_Init()
{
	IT0=1;	// 0: �͵�ƽ����; 1: ���ش���
	IE0=0;	// �ⲿ�ж�0�����־
	EX0=1;	// �ⲿ�ж�0����
	EA=1;	// ȫ���ж�����
	PX0=1;	// �ж�0���ȼ�
}

//void Int0_Routine() interrupt 0
//{
//}
