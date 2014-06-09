/* Includes ------------------------------------------------------------------*/
#include <board.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void delay();

void delay(uint32_t ms) {
    ms *= 1440; // 3360=168MHz, 1440=72MHz
    while(ms--) {
        __NOP();
    }
}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	LEDS_Init();
	
	while (1)
	{
		static uint32_t counter = 0;
		++counter;
		
		LEDS_Off();
		
		LEDS_Set(LED[counter % 2]);
		
		delay(250);
	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
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
