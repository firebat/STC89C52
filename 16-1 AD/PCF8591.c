#include <reg52.h>
#include "I2C.h"

#define PCF8591_ADDR 0x90

// Address 1001 A2,A2,A0,R/W
// Control
// - 0 
// - 1  Analogue Output
// - 00 Analogue Input Type
// - 0
// - 1  Auto-Increment
// - 00 A/D Channel Number
unsigned char PCF8591_ADC(unsigned char Address, Control)
{
	unsigned char Data;

	I2C_Start();
	I2C_SendByte(Address);		// Address
	I2C_RecvAck();
	I2C_SendByte(Control&0x33);	// Control 00xx00xx
	I2C_RecvAck();

	// 读数据
	I2C_Start();
	I2C_SendByte(Address|0x01);
	I2C_RecvAck();
	I2C_RecvByte();				// 忽略上次结果
	I2C_SendAck(0);
	
	Data=I2C_RecvByte();
	I2C_SendAck(1);
	I2C_Stop();

	return Data;
}

unsigned char PCF8591_DAC(unsigned char Address, Data)
{
	I2C_Start();
	I2C_SendByte(Address);	// Address
	I2C_RecvAck();
	I2C_SendByte(0x40);		// Control 01000000
	I2C_RecvAck();

	I2C_SendByte(Data);
	I2C_RecvAck();
	I2C_Stop();
}
