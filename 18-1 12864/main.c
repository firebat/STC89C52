#include <reg52.h>
#include "LCD12864.h"

void main()
{
	LCD12864_Init();

	while(1)
	{
		LCD12864_ShowString(0, 0, "Hello world!");
		LCD12864_ShowString(0, 1, "ÄãºÃ£¬ÊÀ½ç!");
		LCD12864_Delay(500);
	}
}