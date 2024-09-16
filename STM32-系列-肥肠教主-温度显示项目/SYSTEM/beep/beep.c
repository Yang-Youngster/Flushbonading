#include "stm32f10x.h"
#include <delay.h>

GPIO_TypeDef *  GPIO_X_deep_global;


/**
  * @brief  蜂鸣器
  * @param  执行的端口-A OR B  ,函数特定在15端口调试高低电平
  * @retval 无
  */
void initBEEPPort(uint32_t GPIO_APB_X ,GPIO_TypeDef * GPIO_X)
{
		//端口模式的设置
	  GPIO_InitTypeDef GPIO_InitStruct;
	
	  //通用端口进行赋值
	  GPIO_X_deep_global=GPIO_X;
	
	  //使能时钟
	  RCC_APB2PeriphClockCmd(GPIO_APB_X,ENABLE);
	
      GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;    //默认推挽输出
	  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_15;         //开启 GPIO_X的全部端口
	  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	  GPIO_Init(GPIO_X,&GPIO_InitStruct);
}

void beepTalk(void)
{
	
	GPIO_SetBits(GPIO_X_deep_global,GPIO_Pin_15); //高电平
	Delay_ms(200);
	GPIO_ResetBits(GPIO_X_deep_global,GPIO_Pin_15); //低电平
}
