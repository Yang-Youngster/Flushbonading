#include "stm32f10x.h"

/**
  * 函     数: 初始化指定端口
  * 参     数: void
  * 返 回  值: void
  */
void Lighting_sensor_init(void)
{
	//指定端口接收光敏传感器的信号
	
	GPIO_InitTypeDef GPIO_InitStructure;
	/*启动时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		// GPIOA

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;               // 上拉输入 默认高电平，根据相关传感器的特性进行处理
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;                   // GPIO_Pin_6 --> A6
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//  初始化
}

/**
  * 函     数: 获取特定GPIO口的高低电压
  * 参     数: void
  * 返 回  值: void
  */
uint8_t  Get_Sensor_singal()
{
	//根据光敏传感器的特性，主要针对 达到一定 在DO口输出 低电平
	return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);
}




