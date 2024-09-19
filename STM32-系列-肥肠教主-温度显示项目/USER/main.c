#include <stm32f10x.h>
#include <delay.h>
#include <key.h>
#include <led.h>
#include <lighting_sensor.h>
#include <beep.h>
/*********************************************
*   ʵ��ƽ̨��STM32F103CT8
*   library version: functino
*   author : LuoYang �ʳ�����
*   deta: 2024/09/17
*   subject: ������������ʹ��    
**********************************************/

int main()
{
/**	Test Function
  *
  * ��     ��: ����������ˮ��
  * ��     ��: void
  * �� ��  ֵ: void
  */
	//������ʼ��
	//Key_init();
	//LED
	//initLEDPort(RCC_APB2Periph_GPIOA,GPIOA);
	
	//��ʼ��BEEP
	initBEEPPort(RCC_APB2Periph_GPIOB,GPIOB);
	
	//��ʼ������
	Lighting_sensor_init();
	 
	while(1)
	{
	uint8_t	temp=Get_Sensor_singal();
		if(temp==1)
		{
				beepTalk();
		}
	}
}




