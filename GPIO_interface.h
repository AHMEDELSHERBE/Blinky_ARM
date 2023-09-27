/*********************************************************/
/* Author  : Mohamed Abdel Hamid                         */
/* Date    : 14 / 9 / 2023                               */
/* Version : V01                                         */
/*********************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
#include "STD_TYPES.h"
void MGPIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Direction , u8 Copy_u8Mode);
void MGPIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8PinVal);
u8   MGPIO_voidGetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId);	/*read val*/

/* Ports */
#define PORTA 0

/* Directions */
#define GPIOA_INPUT            0
#define GPIOA_OUTPUT_10MHZ     1
#define GPIOA_OUTPUT_2MHZ      2
#define GPIOA_OUTPUT_50MHZ     3

/* MODES */

#define GPIOA_INPUT_ANALOG       0
#define GPIOA_INPUT_FLOATING     1
#define GPIOA_INPUT_PULLUP       2
#define GPIOA_INPUT_PULLDOWN     3

#define GPIOA_OUTPUT_PUSH_PULL       0
#define GPIOA_OUTPUT_OPEN_DRAIN      1
#define GPIOA_OUTPUT_AF_PUSH_PULL    2
#define GPIOA_OUTPUT_AF_OPEN_DRAIN   3
#endif
