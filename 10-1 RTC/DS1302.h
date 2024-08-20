#ifndef __DS1302_H__
#define __DS1302_H__

// 初始化时钟
void DS1302_Init();

// 写入数据
void DS1302_WriteByte(unsigned char Command, Data);

// 读出数据
unsigned char DS1302_ReadByte(unsigned char Command);

#endif