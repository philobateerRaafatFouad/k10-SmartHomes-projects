/*
* UART.h
*
* Created: 11/5/2021 8:28:09 PM
*  Author: user
*/


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL

#define BaudRate 9600

#ifndef DoubleSpeed
#define MyUBRR ((F_CPU/(BaudRate*16UL))-1)
#else
#define MyUBRR ((F_CPU/(BaudRate*8UL))-1)
#endif

void Uart_Init(void);
void Uart_Send(unsigned char data);
unsigned char Uart_Receive(void);
void Uart_String(char * string);

#endif /* UART_H_ */