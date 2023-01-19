#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"
#include "matrixkey.h"

int sec=0,min=0,hour=0;
unsigned int keynum=0,count=0;

void main()
{
	Timer0_Init();
	LCD_Init();
	LCD_ShowString(1,1,"CLOCK:");
	LCD_ShowString(2,1,"  :  :");
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,sec,2);
	}
}

void Timer0_Routine() interrupt 1
{	
	static unsigned int T0count=0;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;
	T0count++;
	if(T0count>=1000)
		{
			T0count=0;
			sec++;
			if(sec>=60)
				{
					sec=0;
					min++;
					if(min>=60)
						{
							min=0;
							hour++;
							if(hour>=24)
								{
									hour=0;
								}
						}
				}	
		}
}	