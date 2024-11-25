#include "stm32f10x.h"
#include "Delay.h"
#include "Software_I2C.h"

#define I2C_SCL_Pin GPIO_Pin_10
#define I2C_SDA_Pin GPIO_Pin_11


void SCL_W_Set(uint16_t value)
{
    GPIO_WriteBit(GPIOA,I2C_SCL_Pin,(BitAction)value);
    Delay_ms(10);
}

void SDA_W_Set(uint16_t value)
{
    GPIO_WriteBit(GPIOA,I2C_SDA_Pin, (BitAction)value);
    Delay_ms(10);
}

uint8_t SDA_R_Set(void)
{
    uint8_t BiteValue;
    BiteValue = GPIO_ReadInputDataBit(GPIOA,I2C_SDA_Pin);
    Delay_ms(10);
    return BiteValue;
}
void Software_I2CInit(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);
}


void Software_I2CStart(void)
{
    SDA_W_Set(1);
    SCL_W_Set(1);
    SDA_W_Set(0);
    SCL_W_Set(0);
}

void Software_I2CStop(void)
{
    SDA_W_Set(0);
    SCL_W_Set(1);
    SDA_W_Set(1);
}

void Software_I2CSendAck(uint8_t AckBit)
{
    SDA_W_Set(AckBit);
    SCL_W_Set(1);
    SCL_W_Set(0);
}

uint8_t Software_I2CReceiveAck(void)
{
    SDA_W_Set(1);
    SCL_W_Set(1);
    uint8_t AckBit = SDA_R_Set();
    SCL_W_Set(0);
    return AckBit;
}

void Software_I2CSendByte(uint8_t Byte)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        SDA_W_Set(Byte & (0x80 >> i));
        SCL_W_Set(1);
        SCL_W_Set(0);
    }
}

uint8_t Software_I2CReceiveByte(void)
{
    uint8_t Byte = 0x00;
    for (uint8_t i = 0; i < 8; i++)
    {
        SCL_W_Set(1);
        if (SDA_R_Set() == 1)
        {
            Byte |= 0x80 >> i;
        }
        SCL_W_Set(0);
    }
    return Byte;
}
