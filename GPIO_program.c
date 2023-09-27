/*********************************************************/
/* Author  : Mohamed Abdel Hamid                         */
/* Date    : 14 / 9 / 2023                               */
/* Version : V01                                         */
/*********************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_priv.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Direction , u8 Copy_u8Mode){
	switch(Copy_u8PortId){
	case PORTA :
		if(Copy_u8PinId<8){
			Copy_u8PinId *= 4;
			GPIOA_CRL &= ~(0b1111<<Copy_u8PinId);		/*CLEAR PINid TO CARRY DATA*/
		    /* 1- set direction */
			GPIOA_CRL |= (Copy_u8Direction<<Copy_u8PinId) ;	/*to get Mode*/
			/* 2- Set Mode  */
			if(Copy_u8Direction == GPIOA_INPUT && (Copy_u8Mode == GPIOA_INPUT_PULLUP ||Copy_u8Mode == GPIOA_INPUT_PULLDOWN)){
				GPIOA_CRL |= (GPIOA_INPUT_PULLUP<<(Copy_u8PinId+2)) ;
			}
			else{
				GPIOA_CRL |= (Copy_u8Mode<<(Copy_u8PinId+2)) ;
			}

			/* Pull up / down */
			if(Copy_u8Mode == 0b10){
				if(Copy_u8Mode == GPIOA_INPUT_PULLUP){
					SET_BIT(GPIOA_ODR,(Copy_u8PinId/4));
				}
				else if(Copy_u8Mode == GPIOA_INPUT_PULLDOWN){
					CLR_BIT(GPIOA_ODR,(Copy_u8PinId/4));
				}
			}
		}
		else if(Copy_u8PinId>=8){
			Copy_u8PinId =(Copy_u8PinId-8) * 4;		/*to get offset 24*/
			GPIOA_CRL &= ~(0b1111<<Copy_u8PinId);
			/* 1- set direction */
		    GPIOA_CRH |= (Copy_u8Direction<<Copy_u8PinId) ;
		    /* 2- Set Mode  */
		    GPIOA_CRH |= (Copy_u8Mode<<(Copy_u8PinId+2)) ;

		    if(Copy_u8Direction == GPIOA_INPUT && (Copy_u8Mode == GPIOA_INPUT_PULLUP ||Copy_u8Mode == GPIOA_INPUT_PULLDOWN)){
   				GPIOA_CRH |= (GPIOA_INPUT_PULLUP<<(Copy_u8PinId+2)) ;
   			}
   			else{
   				GPIOA_CRH |= (Copy_u8Mode<<(Copy_u8PinId+2)) ;
   			}

		    /* Pull up / down */
			if(Copy_u8Mode == 0b10){
				if(Copy_u8Mode == GPIOA_INPUT_PULLUP){
					SET_BIT(GPIOA_ODR,((Copy_u8PinId/4)+8));
				}
				else if(Copy_u8Mode == GPIOA_INPUT_PULLUP){
					CLR_BIT(GPIOA_ODR,((Copy_u8PinId/4)+8));
				}
			}
		}
		break;
	}
}
void MGPIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal){
	CLR_BIT(GPIOA_ODR , Copy_u8PinId);	/*CLEAR OLD DATA*/
	GPIOA_ODR |= (Copy_u8PinVal<<Copy_u8PinId) ;
}
 u8 MGPIO_voidGetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId){
	u8 Loc_u8PinVal;

	Loc_u8PinVal = GET_BIT(GPIOA_ODR,Copy_u8PinId);

	return Loc_u8PinVal ;
}
