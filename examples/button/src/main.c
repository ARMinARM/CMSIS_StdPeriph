
/* Includes ------------------------------------------------------------------*/
#include <board.h>

/* Private function prototypes -----------------------------------------------*/
void Delay(uint32_t nCount);

static uint8_t lastButtonStatus = 0;

/* Private function ----------------------------------------------------------*/
int main(void)
{
    LEDS_Init();
    Buttons_Init();
    
    /* Infinite loop */
    while (1)
	{
		static uint32_t counter = 0;

		uint8_t currentButtonStatus = Button_Read();

		if (lastButtonStatus != currentButtonStatus && currentButtonStatus != 0) {
			++counter;
			LEDS_Off();
			LEDS_Set(LED[counter % 2]);
		}
		lastButtonStatus = currentButtonStatus;
    }			  
}


void  Delay (uint32_t nCount)
{
    for(; nCount != 0; nCount--);
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

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
