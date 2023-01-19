#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;



void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

void main()
{
	UART_Init();
	while(1)
	{
		UART_SendByte(Sec);
		Sec++;
		Delay(1000);
	}
}
