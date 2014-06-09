#ifndef _USART_H_
#define _USART_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_usart.h"

/* Function prototypes -------------------------------------------------------*/
void USART1_Puts(volatile char *s);
void USART1_Putch(volatile char ch);
void USART1_Print(volatile char s[]);
void USART1_Print_Int(int number);
void USART1_Init(uint32_t baudrate, uint8_t interrupt);

/* Function definitions ------------------------------------------------------*/
//void USART_Puts(USART_TypeDef* USARTx, volatile char *s)
void USART1_Puts(volatile char *s)
{
	while(*s) {
		// wait until data register is empty
		while( !(USART1->SR & 0x00000040) ); 
		USART_SendData(USART1, *s);
		*s++;
	}
}


void USART1_Putch(volatile char ch)
{
	USART_SendData( USART1, ch);

	// Wait until the end of transmision
	while( USART_GetFlagStatus( USART1, USART_FLAG_TC) == RESET) {}
}


void USART1_Print(volatile char s[])
{
    int i=0;
    
    while( i < 64) {
	    if( s[i] == '\0') break;
        USART1_Putch( s[i++]);
    }
}


void USART1_Print_Int(int number)
{
	unsigned char s[5], i=1, j=0;

    if( number < 0) { 
    	USART1_Putch( '-');
		number = -number;
	}	
 
    while( number >= 10) {
	    s[i++] = number % 10;
	    number /= 10;
    }
    s[i] = number;
    j = i;
    for( i=j; i>0; i--) USART1_Putch( '0' + s[i]);
}


//======================================================================

/* This funcion initializes the USART1 peripheral
 * 
 * Arguments: baudrate --> the baudrate at which the USART is 
 * 						   supposed to operate
 *            interrupt --> 1 (yes) or 0 (no RX interrupts)
 */
void USART1_Init(uint32_t baudrate, uint8_t interrupt)
{	
	GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);

    // PA9 is TX , PA10 is RX
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    
    USART_InitStructure.USART_BaudRate = baudrate;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    USART_Init(USART1, &USART_InitStructure);

    if (interrupt) {
		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // enable RX interrupts
		//USART_ITConfig(USART1, USART_IT_TXE, ENABLE);

		NVIC_InitTypeDef NVIC_InitStructure; // this is used to configure the NVIC (nested vector interrupt controller)

		NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		 // we want to configure the USART1 interrupts
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART1 interrupts
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART1 interrupts are globally enabled
		NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff
	}

	USART_Cmd(USART1, ENABLE);
}

#ifdef __cplusplus
 }
#endif

#endif // _USART_H_