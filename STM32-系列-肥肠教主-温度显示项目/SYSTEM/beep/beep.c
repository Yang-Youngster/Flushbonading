#include "stm32f10x.h"
#include <delay.h>

GPIO_TypeDef *  GPIO_X_deep_global;


/**
  * @brief  ������
  * @param  ִ�еĶ˿�-A OR B  ,�����ض���15�˿ڵ��Ըߵ͵�ƽ
  * @retval ��
  */
void initBEEPPort(uint32_t GPIO_APB_X ,GPIO_TypeDef * GPIO_X)
{
		//�˿�ģʽ������
	  GPIO_InitTypeDef GPIO_InitStruct;
	
	  //ͨ�ö˿ڽ��и�ֵ
	  GPIO_X_deep_global=GPIO_X;
	
	  //ʹ��ʱ��
	  RCC_APB2PeriphClockCmd(GPIO_APB_X,ENABLE);
	
      GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;    //Ĭ���������
	  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_15;         //���� GPIO_X��ȫ���˿�
	  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	  GPIO_Init(GPIO_X,&GPIO_InitStruct);
}

void beepTalk(void)
{
	
	GPIO_SetBits(GPIO_X_deep_global,GPIO_Pin_15); //�ߵ�ƽ
	Delay_ms(200);
	GPIO_ResetBits(GPIO_X_deep_global,GPIO_Pin_15); //�͵�ƽ
}
