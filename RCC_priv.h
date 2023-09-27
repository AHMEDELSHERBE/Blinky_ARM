/*********************************************************/
/* Author  : Sherbo                         */
/* Date    : 14 / 9 / 2023                               */
/* Version : V01                                         */
/*********************************************************/
#ifndef RCC_PRIV_H
#define RCC_PRIV_H

/* ---------------- Definition for Registers-------------- */
#define RCC_BASE_ADDRESS    0x40021000

#define RCC_CR              *((volatile u32*) (RCC_BASE_ADDRESS + 0x00)) 	/*Clock control register*/
#define RCC_CFGR            *((volatile u32*) (RCC_BASE_ADDRESS + 0x04))	/*Clock configuration register*/
#define RCC_CIR             *((volatile u32*) (RCC_BASE_ADDRESS + 0x08))		/*Clock interrupt register*/
#define RCC_APB2RSTR        *((volatile u32*) (RCC_BASE_ADDRESS + 0x0C))		/*peripheral reset register*/
#define RCC_APB1RSTR        *((volatile u32*) (RCC_BASE_ADDRESS + 0x10))
#define RCC_AHBENR          *((volatile u32*) (RCC_BASE_ADDRESS + 0x14))
#define RCC_APB2ENR         *((volatile u32*) (RCC_BASE_ADDRESS + 0x18))	/*ENABLE FOR APB*/
#define RCC_APB1ENR         *((volatile u32*) (RCC_BASE_ADDRESS + 0x1C))
#define RCC_BDCR            *((volatile u32*) (RCC_BASE_ADDRESS + 0x20/*OFFSET*/))
#define RCC_CSR             *((volatile u32*) (RCC_BASE_ADDRESS + 0x24))



/* Options for Clock type */
#define RCC_HSI				0		/*HIGH SPEED INTERNAL*/
#define RCC_HSE_CRYSTAL		1		/*HIGH SPEED EXTERNAL WITH CRYSTAL OCILATORS*/
#define RCC_HSE_RC		    2		/*HIGH SPEED EXTERNAL WITH RC-CICUIT*/
#define RCC_PLL				3		/*PHASE LOCKED LOOP*/


/* Options for AHB Prescale */
#define AHB_PRESCALE_NOT_DIV     0b0000
#define AHB_PRESCALE_2      	 0b1000
#define AHB_PRESCALE_4      	 0b1001
#define AHB_PRESCALE_8      	 0b1010
#define AHB_PRESCALE_16     	 0b1011
#define AHB_PRESCALE_64     	 0b1100
#define AHB_PRESCALE_128    	 0b1101
#define AHB_PRESCALE_256         0b1110
#define AHB_PRESCALE_512    	 0b1111

/* Options for APB2 */
#define APB2_PRESCALE_NOT_DIV	 0b000
#define APB2_PRESCALE_2      	 0b100
#define APB2_PRESCALE_4          0b101
#define APB2_PRESCALE_8          0b110
#define APB2_PRESCALE_16     	 0b111

/* Options for APB1 */
#define APB1_PRESCALE_NOT_DIV	 0b000
#define APB1_PRESCALE_2      	 0b100
#define APB1_PRESCALE_4          0b101
#define APB1_PRESCALE_8          0b110
#define APB1_PRESCALE_16     	 0b111
#endif
