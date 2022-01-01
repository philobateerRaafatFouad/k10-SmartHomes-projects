/*
 * led.h
 *
 * Created: 11/27/2021 1:23:33 PM
 *  Author: Kerolos
 */ 


#ifndef LED_H_
#define LED_H_
#include <avr/io.h>


/*#define C DDRC    
#define B DDRB 
#define A DDRA
#define D DDRD*/
typedef enum{
	DDRA ,
	DDRB,
	DDRC,
	DDRD
	}ports;
typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD
	}OUTPUTS;

void led_init(ports x , char bit_no);
void led_on(OUTPUTS x, char bit_no);
void led_off();


#endif /* LED_H_ */