#ifndef __LCD_H_
#define __LCD_H_

// 初始化LCD
void LCD_Init();

// 延时函数
void LCD_Delay(unsigned char);

// 写命令
void LCD_WriteCommand(unsigned char);

// 写数据
void LCD_WriteData(unsigned char);

// 设置光标位置
void LCD_SetCursor(unsigned char Line, Column);

// 显示字符
void LCD_ShowChar(unsigned char Line, Column, unsigned char);

// 显示字符串
void LCD_ShowString(unsigned char Line, Column, unsigned char*);

// 显示无符号数字
void LCD_ShowNumber(unsigned char Line, Column, unsigned int Number, unsigned char Length);

// 显示有符号数字
void LCD_ShowSignedNumber(unsigned char Line, Column, int Number, unsigned char Length);

// 显示十六进制数字
void LCD_ShowHexNumber(unsigned char Line, Column, unsigned int Number, unsigned char Length);

// 显示二进制数字
void LCD_ShowBinNumber(unsigned char Line, Column, unsigned int Number, unsigned char Length);

#endif