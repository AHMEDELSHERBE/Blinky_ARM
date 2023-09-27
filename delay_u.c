#include "delay.h"
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
	void delay(u32 j)
		{
			for ( u32 i= 0;  i<j;i++ )
			{
				asm("nop");
			}
		}
