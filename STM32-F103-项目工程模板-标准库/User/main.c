#include "stm32f10x.h"   // Device header

/*********************************************/
//*   实验平台：STM32F103CT8
//*   library version: register
//*   author : 肥肠教主-LuoYang
//*   deta: 2024/07/19
//*   subject:
//*   使用寄存器开发-创建文件-Start-User 文件的形式
//*
/**********************************************/
int main(void)
{
	//寄存器的方式点灯
	RCC->APB2ENR=0x00000010;
	GPIOC->CRH=0x00300000;
	GPIOC->ODR=0x0000200; //重点数据手册
	 while(1)
	 {
		 //读写成功
	 } 
}
