 /*
 * UART.c
 *
 * Created: 11/5/2021 8:28:25 PM
 *  Author: user
 */ 

#include "UART.h"

void Uart_Init(void){
	UCSRB = (1<<TXEN)|(1<<RXEN)|(1 << RXCIE)|(1<<TXCIE);//Enable Tx & Rx
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);//8bit Send & Receive
	UBRRL = (char)MyUBRR;
	UBRRH = MyUBRR>>8;
	
}
void Uart_Send(unsigned char data){
	
	while(!(UCSRA & (1<<UDRE)));//Waiting the register to be empty
	//while(((UCSRA>>UDRE)&1) == 0);
	UDR = data;
}
unsigned char Uart_Receive(void){
	UCSRB |= (1 << RXCIE);
	while(!(UCSRA & (1<<RXC))); //control and status register and the rxc defines if the receive is completed
	return UDR;
}

void Uart_String(char * string){
	unsigned char i = 0;
	while (string[i] != '\0')
	{
		Uart_Send(string[i]);
		i++;
	}
}