
/* Includes ------------------------------------------------------------------*/
#include <board.h>

/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
void Delay(uint32_t nCount);


/* Private function ----------------------------------------------------------*/
int main(void)
{
	LEDS_Init();
	
	USART1_Init(9600, 0);
	USART1_Print("Init\r\n");

    /* Configure PA0 in interrupt mode */
    Buttons_Init_Interrupt();

    /* Generate software interrupt on EXTI0 line */
    //EXTI_GenerateSWInterrupt(EXTI_Line0);
    
    /* Infinite loop */
    while(1)
	{		
    }
}


void Delay(uint32_t nCount)
{
   for(; nCount != 0; nCount--);
}


void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		//Clear EXTI0 interrupt pending bit
		EXTI_ClearITPendingBit(EXTI_Line0);

		USART1_Print("Interrupt\r\n");
		
		
		static uint32_t counter = 0;
		++counter;
		LEDS_Off();
		LEDS_Set(LED[counter % 2]);
	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
