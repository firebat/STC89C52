#include "OneWire.h"

#define DS18B20_SKIP_ROM 	0xCC
#define DS18B20_CONVERT_T 	0x44
#define DS18B20_READ_PAD 	0xBE

void DS18B20_ConvertT()
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVERT_T);
}

float DS18B20_ReadT()
{
	unsigned char TLSB,TMSB;
	int Temp;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_PAD);
	TLSB=OneWire_RecvByte();
	TMSB=OneWire_RecvByte();
	Temp=(TMSB<<8)|TLSB;
	return Temp/16.0;
}