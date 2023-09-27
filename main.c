/*
 * main.c
 *
 *  Created on: Sep 14, 2023
 *      Author: mh_sm
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "delay.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"

int main(){

	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_BUS_APB2 , 3);
	MRCC_voidEnablePeripheral(RCC_BUS_APB2 , 2);
	MGPIO_voidSetPinDirection(PORTA,3,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinDirection(PORTA,2,GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	while(1){
		MGPIO_voidSetPinValue(PORTA,3,1);
		delay(5000);
		MGPIO_voidSetPinValue(PORTA,2,1);
		delay(5000);

	}
}

