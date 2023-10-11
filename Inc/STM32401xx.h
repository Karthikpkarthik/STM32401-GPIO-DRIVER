/*
 * STM32401xx.h
 *
 *  Created on: Oct 11, 2023
 *      Author: karth
 */

#ifndef INC_STM32401XX_H_
#define INC_STM32401XX_H_
#include <stdio.h>
#define __VO           volatile
#define MAIN_MEMORY    0x08000000U  //flash base address
#define SYSTEM_MEMORY  0x1FFF0000U //ROM base address
#define SRAM           0x20000000U //SRAM base address

// Peripheral bus base address
#define APB1_BASE      0x40000000U//apb1bus base address & starting address of peripheral
#define APB2_BASE      0x40010000U //apb2 bus base address
#define AHB1_BASE      0x40020000U//ahb1 bus base address
#define AHB2_BASE      0x50000000U//ahb2 bus base address

//address of peripherals on AHB1 bus.GPIOx,RCC
#define GPIOA_BASE     (AHB1_BASE+0x0000)//GPIOx base address
#define GPIOB_BASE     (AHB1_BASE+0x0400)
#define GPIOC_BASE     (AHB1_BASE+0x0800)
#define GPIOD_BASE     (AHB1_BASE+0x0C00)
#define GPIOE_BASE     (AHB1_BASE+0x1000)
#define GPIOH_BASE     (AHB1_BASE+0x1C00)
#define RCC_BASE       (AHB1_BASE+0x3800)//reset and clock control register

// Address of peripherals on APB2 bus.

#define TIM1_BASE      (APB2_BASE+0X0000)
#define USART1_BASE    (APB2_BASE+0X1000)
#define USART6_BASE    (APB2_BASE+0X1400)
#define ADC1_BASE      (APB2_BASE+0X2000)
#define SPI1_BASE      (APB2_BASE+0X3000)
#define SPI4_BASE      (APB2_BASE+0X3400)
#define EXTI_BASE      (APB2_BASE+0X3C00)
#define TIM9_BASE      (APB2_BASE+0X4000)
#define TIM10_BASE     (APB2_BASE+0X4400)
#define TIM11_BASE     (APB2_BASE+0X4800)

//ADDRESS of peripherals on APB1 bus.
#define TIM2_BASE 	   (APB1_BASE+0X0000)
#define	TIM3_BASE	   (APB1_BASE+0X0400)
#define	TIM4_BASE	   (APB1_BASE+0X0800)
#define	TIM5_BASE	   (APB1_BASE+0X0C00)
#define	RTC_BASE	   (APB1_BASE+0X2800)
#define	WWDG_BASE	   (APB1_BASE+0X2C00)
#define	USART2_BASE    (APB1_BASE+0X4400)
#define	I2C1_BASE	   (APB1_BASE+0X5400)
#define	I2C2_BASE	   (APB1_BASE+0X5800)
#define	I2C3_BASE 	   (APB1_BASE+0X5C00)
#define PWR_BASE       (APB1_BASE+0X7000)

// peripheral definition type casted to the (GPIO_REG_DEF*)
#define GPIOA          ((GPIO_REG_DEF*)GPIOA_BASE)
#define GPIOB          ((GPIO_REG_DEF*)GPIOB_BASE)
#define GPIOC  		   ((GPIO_REG_DEF*)GPIOC_BASE)
#define GPIOD    	   ((GPIO_REG_DEF*)GPIOD_BASE)
#define GPIOE  		   ((GPIO_REG_DEF*)GPIOE_BASE)
#define GPIOH  		   ((GPIO_REG_DEF*)GPIOH_BASE)
//GPIOX registers definition
typedef struct {
	__VO uint32_t  MODER;//mode register offset =0x00
	__VO uint32_t  OTYPER;//output type register offset=0x04
	__VO uint32_t  OSPEEDR;//output speed register offset=0x08
	__VO uint32_t  PUPDR;//pull-up/pull-down register offset=0x0C
	__VO uint32_t  IDR;//input data register offset=0x10
	__VO uint32_t  ODR;// output data register offset =0x14
	__VO uint32_t  BSRR;//bit set/reset register offset=0x18
	__VO uint32_t  LCKR;//configuration lock register offset=0x1C
	__VO uint32_t  AFR[2];//alternate function low register offset:0x20 and alternate function high register offset:0x24
}GPIO_REG_DEF;
GPIO_REG_DEF *pGPIOA =GPIOA;
GPIO_REG_DEF *pGPIOB =GPIOB;
GPIO_REG_DEF *pGPIOC =GPIOC;
GPIO_REG_DEF *pGPIOD =GPIOD;
GPIO_REG_DEF *pGPIOE =GPIOE;
GPIO_REG_DEF *pGPIOH =GPIOH;

//reset and clock control type casting to RCC_REG_DEF*
#define RCC ((RCC_REG_DEF*)RCC_BASE)

//Rest and clock control register definition
typedef  struct {
	__VO uint32_t RCC_CR;
	__VO uint32_t RCC_PLLCFGR;
	__VO uint32_t RCC_CFGR;
	__VO uint32_t RCC_CIR;
	__VO uint32_t RCC_AHB1RSTR;
	__VO uint32_t RCC_AHB2RSTR;
	__VO const uint32_t RESERVED0[2];
	__VO uint32_t RCC_APB1RSTR;
	__VO uint32_t RCC_APB2RSTR;
	__VO const  uint32_t RESERVED1[2];
	__VO uint32_t RCC_AHB1ENR;//AHB1 enable register offset:0x30
	__VO uint32_t RCC_AHB2ENR;//AHB2 enable register offset:0x34
	__VO const uint32_t RESERVED2[2];
}RCC_REG_DEF;
RCC_REG_DEF *pRCC= RCC;

//Enable functions for GPOIx peripheral clocks
#define GPIOA_PCLK_EN() RCC->RCC_AHB1ENR |=(1<<0)
#define GPIOB_PCLK_EN() RCC->RCC_AHB1ENR |=(1<<1)
#define GPIOC_PCLK_EN() RCC->RCC_AHB1ENR |=(1<<2)
#define GPIOD_PCLK_EN() RCC->RCC_AHB1ENR |=(1<<3)
#define GPIOE_PCLK_EN() RCC->RCC_AHB1ENR |=(1<<4)
#define GPIOH_PCLK_EN() RCC->RCC_AHB1ENR |=(1<<7)

//disable function for GPIOX peripheral clocks
#define GPIOA_PCLK_DI() RCC->RCC_AHB1ENR &= ~(1<<0)
#define GPIOB_PCLK_DI() RCC->RCC_AHB1ENR &= ~(1<<1)
#define GPIOC_PCLK_DI() RCC->RCC_AHB1ENR &= ~(1<<2)
#define GPIOD_PCLK_DI() RCC->RCC_AHB1ENR &= ~(1<<3)
#define GPIOE_PCLK_DI() RCC->RCC_AHB1ENR &= ~(1<<4)
#define GPIOH_PCLK_DI() RCC->RCC_AHB1ENR &= ~(1<<7)

//general macros
#define ENABLE  1
#define DISABLE 0
#define SET    ENABLE
#define REST   DISABLE
#define GPIO_PIN_SET   SET
#define GPIO_PIN_RESET RESET
//RCC AHB1 peripheral reset register (RCC_AHB1RSTR)
#define GPIOA_REG_RESET() do{(RCC->RCC_AHB1RSTR |=(1<<0)); (RCC->RCC_AHB1RSTR &=~(1<<0));}while(0)
#define GPIOB_REG_RESET() do{(RCC->RCC_AHB1RSTR |=(1<<1)); (RCC->RCC_AHB1RSTR &=~(1<<1));}while(0)
#define GPIOC_REG_RESET() do{(RCC->RCC_AHB1RSTR |=(1<<2)); (RCC->RCC_AHB1RSTR &=~(1<<2));}while(0)
#define GPIOD_REG_RESET() do{(RCC->RCC_AHB1RSTR |=(1<<3)); (RCC->RCC_AHB1RSTR &=~(1<<3));}while(0)
#define GPIOE_REG_RESET() do{(RCC->RCC_AHB1RSTR |=(1<<4)); (RCC->RCC_AHB1RSTR &=~(1<<4));}while(0)
#define GPIOH_REG_RESET() do{(RCC->RCC_AHB1RSTR |=(1<<5)); (RCC->RCC_AHB1RSTR &=~(1<<7));}while(0)



#endif /* INC_STM32401XX_H_ */
