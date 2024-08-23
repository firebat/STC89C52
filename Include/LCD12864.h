#ifndef __LCD12864_H_
#define __LCD12864_H_

void LCD12864_Init();

void LCD12864_Delay(unsigned int ms);

void LCD12864_WriteCommand(unsigned char Command);

void LCD12864_WriteData(unsigned char Data);

void LCD12864_Clear();

void LCD12864_ShowString(unsigned char x, unsigned char y, unsigned char *String);

#endif