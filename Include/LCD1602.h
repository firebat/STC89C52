#ifndef __LCD_H_
#define __LCD_H_

// ��ʼ��LCD
void LCD_Init();

// ��ʱ����
void LCD_Delay(unsigned char);

// д����
void LCD_WriteCommand(unsigned char);

// д����
void LCD_WriteData(unsigned char);

// ���ù��λ��
void LCD_SetCursor(unsigned char Line, Column);

// ��ʾ�ַ�
void LCD_ShowChar(unsigned char Line, Column, unsigned char);

// ��ʾ�ַ���
void LCD_ShowString(unsigned char Line, Column, unsigned char*);

// ��ʾ�޷�������
void LCD_ShowNumber(unsigned char Line, Column, unsigned int Number, unsigned char Length);

// ��ʾ�з�������
void LCD_ShowSignedNumber(unsigned char Line, Column, int Number, unsigned char Length);

// ��ʾʮ����������
void LCD_ShowHexNumber(unsigned char Line, Column, unsigned int Number, unsigned char Length);

// ��ʾ����������
void LCD_ShowBinNumber(unsigned char Line, Column, unsigned int Number, unsigned char Length);

#endif