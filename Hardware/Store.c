#include "stm32f10x.h"
#include "Store.h"
#include "MyFlash.h"

void Store_Init(void)
{
    if (MyFlash_ReadHalfWord(0x0800FC00) != 0xA5A5)
    {
        MyFlash_ErasePage(0x0800FC00);
        MyFlash_ProgramHalfWord(0x0800FC00,0xA5A5);
        for (uint16_t i = 1; i < 512; i++)
        {
            MyFlash_ProgramHalfWord(0x0800FC00 + 2*i,0x0000);
        }
    }
    for (uint16_t k = 1; k < 512; k++)
    {
        Store_Data[k] = MyFlash_ReadHalfWord(0x0800FC00 + 2*k);
    }
}

void Store_Save(void)
{
    MyFlash_ErasePage(0x0800FC00);
    for (uint16_t j = 0; j < 512; j++)
    {
        MyFlash_ProgramHalfWord(0x0800FC00 + 2*j,Store_Data[j]);
    }
}

void Store_Clear(void)
{
    for (uint16_t l = 1; l < 512; l++)
    {
        Store_Data[l] = 0x0000;
    }
    Store_Save();
}



