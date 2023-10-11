/*
 * STM32401xx_GPIO_DRIVER.c
 *
 *  Created on: Oct 11, 2023
 *      Author: karth
 */

#ifndef INC_STM32401XX_GPIO_DRIVER_H_
#define INC_STM32401XX_GPIO_DRIVER_H_
#include "STM32401xx.h"
typedef struct{
	uint8_t GPIO_PinNumber;/*<possiable mPINS are @GPIO Pin number>*/
	uint8_t GPIO_Pinmode;/*<possiable modes are @GPIO mode>*/
	uint8_t GPIO_Pinspeed;/*<possiable SPEED modes are @GPIO output speed >*/
	uint8_t GPIO_PinPuPdControl;/*<possiable  modes are @GPIO PIN PULL_UP AND PULL_DOWN >*/
	uint8_t GPIO_PinOPType;/*<possiable modes are @GPIO output type >*/
	uint8_t GPIO_PinAltFunMode;

}GPIO_PinConfig_t;
typedef struct {
	GPIO_REG_DEF *pGPIOx;//which holds the base address of GPIOs
	GPIO_PinConfig_t GPIO_PinConfig;//hold the alternate function for the GPIO
}GPIO_handler_t;
//
/*
 * @GPIO Pin number
 */
#define GOIP_PIN_NO_0 0
#define GOIP_PIN_NO_1 1
#define GOIP_PIN_NO_2 2
#define GOIP_PIN_NO_3 3
#define GOIP_PIN_NO_4 4
#define GOIP_PIN_NO_5 5
#define GOIP_PIN_NO_6 6
#define GOIP_PIN_NO_7 7
#define GOIP_PIN_NO_8 8
#define GOIP_PIN_NO_9 9
#define GOIP_PIN_NO_10 10
#define GOIP_PIN_NO_11 11
#define GOIP_PIN_NO_12 12
#define GOIP_PIN_NO_13 13
#define GOIP_PIN_NO_14 14
#define GOIP_PIN_NO_15 15
/*
 * @GPIO mode
 */
#define GPIO_MODE_IN     0
#define GPIO_MODE_OUT    1
#define GPIO_MODE_ALTFU  2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_RT  4 //raising edge
#define GPIO_MODE_IT_FT  5  //falling edge
#define GPIO_MODE_IT_RFS 6  //raising and falling edge
/*
 * /@GPIO output type
 */
#define GPIO_OTY_PP 0
#define GPIO_OTY_OD 1
/*
 * /@GPIO output speed
 */
#define GPIO_SPEED_LOW    0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST   2
#define GPIO_SPEED_HIGH   3
/*
 * /@GPIO PIN PULL_UP AND PULL_DOWN
 */
#define GPIO_NO_PUPD 0
#define GPIO_PIN_PU  1
#define GPIO_PIN_PD  2
/*
 * /GPIO PIN PULL_UP AND PULL_DOWN
 */
//
void GPIO_PerClkContrl(GPIO_REG_DEF *pGPIOx,uint8_t ENorDI);
//
void GPIO_Init(GPIO_handler_t *pGPIO_Handler);
void GPIO_DeInit(GPIO_REG_DEF *pGPIOx);
//read
uint8_t GPIO_ReadFromInputPin(GPIO_REG_DEF *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_REG_DEF *pGPIOx);
//
void GPIO_WriteToOutputPin(GPIO_REG_DEF *pGPIOx,uint8_t PinNumber,uint8_t value);
void GPIO_WriteToOutputPort(GPIO_REG_DEF *pGPIOx,uint16_t value);
void GPIO_ToggleOutputPin(GPIO_REG_DEF *pGPIOx,uint8_t PinNumber);
//IRQ functions
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t Priority,uint8_t ENorDI);
void GPIO_IRQHandling(uint8_t PinNUmber);


#endif /* INC_STM32401XX_GPIO_DRIVER_C_ */
