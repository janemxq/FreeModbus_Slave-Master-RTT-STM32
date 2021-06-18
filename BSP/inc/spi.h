/**
  ********************************  STM32F10x  *********************************
  * @文件名     ： spi.h
  * @作者       ： strongerHuang
  * @库版本     ： V3.5.0
  * @文件版本   ： V1.0.0
  * @日期       ： 2016年07月29日
  * @摘要       ： SPI头文件
  ******************************************************************************/

/* 定义防止递归包含 ----------------------------------------------------------*/
#ifndef _SPI_H
#define _SPI_H

/* 包含的头文件 --------------------------------------------------------------*/
#include "stm32f10x.h"


/* 宏定义 --------------------------------------------------------------------*/
#define PORT_SPI_CS               GPIOB
#define PORT_SPI_SCK              GPIOB
#define PORT_SPI_MISO             GPIOB
#define PORT_SPI_MOSI             GPIOB

#define PIN_SPI_CS                GPIO_Pin_12  //pb12  /WP(低电平)接VDD     /HOLD (低电平)接VDD 
#define PIN_SPI_SCK               GPIO_Pin_13  //pb13
#define PIN_SPI_MISO              GPIO_Pin_14   //pb14
#define PIN_SPI_MOSI              GPIO_Pin_15   //pb15

#define SPI_CS_ENABLE             (PORT_SPI_CS->BRR  = PIN_SPI_CS)
#define SPI_CS_DISABLE            (PORT_SPI_CS->BSRR = PIN_SPI_CS)

/* 函数申明 ------------------------------------------------------------------*/
void SPI_Initializes(void);
uint8_t SPI_WriteByte(uint8_t TxData);
uint8_t SPI_ReadByte(void);


#endif /* _SPI_H */

/**** Copyright (C)2016 strongerHuang. All Rights Reserved **** END OF FILE ****/
