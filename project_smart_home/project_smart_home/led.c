/*
 * led.c
 *
 * Created: 11/27/2021 1:23:50 PM
 *  Author: Kerolos
 */ 
#include "led.h"
void led_init(char x , char bit_no){
	
	x = (1<<bit_no);
}
void led_on(char x){
	 = (1<<2);
	
}
void led_off(){
PORTC &=~ (1<<2);
	
}