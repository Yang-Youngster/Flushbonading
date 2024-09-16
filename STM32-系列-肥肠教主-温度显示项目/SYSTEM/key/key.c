#include "stm32f10x.h"
#include "delay.h"

/**
  * ��     ��: ��ʼ��ʱ��
  * ��     ��: void
  * �� ��  ֵ: void
  */
  
 void Key_init(void)
 {
	 GPIO_InitTypeDef GPIO_InitStructure;
	 /*����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		// GPIOA
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;               // �������� Ĭ�ϸߵ�ƽ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_10;     // ���������Ķ˿ڣ�A8 A10 ��Ҫ�漰�Ķ˿�Ϊ��GPIOA
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);						//  ��ʼ��
 }
 
 /**
  * ��     ��: tempValue =1 ��ʾ�����Ѿ����� GPIOA,GPIO_Pin_8 �˿� ����
  * ��     ��: void
  * �� ��  ֵ: uint8_t
  */
uint8_t Key_Value(void)
 {
	 
	 uint8_t tempValue=0;
	 
	 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==0)    // ��ȡ�͵�ƽ
	 {
		 Delay_ms(30);
		 while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==0);
		 Delay_ms(30);
		 
		 //��ȡ��ֵ
		 tempValue=1;
	 }
		 
	  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)==0)    // ��ȡ�͵�ƽ
	 {
		 Delay_ms(30);
		 while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10)==0);
		 Delay_ms(30);
		 
		 //��ȡ��ֵ
		 tempValue=2;
	 }
	 return tempValue;
 }
  