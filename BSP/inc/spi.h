/**
  ********************************  STM32F10x  *********************************
  * @�ļ���     �� spi.h
  * @����       �� strongerHuang
  * @��汾     �� V3.5.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2016��07��29��
  * @ժҪ       �� SPIͷ�ļ�
  ******************************************************************************/

/* �����ֹ�ݹ���� ----------------------------------------------------------*/
#ifndef _SPI_H
#define _SPI_H

/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "stm32f10x.h"


/* �궨�� --------------------------------------------------------------------*/
#define PORT_SPI_CS               GPIOB
#define PORT_SPI_SCK              GPIOB
#define PORT_SPI_MISO             GPIOB
#define PORT_SPI_MOSI             GPIOB

#define PIN_SPI_CS                GPIO_Pin_12  //pb12  /WP(�͵�ƽ)��VDD     �H/HOLD (�͵�ƽ)��VDD 
#define PIN_SPI_SCK               GPIO_Pin_13  //pb13
#define PIN_SPI_MISO              GPIO_Pin_14   //pb14
#define PIN_SPI_MOSI              GPIO_Pin_15   //pb15

#define SPI_CS_ENABLE             (PORT_SPI_CS->BRR  = PIN_SPI_CS)
#define SPI_CS_DISABLE            (PORT_SPI_CS->BSRR = PIN_SPI_CS)

/* �������� ------------------------------------------------------------------*/
void SPI_Initializes(void);
uint8_t SPI_WriteByte(uint8_t TxData);
uint8_t SPI_ReadByte(void);


#endif /* _SPI_H */

/**** Copyright (C)2016 strongerHuang. All Rights Reserved **** END OF FILE ****/
