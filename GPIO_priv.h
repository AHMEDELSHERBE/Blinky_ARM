/*********************************************************/
/* Author  : Mohamed Abdel Hamid                         */
/* Date    : 14 / 9 / 2023                               */
/* Version : V01                                         */
/*********************************************************/
#ifndef GPIO_PRIV_H
#define GPIO_PRIV_H

#define GPIOA_BASE_ADDRESS    0x40010800		/*GPIO FOR PORT A */

#define GPIOA_CRL             *((volatile u32*) (GPIOA_BASE_ADDRESS + 0x00))	/*CONTROL REGISTER LOW*/
#define GPIOA_CRH 			  *((volatile u32*) (GPIOA_BASE_ADDRESS + 0x04))	/*CONTROL REGISTER HIGH*/
#define GPIOA_IDR 			  *((volatile u32*) (GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR 			  *((volatile u32*) (GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSRR 			  *((volatile u32*) (GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR			  *((volatile u32*) (GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCKR		      *((volatile u32*) (GPIOA_BASE_ADDRESS + 0x18))
#endif
