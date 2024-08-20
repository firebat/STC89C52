#include<reg52.h>
#include "Delay.h"

#define IO_KEY P3

unsigned char Key_Down()
{
	unsigned char Key=0, a=0;

	IO_KEY=0x0F;
	if (IO_KEY!=0x0F)
	{
		Delay(10);
		if(IO_KEY!=0x0F)
		{
			IO_KEY=0x0F;
			switch (IO_KEY)	// ÁÐ
			{
				case 0x07: Key=1; break;	// 0111
				case 0x0B: Key=2; break;	// 1011
				case 0x0D: Key=3; break;	// 1101
				case 0x0E: Key=4; break;	// 1110
			}

			IO_KEY=0xF0;
			switch (IO_KEY)	// ÐÐ
			{
				case 0xD0: Key=Key+4;break;	// 1101
				case 0xE0: Key=Key+8;break;	// 1110
			}
		}
	}
	return Key;
}