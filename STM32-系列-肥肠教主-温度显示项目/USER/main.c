#include <stm32f10x.h>
#include <delay.h>
#include <key.h>
#include <led.h>
#include <lighting_sensor.h>
#include <beep.h>
/*********************************************
*   实验平台：STM32F103CT8
*   library version: register
*   author : LuoYang 肥肠教主
*   deta: 2024/07/27
*   subject: 光敏传感器的使用    
**********************************************/

int main()
{
/**	Test Function
  *
  * 函     数: 按键控制流水灯
  * 参     数: void
  * 返 回  值: void
  */
	//按键初始化
	Key_init();
	//LED
	initLEDPort(RCC_APB2Periph_GPIOA,GPIOA);
	initBEEPPort(RCC_APB2Periph_GPIOB,GPIOB);
	Lighting_sensor_init();

	while(1)
	{
		//按键按下
		if(Key_Value()==2)
		{
			while(1)
			{
				waterLed();
			}
			
		}
		//按键按下
		if(Key_Value()==1)
		{
			//启动光敏传感器
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




