#include <REGX52.H>
#include "Delay.h"
#include "LIGHT.H"

void main()
{
	while(1)
	{
		LIGHT(7,1);
		LIGHT(8,0);
		Delay(1000);
		LIGHT(8,9);
		Delay(1000);
		LIGHT(8,8);
		Delay(1000);
		LIGHT(8,7);
		Delay(1000);
		LIGHT(8,6);
		Delay(1000);
		LIGHT(8,5);
		Delay(1000);
		LIGHT(8,4);
		Delay(1000);
		LIGHT(8,3);
		Delay(1000);
		LIGHT(8,2);
		Delay(1000);
		LIGHT(8,1);
		Delay(1000);
	}
}