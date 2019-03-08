#include "led.h"
#include "delay.h"
#include "ioport.h"
#include "sys.h"
#include "usart.h"
#include "GSM.h"
char * testdata = "{\
\"action\": \"01\",\
\"apikey\": \"7bfbd61ef8927f3cde714dcf69aac0dd\",\
\"devid\": \"I4RIzUgh\",\
\"sn\": \"1\",\
\"data\":\
  {\
\"temperature\":\"12.8\",\
\"humidity\":\"13.9\",\
\"windspeed\":\"12.9\",\
\"winddirection\":\"123\",\
\"atmosphere\":\"1234\",\
\"uv\":\"12\",\
\"lux\":\"12\",\
\"so2\":\"1123\",\
\"co\":\"12\",\
\"no2\":\"1123\",\
\"o3\":\"123\",\
\"co2\":\"123\",\
\"voc\":\"12\",\
\"pm25\":\"123\",\
\"pm10\":\"23\",\
\"noise\":\"12\",\
\"longitude\":\"111.11\",\
\"latitude\":\"111.12\",\
\"reportperiod\":20\
  }\
}";



int main(void)
{		
	delay_init();	    	 //延时函数初始化	 
	gpio_init();	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
	delay_ms(3000); 
	gsm_net_init("UDP", 9000);
	while(1)
	{
			gsm_upd_senddata("101.200.48.202", 8777 ,testdata);
	}	 
}

