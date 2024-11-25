#include "stm32f10x.h"
#include <time.h>
#include <stdio.h>
#include "MyRTC.h"

void MyRTC_Init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);

    PWR_BackupAccessCmd(ENABLE);
    if (BKP_ReadBackupRegister(BKP_DR1) != 0xA5A5)
    {
        RCC_LSEConfig(RCC_LSE_ON);
        while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) != SET);

        RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
        RCC_RTCCLKCmd(ENABLE);

        RTC_WaitForSynchro();
        RTC_WaitForLastTask();

        RTC_SetPrescaler(32768 - 1);
        RTC_WaitForLastTask();

        MyRTC_SetTime();

        BKP_WriteBackupRegister(BKP_DR1,0xA5A5);
    }

}


void MyRTC_SetTime(void)
{   // 获取当前时间（时间戳）
    time_t current_time = time(NULL);

    if (current_time == (time_t)(-1)) {
        // 错误处理：time 函数失败
        perror("time");
    }

    RTC_SetCounter(current_time);
    RTC_WaitForLastTask();
}


