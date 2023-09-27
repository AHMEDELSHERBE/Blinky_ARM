/*********************************************************/
/* Author  : SHERBO                         */
/* Date    : 14 / 9 / 2023                               */
/* Version : V01                                         */
/*********************************************************/
/* Standard Lib */
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
/* Lower Layers */

/* Peripheral */
#include "RCC_interface.h"
#include "../include/RCC_config.h"
#include "RCC_priv.h"
/*
 * CHOOSE CLOCKTYPE(HSI-HSE-PLL)
 * AHP &APB1&APB2 ---------BIT
 * BUSES IF D OR E FROM---------INTERFACE-------
 */
void MRCC_voidInit(){

	/* 1- Determine clock type */
	switch(CLOCK_TYPE){

	case RCC_HSI 		 :SET_BIT(RCC_CR,0) ;   /* Enable HSI */
						   RCC_CFGR = 0 ;          /* Set as Sys Clk */
						   break;

	case RCC_HSE_CRYSTAL : SET_BIT(RCC_CR,16); 		  /* Enable HSE */
						   CLR_BIT(RCC_CR,18);		  /* Disable Bypass */
						   RCC_CFGR = 0b01 ;		  /* Set as Sys Clk */
						   break;

	case RCC_HSE_RC      : SET_BIT(RCC_CR,16); 		  /* Enable HSE */
	                       SET_BIT(RCC_CR,18);		  /* ENABLE Bypass */
	                       RCC_CFGR = 0b01 ;          /* Set as Sys Clk */
	                       break;

	}

	/* 2- Determine Buses Prescale */
	RCC_CFGR |= (AHB_PRESCALE<<4);
	RCC_CFGR |= (APB2_PRESCALE<<11);
	RCC_CFGR |= (APB1_PRESCALE<<8);
}

void MRCC_voidEnablePeripheral(u8 Copy_u8BusId , u8 Copy_u8PerId){
	switch(Copy_u8BusId){
	case RCC_BUS_AHB  : SET_BIT(RCC_AHBENR ,Copy_u8PerId); break ;
	case RCC_BUS_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerId); break ;
	case RCC_BUS_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerId); break ;
	}
}
void MRCC_voidDisablePeripheral(u8 Copy_u8BusId , u8 Copy_u8PerId){
	switch(Copy_u8BusId){
	case RCC_BUS_AHB  : CLR_BIT(RCC_AHBENR ,Copy_u8PerId); break ;
	case RCC_BUS_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerId); break ;
	case RCC_BUS_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerId); break ;
	}
}
