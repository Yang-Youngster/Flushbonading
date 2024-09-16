#include "stm32f10x.h"
#include <delay.h>

//全局变量
  GPIO_TypeDef *  GPIO_X_led_global;
/**
  * @brief  初始化
  * @param  选择特定的端口进行使能
  * @retval 无
  */
void initLEDPort(uint32_t GPIO_APB_X ,GPIO_TypeDef * GPIO_X)
{
		  //端口模式的设置
	  GPIO_InitTypeDef GPIO_InitStruct;
	  //通用端口进行赋值
	  GPIO_X_led_global=GPIO_X;
	  //使能时钟
	  RCC_APB2PeriphClockCmd(GPIO_APB_X,ENABLE);
	
		GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;    //默认推挽输出
		GPIO_InitStruct.GPIO_Pin=GPIO_Pin_All;         //开启 GPIO_X的全部端口
		GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
	  GPIO_Init(GPIO_X,&GPIO_InitStruct);
}
/**
  * @brief  流水灯效果
  * @param  写入数据的端口
  * @retval 无
  */

void waterLed(void)
{
	//写入数据状态 	
	GPIO_Write(GPIO_X_led_global,~0x0001); //给 PX0 端口 低电平
	  Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0002); //给 PX1 端口 高 电平
		Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0004); //给 PX2 端口 高 电平
		Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0008); //给 PX3 端口 高 电平
		Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0010); //给 PX4 端口 高 电平
		Delay_ms(500);
	GPIO_Write(GPIO_X_led_global,~0x0020); //给 PX5 端口 高 电平
		Delay_ms(500);
  //……后续可以直接添加
}
