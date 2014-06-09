#include <board.h>

//#include <stm32f10x_usart.h> // under Libraries/STM32F4xx_StdPeriph_Driver/inc and src
//#include "main.h"

#define MAX_STRLEN 8 // this is the maximum string length of our string in characters
volatile char received_string[MAX_STRLEN+1]; // this will hold the recieved string

void Delay(__IO uint32_t nCount) {
  while(nCount--) {
  }
}


int main(void) {
  
  USART1_Init(9600, 1); // initialize USART1 @ 9600 baud, 1=use interrupts

  USART1_Print("Init\r\n"); // just send a message to indicate that it works

  while (1){
	  
  }
}

// this is the interrupt request handler (IRQ) for ALL USART1 interrupts
void USART1_IRQHandler(void){
	//USART_puts(USART1, "interrupt!\r\n");
	USART1_Print("interrupt!\r\n");
	
	// check if the USART1 receive interrupt flag was set
	if( USART_GetITStatus(USART1, USART_IT_RXNE) ){
		
		static uint8_t cnt = 0; // this counter is used to determine the string length
		char t = USART1->DR; // the character from the USART1 data register is saved in t
		
		/* check if the received character is not the LF character (used to determine end of string) 
		 * or the if the maximum string length has been been reached 
		 */
		if( (t != '\n') && (cnt < MAX_STRLEN) ){ 
			received_string[cnt] = t;
			cnt++;
		}
		else{ // otherwise reset the character counter and print the received string
			cnt = 0;
			USART1_Print(received_string);
		}
	}
}
