#include "stm32f10x.h"
#include "Software_SPI.h"

#define SPI_SS_Pin GPIO_Pin_4
#define SPI_SCK_Pin GPIO_Pin_5
#define SPI_MOSI_Pin GPIO_Pin_7
#define SPI_MISO_Pin GPIO_Pin_6

void Software_SPIInit(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    //初始化SS引脚和SCK引脚；
    SS_W_Set(1);
    SCK_W_Set(0);
}

void SS_W_Set(uint8_t value)
{
    GPIO_WriteBit(GPIOA,SPI_SS_Pin,(BitAction)value);
}

void SCK_W_Set(uint8_t value)
{
    GPIO_WriteBit(GPIOA,SPI_SCK_Pin,(BitAction)value);
}

void MOSI_W_Set(uint8_t value)
{
    GPIO_WriteBit(GPIOA,SPI_MOSI_Pin,(BitAction)value);
}

uint8_t MISO_R_Set(void)
{
    return GPIO_ReadInputDataBit(GPIOA,SPI_MISO_Pin);
}

void Software_SPIStart(void)
{
    SS_W_Set(0);
}

void Software_SPIStop(void)
{
    SS_W_Set(1);
}

uint8_t Software_SwapByte(uint8_t ByteSend)
{
    uint8_t ByteReceive = 0x00;
    for (uint8_t i = 0; i < 8; i++)
    {
        MOSI_W_Set(ByteSend & (0x80 >> i));
        SCK_W_Set(1);
        if (MISO_R_Set() == 1)
        {
            ByteReceive |= (0x80 >>i);
        }
        SCK_W_Set(0);
    }
    return ByteReceive;
}

