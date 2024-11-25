#include "stm32f10x.h"
#include "Hardware_SPI.h"

#define MySS_Pin GPIO_Pin_4

void MySS_W_Set(uint8_t value)
{
	GPIO_WriteBit(GPIOA,MySS_Pin,(BitAction)value);
}

void Hardware_SPIInit(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    SPI_InitTypeDef SPI_InitStructure;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CRCPolynomial = 7;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
    SPI_Init(SPI1,&SPI_InitStructure);

    SPI_Cmd(SPI1,ENABLE);

    MySS_W_Set(1);
}


void Hardware_SPIStart(void)
{
    MySS_W_Set(0);
}

void Hardware_SPIStop(void)
{
    MySS_W_Set(1);
}

uint8_t Hardware_SPISwap(uint8_t ByteSend)
{
    while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE) != 1);
    SPI_I2S_SendData(SPI1,ByteSend);
    while (SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE) != 1);
    return SPI_I2S_ReceiveData(SPI1);
}


