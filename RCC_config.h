/*********************************************************/
/* Author  : Mohamed Abdel Hamid                         */
/* Date    : 14 / 9 / 2023                               */
/* Version : V01                                         */
/*********************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H
/* ----------------OPTIONS CLOCK TYPE&AHB-------------- */

/* Options : RCC_HSI
			 RCC_HSE_CRYSTAL
             RCC_HSE_RC
             RCC_PLL
 	 	 	 	 	 	 	 */
#define CLOCK_TYPE 				RCC_HSI		/*CHOOSE HIGH SPEED INTERNAL*/

/* Options : AHB_PRESCALE_NOT_DIV
			 AHB_PRESCALE_2
			 AHB_PRESCALE_4
			 AHB_PRESCALE_8
			 AHB_PRESCALE_16
			 AHB_PRESCALE_64
			 AHB_PRESCALE_128
			 AHB_PRESCALE_256
			 AHB_PRESCALE_512
 	 	 	 	 	 	 	 	 */
#define AHB_PRESCALE 			AHB_PRESCALE_NOT_DIV

/* Options : APB2_PRESCALE_NOT_DIV
			 APB2_PRESCALE_2
			 APB2_PRESCALE_4
			 APB2_PRESCALE_8
			 APB2_PRESCALE_16
 	 	 	 	 	 	 	 	 */
#define APB2_PRESCALE			APB2_PRESCALE_NOT_DIV

/* Options : APB1_PRESCALE_NOT_DIV
			 APB1_PRESCALE_2
			 APB1_PRESCALE_4
			 APB1_PRESCALE_8
			 APB1_PRESCALE_16
 	 	 	 	 	 	 	 	 */
#define APB1_PRESCALE			APB1_PRESCALE_NOT_DIV
/*ALL APB1&APB2 HAVE THE SAME CLOCK*/
#endif
