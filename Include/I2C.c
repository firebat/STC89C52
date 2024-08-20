#include <reg52.h>

sbit I2C_SCL=P2^0;
sbit I2C_SDA=P2^1;

void I2C_Start()
{
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;
}

void I2C_Stop()
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
}

void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;
	}
}

unsigned char I2C_RecvByte()
{
	unsigned char Byte=0x00;
	unsigned char i;

	I2C_SDA=1;
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if (I2C_SDA)
			Byte|=(0x80>>i);
		I2C_SCL=0;
	}
	
	return Byte;
}

void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	I2C_SCL=0;
}

unsigned char I2C_RecvAck()
{
	unsigned char AckBit;
	I2C_SDA=1;
	I2C_SCL=1;
	AckBit=I2C_SDA;
	I2C_SCL=0;
	return AckBit;
}

