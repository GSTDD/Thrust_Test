
#include "stm32f10x.h"
#include "delay.h"
#include "HX711.h"
#include "usart.h"
#include "filter.h"

float Buf_Thrust[15];

int main(void)
{		
	
	float Thrust = 0;
//	float Weight = 0;
	Init_HX711pin();
	delay_init();
	
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ9600
	printf("hello\r\n");
	Get_Maopi();				//��ëƤ����
	delay_ms(1000);
	delay_ms(1000);
	Get_Maopi();				//���»�ȡëƤ����
	printf("hello\r\n");
	while(1)
	{
		Get_Weight();

		printf("Weight:%d g\r\n",Weight_Shiwu);
		
//Thrust = (float)(Weight_Shiwu / 1000 )* 9.8;//9.8N/KG	
		//Thrust = Moving_Average(Buf_Thrust,Thrust);
		//printf("Thrust:%f N\r\n",Thrust);
			
		//printf("Thrust:%fN---Weight:%dg\r\n",Thrust,Weight_Shiwu);
		delay_ms(1000);
	}
}






