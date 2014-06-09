#ifndef _LEDS_H_
#define _LEDS_H_

#ifdef __cplusplus
 extern "C" {
#endif

#define LEDPORT		GPIOB
#define LEDCLOCK	RCC_APB2Periph_GPIOB

#define LED1	GPIO_Pin_0
#define LED2	GPIO_Pin_1


void LEDS_Init(void);
void LEDS_Toggle(uint16_t led);
void LEDS_Set(uint16_t in);
void LEDS_On(void);
void LEDS_Off(void);
void LED1_On(void);
void LED1_Off(void);
void LED2_On(void);
void LED2_Off(void);


const uint16_t LEDS = LED1 | LED2;
const uint16_t LED[2] = { LED1, LED2 };

// init
void LEDS_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* GPIOC Periph clock enable */
	RCC_APB2PeriphClockCmd(LEDCLOCK, ENABLE);
	
	/* Configure LED pins in output pushpull mode */
	GPIO_InitStructure.GPIO_Pin = LEDS;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(LEDPORT, &GPIO_InitStructure);
}

// generic
void LEDS_Toggle(uint16_t led)
{
	LEDPORT->ODR ^= led;
}

void LEDS_Set(uint16_t in)
{
	LEDPORT->BSRR = in;
}

void LEDS_On(void)
{
	LEDPORT->BSRR  = LEDS;
}

void LEDS_Off(void)
{
	LEDPORT->BRR  = LEDS;
}

// LED1
void LED1_On(void)
{
	LEDPORT->BSRR  = LED1;
}

void LED1_Off(void)
{
	LEDPORT->BRR  = LED1;
}

// LED2
void LED2_On(void)
{
	LEDPORT->BSRR  = LED2;
}

void LED2_Off(void)
{
	LEDPORT->BRR  = LED2;
}

#ifdef __cplusplus
 }
#endif

#endif // _LEDS_H_
