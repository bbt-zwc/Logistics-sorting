#include "stm32f10x.h"
#include "Delay.h"

void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//����GPIOA��ʱ��
	
	GPIO_InitTypeDef  GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_3;  //PA5->EN;PA4->DIR;PA3->PWM
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_SetBits(GPIOA, GPIO_Pin_4| GPIO_Pin_3);	
}

//dir����1����0����numȦ����speed������ߵ͵�ƽʱ��
void Motor_Run_1(uint32_t dir,uint32_t num,uint32_t speed)  
{
	if(dir==1)//��
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);		
	}
	
	if(dir==0)//��
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);	
	}
	
	for(uint32_t i=0;i<=(num*100);i++)  //��ƽ��ת2��Ϊһ�����壬������תһ����Ҫ3200�����壬
	{		
		Delay_us(speed);                   //�ߵ͵�ƽ����ʱ�䣬����Ƶ��
		GPIOA->ODR ^= GPIO_Pin_3; //��תPA3�����ƽ
	}	
}








