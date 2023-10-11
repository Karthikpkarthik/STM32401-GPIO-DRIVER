/*
 * STM32401xx_GPIO_HEADER.c
 *
 *  Created on: Oct 11, 2023
 *      Author: karth
 */
#include "STM32401xx_GPIO_DRIVER.h"

/***************************************
-------Peripheral clock set----------
*  @FunctionName:  GPIO_PerClkContrl

*  @Brief: This function used to enable or disable the particular GPIO peripheral clock

*  @Parameter[1]:take GPIO base address
*  @Parameter[2]:take SET  or REST macro

*  @Return Type: None

*  @Note: None
***************************************/
void GPIO_PerClkContrl(GPIO_REG_DEF *pGPIOx,uint8_t ENorDI)
{
if (ENorDI==ENABLE)
{ if (pGPIOx==GPIOA)
	GPIOA_PCLK_EN();
else if (pGPIOx==GPIOB)
	GPIOB_PCLK_EN();
else if (pGPIOx==GPIOC)
	GPIOC_PCLK_EN();
else if (pGPIOx==GPIOD)
	GPIOD_PCLK_EN();
else if (pGPIOx==GPIOE)
	GPIOE_PCLK_EN();
else if (pGPIOx==GPIOH)
	GPIOH_PCLK_EN();
}
else if(ENorDI==DISABLE)
{
	if (pGPIOx==GPIOA)
		GPIOA_PCLK_DI();
	else if (pGPIOx==GPIOB)
		GPIOB_PCLK_DI();
	else if (pGPIOx==GPIOC)
		GPIOC_PCLK_DI();
	else if (pGPIOx==GPIOD)
		GPIOD_PCLK_DI();
	else if (pGPIOx==GPIOE)
		GPIOE_PCLK_DI();
	else if (pGPIOx==GPIOH)
		GPIOH_PCLK_DI();
}
}
//
/***************************************
-------GPIO PORT Initialization ----------
*  @FunctionName:  GPIO_Init

*  @Brief: This function used to configure the pull-up/pull-down,speed,alternate function,
*  pin mode,pin output type.

*  @Parameter[1]:take GPIO base address


*  @Return Type: None

*  @Note: None
**************************************/

void GPIO_Init(GPIO_handler_t *pGPIO_Handler)
{
	uint8_t temp=0;
 if(pGPIO_Handler->GPIO_PinConfig.GPIO_Pinmode <= GPIO_MODE_ANALOG)
 {//NON INTERRUPT MODE

	temp=pGPIO_Handler->GPIO_PinConfig.GPIO_Pinmode <<(2*pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber);
	pGPIO_Handler->pGPIOx->MODER &= ~(0x3 <<(2*pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber));
	pGPIO_Handler->pGPIOx->MODER|=temp;

 }
 else
 { //interrupt mode

 }
 temp=0;
 //configuring the speed
 temp=pGPIO_Handler->GPIO_PinConfig.GPIO_Pinspeed <<(2*pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber);
 pGPIO_Handler->pGPIOx->OSPEEDR &= ~(0x3 <<(2*pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber));//clearing
 pGPIO_Handler->pGPIOx->OSPEEDR|=temp;//setting
 temp=0;
 //configuring the pull-up and pull-down
 temp=pGPIO_Handler->GPIO_PinConfig.GPIO_PinPuPdControl<<(2*pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber);
 pGPIO_Handler->pGPIOx->PUPDR &= ~(0x3 <<(2*pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber));//clearing
 pGPIO_Handler->pGPIOx->PUPDR|=temp;//setting
 temp=0;
 //configuring the pin output type
 temp=pGPIO_Handler->GPIO_PinConfig.GPIO_PinOPType<<pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber;
 pGPIO_Handler->pGPIOx->OSPEEDR &= ~(0x1 <<pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber);//clearing
 pGPIO_Handler->pGPIOx->OTYPER|=temp;//setting
 temp=0;

 //configuring the pin alternate function
 if(pGPIO_Handler->GPIO_PinConfig.GPIO_PinAltFunMode==GPIO_MODE_ALTFU)
 {
  uint8_t temp1=0,temp2=0;
  temp1=pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber/8;
  temp2=pGPIO_Handler->GPIO_PinConfig.GPIO_PinNumber%8;
  pGPIO_Handler->pGPIOx->AFR[temp1]&= ~(0xf <<(4*temp2));
  pGPIO_Handler->pGPIOx->AFR[temp1]|=pGPIO_Handler->GPIO_PinConfig.GPIO_PinAltFunMode <<(4*temp2);
 }
}
/***************************************
-------GPIO PORT deInitialization ----------
*  @FunctionName:  GPIO_DeInit

*  @Brief: This function used to deInitialization the pull-up/pull-down,speed,alternate function,
*  pin mode,pin output type.

*  @Parameter[1]:take GPIO base address


*  @Return Type: None

*  @Note: None
**************************************/
void GPIO_DeInit(GPIO_REG_DEF *pGPIOx)
{
	if (pGPIOx==GPIOA)
		GPIOA_REG_RESET();
	else if (pGPIOx==GPIOB)
		GPIOB_REG_RESET();
	else if (pGPIOx==GPIOC)
		GPIOC_REG_RESET();
	else if (pGPIOx==GPIOD)
		GPIOD_REG_RESET();
	else if (pGPIOx==GPIOE)
		GPIOE_REG_RESET();
	else if (pGPIOx==GPIOH)
		GPIOH_REG_RESET();
}
/********************************************************
-------GPIO pin input ----------
*  @FunctionName:  GPIO_ReadFromInputPin

*  @Brief: This function used to access the indivisial pin input return the value of the particular pin.

*  @Parameter[1]:take GPIO base address
*  @Parameter[2]:take Pin number


*  @Return Type: unsigned char (8 bits)

*  @Note: None
**************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_REG_DEF *pGPIOx,uint8_t PinNumber)
{
uint8_t value=0;
value=(uint8_t)(pGPIOx->IDR >> PinNumber)&0x00000001;
return value;
}
/********************************************************
-------GPIO port input ----------
*  @FunctionName:  GPIO_ReadFromInputPort

*  @Brief: This function used to access the individual pin input and return the value of the particular pin.

*  @Parameter[1]:take GPIO base address



*  @Return Type: unsigned int (16 bits)

*  @Note: None
**************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_REG_DEF *pGPIOx)
{
uint16_t value=0;
value=(uint16_t)pGPIOx->IDR;
return value;
}
/********************************************************
-------GPIO pin output ----------
*  @FunctionName:  GPIO_WriteToOutputPin

*  @Brief: This function used to write the data tp individual pin.

*  @Parameter[1]:take GPIO base address
*  @Parameter[2]:take pin number 1 to 16
*  @Parameter[3]:take GPIO_PIN_SET or GPIO_PIN_RESET

*  @Return Type: NA

*  @Note: None
**************************************/
void GPIO_WriteToOutputPin(GPIO_REG_DEF *pGPIOx,uint8_t PinNumber,uint8_t value)
{
  if (value==GPIO_PIN_SET){
	// set the pin
	  pGPIOx->ODR|=(1<<PinNumber);
  }
  else{
	// reset the pin
	  pGPIOx->ODR&= ~(1<<PinNumber);
  }
}
/********************************************************
-------GPIO port output ----------
*  @FunctionName:  GPIO_WriteToOutputPort

*  @Brief: This function used to write the data to particular port .

*  @Parameter[1]:take GPIO base address
*
*  @Parameter[2]:take any value between 0 to 2^16

*  @Return Type: NA

*  @Note: None
**************************************/
void GPIO_WriteToOutputPort(GPIO_REG_DEF *pGPIOx,uint16_t value)
{
 pGPIOx->ODR=value;
}
/********************************************************
-------GPIO pin output Toggle ----------
*  @FunctionName:  GPIO_ToggleOutputPin

*  @Brief: This function used to toggle the perticuler pin.

*  @Parameter[1]:take GPIO base address
*
*  @Parameter[2]:take pin  number

*  @Return Type: NA

*  @Note: None
**************************************/
void GPIO_ToggleOutputPin(GPIO_REG_DEF *pGPIOx,uint8_t PinNumber)
{
pGPIOx->ODR^=(1<<PinNumber);
}
/********************************************************
-------IRQ Config ----------
*  @FunctionName:  GPIO_IRQConfig

*  @Brief: This function used to toggle the perticuler pin.

*  @Parameter[1]:take GPIO base address
*
*  @Parameter[2]:take pin  number

*  @Return Type: NA

*  @Note: None
**************************************/
//IRQ functions
//void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t Priority,uint8_t ENorDI);
//void GPIO_IRQHandling(uint8_t PinNUmber);

