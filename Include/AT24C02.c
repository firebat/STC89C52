#include <reg52.h>
#include "I2C.h"

#define ATC24C02_ADDR	0xA0

void AT24C02_Delay(unsigned char xms)	//@12.000MHz
{
	unsigned char data i, j;

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


void AT24C02_WriteByte(unsigned char Address, Data)
{
	I2C_Start();
	I2C_SendByte(ATC24C02_ADDR);
	I2C_RecvAck();
	I2C_SendByte(Address);
	I2C_RecvAck();
	I2C_SendByte(Data);
	I2C_RecvAck();
	I2C_Stop();
	AT24C02_Delay(5);
}

unsigned char AT24C02_ReadByte(unsigned char Address)
{
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(ATC24C02_ADDR);
	I2C_RecvAck();
	I2C_SendByte(Address);
	I2C_RecvAck();
	I2C_Start();
	I2C_SendByte(ATC24C02_ADDR|0x01);
	I2C_RecvAck();
	Data=I2C_RecvByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}
