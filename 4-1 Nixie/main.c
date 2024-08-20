#include <reg52.h>
#include "Nixie.h"

// JP10 - JP12


void main()
{
	while(1)
	{
		Nixie(1, 1);
		Nixie(2, 2);
		Nixie(3, 3);
		Nixie(4, 4);
		Nixie(5, 5);
		Nixie(6, 6);
		Nixie(7, 7);
		Nixie(8, 8);
	}
}

