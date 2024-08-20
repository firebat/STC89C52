void Delay(unsigned int n)	//@12.000MHz
{
	unsigned char data i, j;

	do
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	} while(--n);
}
