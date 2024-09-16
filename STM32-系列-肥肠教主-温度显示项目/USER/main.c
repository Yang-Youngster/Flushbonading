#include <stm32f10x.h>
#include <delay.h>
#include <key.h>
#include <led.h>
#include <lighting_sensor.h>
#include <beep.h>
/*********************************************
*   ʵ��ƽ̨��STM32F103CT8
*   library version: register
*   author : LuoYang �ʳ�����
*   deta: 2024/07/27
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
	Key_init();
	//LED
	initLEDPort(RCC_APB2Periph_GPIOA,GPIOA);
	initBEEPPort(RCC_APB2Periph_GPIOB,GPIOB);
	Lighting_sensor_init();

	while(1)
	{
		//��������
		if(Key_Value()==2)
		{
			while(1)
			{
				waterLed();
			}
			
		}
		//��������
		if(Key_Value()==1)
		{
			//��������������
			while(1)
			{
				if(Get_Sensor_singal()==0)
				{
					beepTalk();
				}
			}
			
		}
	}
}




