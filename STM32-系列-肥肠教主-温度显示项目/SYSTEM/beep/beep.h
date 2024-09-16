#ifndef __BEEP_H
#define __BEEP_H

void initBEEPPort(uint32_t GPIO_APB_X ,GPIO_TypeDef * GPIO_X);
void beepTalk(void);

#endif
