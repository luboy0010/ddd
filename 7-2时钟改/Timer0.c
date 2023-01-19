#include <REGX52.H>

void Timer0_Init()//定时器0初始化
{
	TMOD&=0xF0;
	TMOD|=0x01;
	TF0=0;
	TR0=1;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;
	ET0=1;
	EA=1;
	PT0=0;
}
/*
void Timer0_Routine() interrupt 1
{	
	static unsigned int T0count=0;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;
	T0count++;
	if(T0count>=1000)
		{
			T0count=0;
			T0count++;
			P2_0=~P2_0;
		}
}	
*/