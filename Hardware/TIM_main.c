#include "stm32f10x.h"
#include "TIM_main.h"

void TIM_mainInit(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);

    TIM_InternalClockConfig(TIM2);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period = 10000 - 1;
    TIM_TimeBaseStructure.TIM_Prescaler = 7200 - 1;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);


    //内部时钟TIM调用(二选一)；
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);

    // //外部时钟TIM调用(二选一)；
    // GPIO_InitTypeDef GPIO_InitStructure;
    // GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    // GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    // GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    // GPIO_Init(GPIOA,&GPIO_InitStructure)
    // TIM_ETRClockMode2Config(tim2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x00);


    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(TIM2,ENABLE);

}


void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2,TIM_IT_Update) == SET)
    {
        

        TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
    }
    
}

