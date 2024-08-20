#include <reg52.h>
#include "Keyboard.h"
#include "Delay.h"
#include "Nixie.h"

// J12 - JP10(P0)
// JP4 - JP8(P1)
void main()
{
	unsigned char Number=0, Key=0;
	
	while(1)
	{
		Key = Key_Down();
		if (Key>0)
		{
			Number=Key;
		}
		
		Nixie(8, Number    % 10);
		Nixie(7, Number/10 % 10);
	}
}
