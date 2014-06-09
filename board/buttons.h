#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#ifdef __cplusplus
 extern "C" {
#endif

#define BUTTONPORT		GPIOA
#define BUTTONCLOCK		RCC_APB2Periph_GPIOA
#define USER_BUTTON		GPIO_Pin_0


void Buttons_Init(void);
void Buttons_Init_Interrupt(void);
uint8_t Button_Read(void);
void EXTI0_IRQHandler(void);

// init
void Buttons_Init(void)
{
	RCC_APB2PeriphClockCmd(BUTTONCLOCK, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin = USER_BUTTON;
    GPIO_Init(BUTTONPORT, &GPIO_InitStructure);	
}

uint8_t Button_Read(void)
{
	return GPIO_ReadInputDataBit(BUTTONPORT, USER_BUTTON);
}

void Buttons_Init_Interrupt(void)
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	GPIO_InitTypeDef   GPIO_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;
	
   /* Enable GPIOA clock */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
   /* Configure PA0 pin as input floating */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
   GPIO_Init(GPIOA, &GPIO_InitStructure);

   /* Enable alternative function(AFIO) clock */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

   /* Connect EXTI0 Line to PA0 pin */
   GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);

   /* Configure EXTI0 line */
   EXTI_InitStructure.EXTI_Line = EXTI_Line0;
   EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
   EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
   //EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
   EXTI_InitStructure.EXTI_LineCmd = ENABLE;
   EXTI_Init(&EXTI_InitStructure);

   /* Enable and set EXTI0 Interrupt to the lowest priority */
   /* (check "misc.h" priority table on line 79)*/
   NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 15;
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 15;
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
}

// Implement this function in your main.c (or wherever) that handles the interrupt
/*
void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)
	{
		//Clear EXTI0 interrupt pending bit
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}
*/


#ifdef __cplusplus
 }
#endif

#endif // _BUTTONS_H_
