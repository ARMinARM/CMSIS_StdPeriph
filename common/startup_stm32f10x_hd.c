//*****************************************************************************
//  @RT :%s/IntHandler/_IRQHandler/g
//  rn startup_coide startup_stm32f10x_hd.c
//
//! \file startup_coide.c
//! \brief STM32F1xx Devices Startup code for CooCox CoIDE.
//!        This module performs:
//!           - Set the initial SP
//!           - Set the vector table entries with the exceptions ISR address
//!           - Initialize data and bss
//!           - Setup the microcontroller system. 			
//!           - Call the application's entry point.
//!           .
//! \version V2.1.1.0
//! \date 5/24/2012
//! \author CooCox
//! \copy
//!
//! Copyright (c)  2011, CooCox 
//! All rights reserved.
//! 
//! Redistribution and use in source and binary forms, with or without 
//! modification, are permitted provided that the following conditions 
//! are met: 
//! 
//!     * Redistributions of source code must retain the above copyright 
//! notice, this list of conditions and the following disclaimer. 
//!     * Redistributions in binary form must reproduce the above copyright
//! notice, this list of conditions and the following disclaimer in the
//! documentation and/or other materials provided with the distribution. 
//!     * Neither the name of the <ORGANIZATION> nor the names of its 
//! contributors may be used to endorse or promote products derived 
//! from this software without specific prior written permission. 
//! 
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//! AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
//! IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//! ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
//! LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
//! SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//! INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
//! CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
//! ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
//! THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

//***************************************************************************** 
//
// Stack Configuration
//
//*****************************************************************************
//
// Stack size (in Words)
//
#define STACK_SIZE       0x00000100      
__attribute__ ((section(".co_stack")))
unsigned long pulStack[STACK_SIZE];      
 
#define WEAK __attribute__ ((weak))           

//*****************************************************************************
//
// Declaration of the default fault handlers
//
//*****************************************************************************
void WEAK  ResetHandler(void);
void WEAK  NMI_IRQHandler(void);
void WEAK  HardFault_IRQHandler(void);
void WEAK  MemManage_IRQHandler(void);
void WEAK  BusFault_IRQHandler(void);
void WEAK  UsageFault_IRQHandler(void);
void WEAK  SVC_IRQHandler(void);
void WEAK  DebugMon_IRQHandler(void);
void WEAK  PendSV_IRQHandler(void);
void WEAK  SysTick_IRQHandler(void);
void WEAK  WWDG_IRQHandler(void);  
void WEAK  PVD_IRQHandler(void);  
void WEAK  TAMPER_IRQHandler(void);
void WEAK  RTC_IRQHandler(void);
void WEAK  FLASH_IRQHandler(void); 
void WEAK  RCC_IRQHandler(void);
void WEAK  EXTI0_IRQHandler(void); 
void WEAK  EXTI1_IRQHandler(void); 
void WEAK  EXTI2_IRQHandler(void); 
void WEAK  EXTI3_IRQHandler(void); 
void WEAK  EXTI4_IRQHandler(void); 
void WEAK  DMA1Channel1_IRQHandler(void); 
void WEAK  DMA1Channel2_IRQHandler(void);
void WEAK  DMA1Channel3_IRQHandler(void);
void WEAK  DMA1Channel4_IRQHandler(void); 
void WEAK  DMA1Channel5_IRQHandler(void); 
void WEAK  DMA1Channel6_IRQHandler(void); 
void WEAK  DMA1Channel7_IRQHandler(void); 
void WEAK  ADC12_IRQHandler(void); 
void WEAK  CAN1TX_IRQHandler(void); 
void WEAK  CAN1RX0_IRQHandler(void); 
void WEAK  CAN1RX1_IRQHandler(void);  
void WEAK  CAN1SCE_IRQHandler(void);  
void WEAK  EXTI95_IRQHandler(void); 
void WEAK  TIM1BRKTIM9_IRQHandler(void);
void WEAK  TIM1UPTIM10_IRQHandler(void);
void WEAK  TIM1TRGCOMTIM11_IRQHandler(void);
void WEAK  TIM1CC_IRQHandler(void);
void WEAK  TIM2_IRQHandler(void);
void WEAK  TIM3_IRQHandler(void);
void WEAK  TIM4_IRQHandler(void);
void WEAK  I2C1EV_IRQHandler(void);
void WEAK  I2C1ER_IRQHandler(void);
void WEAK  I2C2EV_IRQHandler(void);
void WEAK  I2C2ER_IRQHandler(void);
void WEAK  SPI1_IRQHandler(void);
void WEAK  SPI2_IRQHandler(void);
void WEAK  USART1_IRQHandler(void);
void WEAK  USART2_IRQHandler(void);
void WEAK  USART3_IRQHandler(void);
void WEAK  EXTI1510_IRQHandler(void);
void WEAK  RTCAlarm_IRQHandler(void);
void WEAK  OTGFSWKUP_IRQHandler(void);
void WEAK  TIM8BRKTIM12_IRQHandler(void);
void WEAK  TIM8UPTIM13_IRQHandler(void);
void WEAK  TIM8TRGCOMTIM14_IRQHandler(void);
void WEAK  TIM8CC_IRQHandler(void);
void WEAK  ADC3_IRQHandler(void);
void WEAK  FSMC_IRQHandler(void);
void WEAK  SDIO_IRQHandler(void);
void WEAK  TIM5_IRQHandler(void);
void WEAK  SPI3_IRQHandler(void);
void WEAK  UART4_IRQHandler(void);
void WEAK  UART5_IRQHandler(void);
void WEAK  TIM6_IRQHandler(void);
void WEAK  TIM7_IRQHandler(void);
void WEAK  DMA2Channel1_IRQHandler(void);
void WEAK  DMA2Channel2_IRQHandler(void);
void WEAK  DMA2Channel3_IRQHandler(void);
void WEAK  DMA2Channel4_IRQHandler(void);
void WEAK  DMA2Channel5_IRQHandler(void);
void WEAK  ETH_IRQHandler(void);
void WEAK  ETHWKUP_IRQHandler(void);
void WEAK  CAN2TX_IRQHandler(void);
void WEAK  CAN2RX0_IRQHandler(void);
void WEAK  CAN2RX1_IRQHandler(void);
void WEAK  CAN2SCE_IRQHandler(void);
void WEAK  OTGFS_IRQHandler(void);


//*****************************************************************************
//
// Symbols defined in linker script
//
//*****************************************************************************
//
// Start address for the initialization values of the .data section.
//  
extern unsigned long _sidata;    

//
// Start address for the .data section 
//
extern unsigned long _sdata;     

//
// End address for the .data section
//
extern unsigned long _edata;     

//
// Start address for the .bss section
//
extern unsigned long _sbss;      

//
// End address for the .bss section
//
extern unsigned long _ebss;      

//
// End address for ram 
//
extern void _eram;               

//*****************************************************************************
//
// Function prototypes
//
//*****************************************************************************
extern int main(void);            
void ResetHandler(void);   
static void Default_IRQHandler(void);  

//
// The minimal vector table for a Cortex M3.  Note that the proper constructs
// must be placed on this to ensure that it ends up at physical address
// 0x00000000.
//  
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
    (void *)&pulStack[STACK_SIZE],          // The initial stack pointer     
    ResetHandler,                           // The reset handler                        
    NMI_IRQHandler,                          // The NMI handler                        
    HardFault_IRQHandler,                    // The hard fault handler                  
    MemManage_IRQHandler,                    // The MPU fault handler                  
    BusFault_IRQHandler,                     // The bus fault handler                   
    UsageFault_IRQHandler,                   // The usage fault handler                  
    0,0,0,0,                                // Reserved                            
    SVC_IRQHandler,                          // SVCall handler                         
    DebugMon_IRQHandler,                     // Debug monitor handler                    
    0,                                      // Reserved                                  
    PendSV_IRQHandler,                       // The PendSV handler                      
    SysTick_IRQHandler,                      // The SysTick handler                    
    WWDG_IRQHandler,                         // 0 Window Watchdog interrupt
    PVD_IRQHandler,                          // 1 PVD through EXTI Line detection  
    TAMPER_IRQHandler,                       // 2 Tamper interrupt 
    RTC_IRQHandler,                          // 3 RTC global interrupt
    FLASH_IRQHandler,                        // 4 Flash global interrupt
    RCC_IRQHandler,                          // 5 RCC global interrupt
    EXTI0_IRQHandler,                        // 6 EXTI Line0 interrupt
    EXTI1_IRQHandler,                        // 7 EXTI Line1 interrupt 
    EXTI2_IRQHandler,                        // 8 EXTI Line2 interrupt
    EXTI3_IRQHandler,                        // 9 EXTI Line3 interrupt
    EXTI4_IRQHandler,                        // 10 EXTI Line4 interrupt
    DMA1Channel1_IRQHandler,                 // 11 DMA1 Channel1 global interrupt
    DMA1Channel2_IRQHandler,                 // 12 DMA1 Channel2 global interrupt
    DMA1Channel3_IRQHandler,                 // 13 DMA1 Channel3 global interrupt
    DMA1Channel4_IRQHandler,                 // 14 DMA1 Channel4 global interrupt
    DMA1Channel5_IRQHandler,                 // 15 DMA1 Channel5 global interrupt
    DMA1Channel6_IRQHandler,                 // 16 DMA1 Channel6 global interrupt
    DMA1Channel7_IRQHandler,                 // 17 DMA1 Channel7 global interrupt
    ADC12_IRQHandler,                        // 18 ADC1 and ADC2 global interrupt
    CAN1TX_IRQHandler,                       // 19 CAN1 TX interrupts
    CAN1RX0_IRQHandler,                      // 20 CAN1 RX0 interrupts
    CAN1RX1_IRQHandler,                      // 21 CAN1 RX1 interrupt
    CAN1SCE_IRQHandler,                      // 22 CAN1 SCE interrupt 
    EXTI95_IRQHandler,                       // 23 EXTI Line[9:5] interrupts 
    TIM1BRKTIM9_IRQHandler,                  // 24 TIM1 Break interrupt
    TIM1UPTIM10_IRQHandler,                  // 25 TIM1 Update interrupt
    TIM1TRGCOMTIM11_IRQHandler,              // 26 TIM1 Trigger and Commutation
    TIM1CC_IRQHandler,                       // 27 TIM1 Capture Compare interrupt
    TIM2_IRQHandler,                         // 28 TIM2 global interrupt
    TIM3_IRQHandler,                         // 29 TIM3 global interrupt
    TIM4_IRQHandler,                         // 30 TIM4 global interrupt
    I2C1EV_IRQHandler,                       // 31 I2C1 event interrupt
    I2C1ER_IRQHandler,                       // 32 I2C1 error interrupt
    I2C2EV_IRQHandler,                       // 33 I2C2 event interrupt
    I2C2ER_IRQHandler,                       // 34 I2C2 error interrupt
    SPI1_IRQHandler,                         // 35 SPI1 global interrupt
    SPI2_IRQHandler,                         // 36 SPI2 global interrupt
    USART1_IRQHandler,                       // 37 USART1 global interrupt
    USART2_IRQHandler,                       // 38 USART2 global interrupt
    USART3_IRQHandler,                       // 39 USART3 global interrupt
    EXTI1510_IRQHandler,                     // 40 EXTI Line[15:10] interrupts
    RTCAlarm_IRQHandler,                     // 41 RTC alarm through EXTI line
    OTGFSWKUP_IRQHandler,                    // 42 USB On-The-Go FS Wakeup
    TIM8BRKTIM12_IRQHandler,                 // 43 TIM8 Break interrupt
    TIM8UPTIM13_IRQHandler,                  // 44 TIM8 Update interrupt
    TIM8TRGCOMTIM14_IRQHandler,              // 45 TIM8 Trigger and Commutation
    TIM8CC_IRQHandler,                       // 46 TIM8 Capture Compare interrupt
    ADC3_IRQHandler,                         // 47 ADC3 global interrupt
    FSMC_IRQHandler,                         // 48 FSMC global interrupt
    SDIO_IRQHandler,                         // 49 SDIO global interrupt
    TIM5_IRQHandler,                         // 50 TIM5 global interrupt
    SPI3_IRQHandler,                         // 51 SPI3 global interrupt
    UART4_IRQHandler,                        // 52 UART4 global interrupt
    UART5_IRQHandler,                        // 53 UART5 global interrupt
    TIM6_IRQHandler,                         // 54 TIM6 global interrupt
    TIM7_IRQHandler,                         // 55 TIM7 global interrupt
    DMA2Channel1_IRQHandler,                 // 56 DMA2 Channel1 global interrupt
    DMA2Channel2_IRQHandler,                 // 57 DMA2 Channel2 global interrupt
    DMA2Channel3_IRQHandler,                 // 58 DMA2 Channel3 global interrupt
    DMA2Channel4_IRQHandler,                 // 59 DMA2 Channel4 global interrupt
    DMA2Channel5_IRQHandler,                 // 60 DMA2 Channel5 global interrupt
    ETH_IRQHandler,                          // 61 Ethernet global interrupt
    ETHWKUP_IRQHandler,                      // 62 Ethernet Wakeup through EXTI line
    CAN2TX_IRQHandler,                       // 63 CAN2 TX interrupts
    CAN2RX0_IRQHandler,                      // 64 CAN2 RX0 interrupts
    CAN2RX1_IRQHandler,                      // 65 CAN2 RX1 interrupt
    CAN2SCE_IRQHandler,                      // 66 CAN2 SCE interrupt
    OTGFS_IRQHandler,                        // 67 USB On The Go FS global interrupt
    (void *)0xF108F85F                      // Boot in RAM mode 
};

//*****************************************************************************
//
//! \brief This is the code that gets called when the processor first
//! starts execution following a reset event. 
//!
//! \param None.
//!
//! Only the absolutely necessary set is performed, after which the 
//! application supplied main() routine is called. 
//!
//! \return None.
//
//*****************************************************************************
void Default_ResetHandler(void)
{
    //
    // Initialize data and bss
    //
    unsigned long *pulSrc, *pulDest;

    //
    // Copy the data segment initializers from flash to SRAM
    //
    pulSrc = &_sidata;

    for(pulDest = &_sdata; pulDest < &_edata; )
    {
        *(pulDest++) = *(pulSrc++);
    }

    //
    // Zero fill the bss segment.
    //
    for(pulDest = &_sbss; pulDest < &_ebss; )
    {
        *(pulDest++) = 0;
    }

    //
    // Call the application's entry point.
    //
    main();
}

//*****************************************************************************
//
// Provide weak aliases for each Exception handler to the Default_IRQHandler. 
// As they are weak aliases, any function with the same name will override 
// this definition.
//
//*****************************************************************************  
#pragma weak ResetHandler = Default_ResetHandler
#pragma weak NMI_IRQHandler = Default_IRQHandler
#pragma weak HardFault_IRQHandler = Default_IRQHandler
#pragma weak MemManage_IRQHandler = Default_IRQHandler
#pragma weak BusFault_IRQHandler = Default_IRQHandler
#pragma weak UsageFault_IRQHandler = Default_IRQHandler
#pragma weak SVC_IRQHandler = Default_IRQHandler
#pragma weak DebugMon_IRQHandler = Default_IRQHandler
#pragma weak PendSV_IRQHandler = Default_IRQHandler
#pragma weak SysTick_IRQHandler = Default_IRQHandler
#pragma weak WWDG_IRQHandler = Default_IRQHandler  
#pragma weak PVD_IRQHandler = Default_IRQHandler  
#pragma weak TAMPER_IRQHandler = Default_IRQHandler
#pragma weak RTC_IRQHandler = Default_IRQHandler
#pragma weak FLASH_IRQHandler = Default_IRQHandler 
#pragma weak RCC_IRQHandler = Default_IRQHandler
#pragma weak EXTI0_IRQHandler = Default_IRQHandler 
#pragma weak EXTI1_IRQHandler = Default_IRQHandler 
#pragma weak EXTI2_IRQHandler = Default_IRQHandler 
#pragma weak EXTI3_IRQHandler = Default_IRQHandler 
#pragma weak EXTI4_IRQHandler = Default_IRQHandler 
#pragma weak DMA1Channel1_IRQHandler = Default_IRQHandler 
#pragma weak DMA1Channel2_IRQHandler = Default_IRQHandler
#pragma weak DMA1Channel3_IRQHandler = Default_IRQHandler
#pragma weak DMA1Channel4_IRQHandler = Default_IRQHandler 
#pragma weak DMA1Channel5_IRQHandler = Default_IRQHandler 
#pragma weak DMA1Channel6_IRQHandler = Default_IRQHandler 
#pragma weak DMA1Channel7_IRQHandler = Default_IRQHandler 
#pragma weak ADC12_IRQHandler = Default_IRQHandler 
#pragma weak CAN1TX_IRQHandler = Default_IRQHandler 
#pragma weak CAN1RX0_IRQHandler = Default_IRQHandler 
#pragma weak CAN1RX1_IRQHandler = Default_IRQHandler  
#pragma weak CAN1SCE_IRQHandler = Default_IRQHandler  
#pragma weak EXTI95_IRQHandler = Default_IRQHandler 
#pragma weak TIM1BRKTIM9_IRQHandler = Default_IRQHandler
#pragma weak TIM1UPTIM10_IRQHandler = Default_IRQHandler
#pragma weak TIM1TRGCOMTIM11_IRQHandler = Default_IRQHandler
#pragma weak TIM1CC_IRQHandler = Default_IRQHandler
#pragma weak TIM2_IRQHandler = Default_IRQHandler  
#pragma weak TIM3_IRQHandler = Default_IRQHandler 
#pragma weak TIM4_IRQHandler = Default_IRQHandler 
#pragma weak I2C1EV_IRQHandler = Default_IRQHandler 
#pragma weak I2C1ER_IRQHandler = Default_IRQHandler 
#pragma weak I2C2EV_IRQHandler = Default_IRQHandler 
#pragma weak I2C2ER_IRQHandler = Default_IRQHandler 
#pragma weak SPI1_IRQHandler = Default_IRQHandler 
#pragma weak SPI2_IRQHandler = Default_IRQHandler 
#pragma weak USART1_IRQHandler = Default_IRQHandler 
#pragma weak USART2_IRQHandler = Default_IRQHandler 
#pragma weak USART3_IRQHandler = Default_IRQHandler 
#pragma weak EXTI1510_IRQHandler = Default_IRQHandler 
#pragma weak RTCAlarm_IRQHandler = Default_IRQHandler 
#pragma weak OTGFSWKUP_IRQHandler = Default_IRQHandler
#pragma weak TIM8BRKTIM12_IRQHandler = Default_IRQHandler
#pragma weak TIM8UPTIM13_IRQHandler = Default_IRQHandler
#pragma weak TIM8TRGCOMTIM14_IRQHandler = Default_IRQHandler
#pragma weak TIM8CC_IRQHandler = Default_IRQHandler
#pragma weak ADC3_IRQHandler = Default_IRQHandler
#pragma weak FSMC_IRQHandler = Default_IRQHandler
#pragma weak SDIO_IRQHandler = Default_IRQHandler
#pragma weak TIM5_IRQHandler = Default_IRQHandler 
#pragma weak SPI3_IRQHandler = Default_IRQHandler 
#pragma weak UART4_IRQHandler = Default_IRQHandler 
#pragma weak UART5_IRQHandler = Default_IRQHandler 
#pragma weak TIM6_IRQHandler = Default_IRQHandler 
#pragma weak TIM7_IRQHandler = Default_IRQHandler 
#pragma weak DMA2Channel1_IRQHandler = Default_IRQHandler 
#pragma weak DMA2Channel2_IRQHandler = Default_IRQHandler 
#pragma weak DMA2Channel3_IRQHandler = Default_IRQHandler 
#pragma weak DMA2Channel4_IRQHandler = Default_IRQHandler 
#pragma weak DMA2Channel5_IRQHandler = Default_IRQHandler 
#pragma weak ETH_IRQHandler = Default_IRQHandler 
#pragma weak ETHWKUP_IRQHandler = Default_IRQHandler 
#pragma weak CAN2TX_IRQHandler = Default_IRQHandler 
#pragma weak CAN2RX0_IRQHandler = Default_IRQHandler 
#pragma weak CAN2RX1_IRQHandler = Default_IRQHandler 
#pragma weak CAN2SCE_IRQHandler = Default_IRQHandler 
#pragma weak OTGFS_IRQHandler = Default_IRQHandler 
  

//*****************************************************************************
//
//! \brief This is the code that gets called when the processor receives an 
//! unexpected interrupt.  
//!
//! \param None.
//!
//! This simply enters an infinite loop, preserving the system state for 
//! examination by a debugger.
//!
//! \return None.  
//*****************************************************************************  
static void Default_IRQHandler(void) 
{
    //
    // Go into an infinite loop.
    //
    while (1) 
    {
    }
}


