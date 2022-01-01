/*
 * airconditioner.c
 *
 * Created: 12/7/2021 5:17:06 PM
 *  Author: Kerolos
 */ 
#include "airconditioner.h"

void airconditioner_init(void){
	 unsigned short temp = 0;
	 char string[20];
	temp = ADC_Read(DIO_ChannelA0);
		temp = temp/4;
			/*itoa(temp,string,10);
			LCD_String(string);
			_delay_ms(200);
			LCD_Cmd(0x01);*/
		if(temp>=29){
			LCD_Cmd(0x01);
			dcmotor_rotate(dcmotor_cw);
			LCD_String(str16);
		}
		if (temp<=20)
		{
			LCD_Cmd(0x01);
			dcmotor_rotate(dcmotor_stop);
			LCD_String(str17);
			
		}
		
}
