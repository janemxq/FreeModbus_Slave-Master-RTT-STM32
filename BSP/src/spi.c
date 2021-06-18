/**
  ********************************  STM32F10x  *********************************
  * @�ļ���     �� spi.c
  * @����       �� strongerHuang
  * @��汾     �� V3.5.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2016��07��29��
  * @ժҪ       �� SPIԴ�ļ�
  ******************************************************************************/
/*----------------------------------------------------------------------------
  ������־:
  2016-07-29 V1.0.0:��ʼ�汾
  ----------------------------------------------------------------------------*/
/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "spi.h"


/************************************************
�������� �� SPI_GPIO_Configuration
��    �� �� SPI��������
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void SPI_GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* SPI: CS������� */
  GPIO_InitStructure.GPIO_Pin = PIN_SPI_CS;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(PORT_SPI_CS, &GPIO_InitStructure);

  /* SPI: SCK, MOSI������� */
  GPIO_InitStructure.GPIO_Pin = PIN_SPI_SCK | PIN_SPI_MOSI;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(PORT_SPI_SCK, &GPIO_InitStructure);

  /* SPI: MISO�������� */
  GPIO_InitStructure.GPIO_Pin = PIN_SPI_MISO;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(PORT_SPI_MISO, &GPIO_InitStructure);
}

/************************************************
�������� �� SPI_Configuration
��    �� �� SPI����
            SPIΪ��ģʽ��ʱ����ƽʱΪ�ͣ������زɼ�����
            8λ���ݸ�ʽ���������Ƭѡ�����ݸ�λ��ǰ
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void SPI_Configuration(void)
{
  SPI_InitTypeDef  SPI_InitStructure;

  /* SPI ��ʼ������ */
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; //SPI����Ϊ˫��˫��ȫ˫��
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;                      //����Ϊ�� SPI
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;                  //SPI���ͽ��� 8 λ֡�ṹ
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;                        //ʱ�����ո�
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;                       //���ݲ����ڵڶ���ʱ����
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;                          //������� NSS �ź�
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2; //������Ԥ��ƵֵΪ2
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;                 //���ݴ���� MSB λ��ʼ
  SPI_InitStructure.SPI_CRCPolynomial = 7;                           //���������� CRCֵ����Ķ���ʽ
  SPI_Init(SPI2, &SPI_InitStructure);

  SPI_Cmd(SPI2, ENABLE);                                             //ʹ�� SPI1
}

/************************************************
�������� �� SPI_Initializes
��    �� �� SPI��ʼ��
��    �� �� ��
�� �� ֵ �� ��
��    �� �� strongerHuang
*************************************************/
void SPI_Initializes(void)
{
  SPI_GPIO_Configuration();
  SPI_Configuration();
}

/************************************************
�������� �� SPI_WriteByte
��    �� �� SPIдһ�ֽ�����
��    �� �� TxData --- ���͵��ֽ�����
�� �� ֵ �� ���������ֽ�����
��    �� �� strongerHuang
*************************************************/
uint8_t SPI_WriteByte(uint8_t TxData)
{
  while((SPI2->SR & SPI_I2S_FLAG_TXE) == (uint16_t)RESET);
  SPI2->DR = TxData;

  while((SPI2->SR & SPI_I2S_FLAG_RXNE) == (uint16_t)RESET);
  return SPI2->DR;
}

/************************************************
�������� �� SPI_ReadByte
��    �� �� SPI��һ�ֽ�����
��    �� �� ��
�� �� ֵ �� ���������ֽ�����
��    �� �� strongerHuang
*************************************************/
uint8_t SPI_ReadByte(void)
{
  while((SPI2->SR & SPI_I2S_FLAG_TXE) == (uint16_t)RESET);
  SPI2->DR = 0xFF;

  while((SPI2->SR & SPI_I2S_FLAG_RXNE) == (uint16_t)RESET);
  return SPI2->DR;
}


/**** Copyright (C)2016 strongerHuang. All Rights Reserved **** END OF FILE ****/
