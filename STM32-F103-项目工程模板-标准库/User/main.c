#include "stm32f10x.h"   // Device header
#include "Delay.h"

/*********************************************/
//*   实验平台：STM32F103CT8
//*   library version: register
//*   author : 肥肠教主-LuoYang
//*   deta: 2024/07/19
//*   subject:
//*   使用寄存器开发-创建文件-Start-User 文件的形式 Test文件
//*
/**********************************************/
int main(void)
{
	//寄存器的方式点灯
	//RCC->APB2ENR=0x00000010; //看数据手册 开启使能时钟，获取GPIOC的操作权限
	//GPIOC->CRH=0x00300000;
	//GPIOC->ODR=0x0000200; //重点数据手册
	 GPIO_InitTypeDef GPIO_PC13;
	 GPIO_InitTypeDef GPIO_PA0;
	//使用库函数的方式点灯
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOA,ENABLE);
	 //定义相关输出模式
	 GPIO_PC13.GPIO_Pin=GPIO_Pin_13;
	 GPIO_PC13.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_PC13.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOC,&GPIO_PC13);
	 GPIO_PA0.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_PA0.GPIO_Pin=GPIO_Pin_0;
	 GPIO_PA0.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOA,&GPIO_PA0);
	//设立高点平
	 while(1)
	 {
		 //读写成功
		  GPIO_SetBits(GPIOA,GPIO_Pin_0);
		  GPIO_SetBits(GPIOC,GPIO_Pin_13);
		  Delay_s(2);
		  GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		  GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		  Delay_s(2);
	 } 
}
