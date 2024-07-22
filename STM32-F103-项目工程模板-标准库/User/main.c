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
void delay(u16 num)
{
  u16 i,j;
  for(i=0;i<num;i++)
    for(j=0;j<0x800;j++);
}
int main(void)
{
	//寄存器的方式点灯
	//RCC->APB2ENR=0x00000010; //看数据手册 开启使能时钟，获取GPIOC的操作权限
	//GPIOC->CRH=0x00300000;
	//GPIOC->ODR=0x0000200; //重点数据手册
	 GPIO_InitTypeDef GPIO_temp;
	//使用库函数的方式点灯
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	 GPIO_temp.GPIO_Pin=GPIO_Pin_13;
	 GPIO_temp.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_temp.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOC,&GPIO_temp);
	//设立高点平

	 while(1)
	 {
		 //读写成功
		  GPIO_SetBits(GPIOC,GPIO_Pin_13);
		  delay(1000);
		  GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		  delay(1000);
	 } 
}
