#include "stm32f10x.h"
#include "delay.h"

/**
  * 函     数: 初始化时钟
  * 参     数: void
  * 返 回  值: void
  */
  
 void Key_init(void)
 {
	 /*启动时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		// GPIOA
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;               // 上拉输入 默认高电平
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);						//  初始化
 }
 
 /**
  * 函     数: 初始化时钟
  * 参     数: void
  * 返 回  值: uint8_t
  */
 
uint8_t Key_Value(void)
 {
	 
	 uint8_t tempValue=0;
	 
	 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==0)    // 读取低电平
	 {
		 Delay_ms(30);
		 while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==0);
		 Delay_ms(30);
		 
		 //获取键值
		 tempValue=1;
	 }
		 
	  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)==0)    // 读取低电平
	 {
		 Delay_ms(30);
		 while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)==0);
		 Delay_ms(30);
		 
		 //获取键值
		 tempValue=2;
	 }
	 return tempValue;
 }
 