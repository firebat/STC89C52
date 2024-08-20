#ifndef __ONE_WIRE_H
#define __ONE_WIRE_H

unsigned char OneWire_Init();
void OneWire_SendBit(unsigned char Bit);
unsigned char OneWire_RecvBit();
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_RecvByte();
#endif
