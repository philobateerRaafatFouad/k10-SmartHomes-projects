/*
* UART_K10.c
*
* Created: 11/5/2021 8:27:49 PM
* Author : user
*/
#include "includes.h"

char c=5;
volatile unsigned char k=0;
uint8 p=0;
volatile uint8 Uart_Data = 0;
	char a;
	char b=1;
	char s=0;
		Uint8 z=0;

int main(void)
{
	Uint8 data = 0;
	sei();
	char y;

	char k=0;

	Uint8 x=0;
	DDRD |= (1<<7);
	DDRD |= (1<<6);
	DDRD |= (1<<5);
	DDRD |= (1<<4);
	DDRD |= (1<<3);
		DDRD |= (1<<2);
	DDRB |= (1<<7);


	
	Uart_Init();
	DIO_Init();
	LCD_Init();
	dcmotor_init();
	TWI_Init(0b00000010);
	ADC_Init();
	
	Uint8 data2 =0;
	Uint8 data3 =0;
	Uint8 data4 =0;

	unsigned short temp = 0;
	char string[20];
	char arr[2];
	char arr1[2];
	char arr2[2];
	char arr3[2];

	
	while (1)
	{
		
		////////////////////////////////////////////////////////////////////////////////////////
		////                       temperature and air conditioner
		////////////////////////////////////////////////////////////////////////////////////
		
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
			_delay_ms(1000);
			LCD_Cmd(0x01);

		}
		if (temp<=20)
		{
			LCD_Cmd(0x01);
			dcmotor_rotate(dcmotor_stop);
			LCD_String(str17);
			_delay_ms(1000);
			LCD_Cmd(0x01);
		}
		
		
		///////////////////////////////////////////////////////////////////////////////////////////////////
		////                                  e2prom to read password
		//////////////////////////////////////////////////////////////////////////////////////////////////
		
		//	LCD_Cmd(0x01);
		/* password = 0b00000011;
		E2PROM_Write(0b10100000,0b00000011,password);
		z= E2PROM_Read(0b10100000,0b00000011);
		if(z==password){
		PORTD |=(1<<7);
		}
		//itoa (z,buff,10);
		//LCD_String(buff);*/
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////                           uart send and recieve password
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Uart_Send('m');
		
		

		
		////////////////////////////////////////////////////////////////////////////////////////////////
		/////                                keypad and lcd                                        /////
		////////////////////////////////////////////////////////////////////////////////////////////////
		LCD_String(str);
		LCD_Cmd(0xc0);
		LCD_String(str18);
		if(x==0){
	do
	{
	data =GetKey2();
	} while (data==0 && p==0 );
		if(data != 0){
		switch(data){
		case '1':
		LCD_Cmd(0x01);
		LCD_String(str2);
		for (int q=0;q<2;q++)
		{
		arr[q]=GetKey();
		}
		if(arr[0]=='5' && arr[1]=='6'){
		LCD_Cmd(0x01);
		LCD_String(str1);
		_delay_ms(1500);
		LCD_Cmd(0x01);
		LCD_String(str3);
		LCD_Cmd(0Xc0);
		LCD_String(str4);
		x=1;
		}
		else{
		LCD_Cmd(0x01);

		LCD_String(str10);
		_delay_ms(1000);
		}
		
		break;
		case '2':
		LCD_Cmd(0x01);
		LCD_String(str2);
		for (int w=0;w<2;w++)
		{
		arr1[w]=GetKey();
		}
		if(arr1[0]=='4' && arr1[1]=='3'){
		LCD_Cmd(0x01);
		LCD_String(str1);
		_delay_ms(1500);
		LCD_Cmd(0x01);
		LCD_String(str3);
		LCD_Cmd(0Xc0);
		LCD_String(str4);
		x=1;
		}
		else{
		LCD_Cmd(0x01);

		LCD_String(str10);
		_delay_ms(1000);
		LCD_Cmd(0x01);

		}
		break;
		case '3':
		LCD_Cmd(0x01);
		LCD_String(str2);
		for (int e=0;e<2;e++)
		{
		arr2[e]=GetKey();
		}
		if(arr2[0]=='6' && arr2[1]=='5'){
		LCD_Cmd(0x01);
		LCD_String(str1);
		_delay_ms(1500);
		LCD_Cmd(0x01);
		LCD_String(str3);
		LCD_Cmd(0Xc0);
		LCD_String(str4);
		x=1;
		}
		else{
		LCD_Cmd(0x01);

		LCD_String(str10);
		_delay_ms(1000);
		}
		break;
		case '4':
		LCD_Cmd(0x01);
		LCD_String(str2);
		for (int r=0;r<2;r++)
		{
		arr3[r]=GetKey();
		}
		if(arr3[0]=='7' && arr3[1]=='8'){
		LCD_Cmd(0x01);
		LCD_String(str1);
		_delay_ms(1500);
		LCD_Cmd(0x01);
		LCD_String(str3);
		LCD_Cmd(0Xc0);
		LCD_String(str4);
		x=1;
		}
		else{
		LCD_Cmd(0x01);

		LCD_String(str10);
		_delay_ms(1000);
		}
		break;
		}
		}
		}
		///////////////////////////////////////////////////////////////
		
		///////////////////////////////////////////////////////////
		if(x==1){
		data2 = GetKey();
		if(data2 != 0){
		switch(data2 ){
		case '1':
		PORTD ^=(1<<7);
		LCD_Cmd(0x01);
		LCD_String(str6);
		_delay_ms(1000);
		x=0;
		LCD_Cmd(0x01);
		break;
		case '2':
		PORTD ^=(1<<6);
		LCD_Cmd(0x01);
		LCD_String(str6);
		_delay_ms(1000);
		x=0;
		LCD_Cmd(0x01);
		break;
		case '3':
		PORTD ^=(1<<2);
		LCD_Cmd(0x01);
		LCD_String(str6);
		_delay_ms(1000);
		x=0;
		LCD_Cmd(0x01);
		break;
		case '4':
		PORTD ^=(1<<4);
		LCD_Cmd(0x01);
		LCD_String(str6);
		_delay_ms(1000);
		x=0;
		LCD_Cmd(0x01);
		break;
		case '5':
		PORTD ^=(1<<3);
		LCD_Cmd(0x01);
		LCD_String(str6);
		_delay_ms(1000);
		x=0;
		LCD_Cmd(0x01);
		break;
		case '6':
	PORTD ^=(1<<2);
		LCD_Cmd(0x01);
		LCD_String(str6);
		_delay_ms(1000);
		x=0;
		LCD_Cmd(0x01);
		break;
				

		}
		}
		
		
		}
		}
		}
		
ISR(USART_RXC_vect){
if (UDR=='1')
{
	
	Uart_String(str7);
	Uart_String(str8);
	LCD_String(str20);
	for(int i=0;i<3;i++){
		a= Uart_Receive();
		if (a== '1'){
			Uart_String(str9);
			s=1;
			break;
		}
		else{
			Uart_String(str10);
			Uart_Receive();
			b++;
			if(b==4){
				PORTB |=(1<<7);
				Uart_String(str12);
				Uart_Receive();
				if(Uart_Receive()== '3'){
					PORTB &=~ (1<<7);
				}
			}
		}
	}
	
	while (s==1){
		Uart_String(str11);
		z=Uart_Receive();
		switch (z){
			case '1':
			/*dcmotor_rotate(dcmotor_cw);
			_delay_ms(5000);
			dcmotor_rotate(dcmotor_stop);
			*/
			Timer1_Fast_PWM_Init(187);
			break;
			case '2':
		/*	dcmotor_rotate(dcmotor_acw);
			_delay_ms(5000);
			dcmotor_rotate(dcmotor_stop);*/
					Timer1_Fast_PWM_Init(124);

			break;
			case '3':
			add_user1();
			LCD_Cmd(0x01);
			LCD_String(str13);
			break;
			case '4':
			add_user2();
			LCD_Cmd(0x01);
			LCD_String(str14);
			break;
			case '5':
			add_user3();
			LCD_Cmd(0x01);
			LCD_String(str15);
			break;
			case '6':
			LCD_Cmd(0x01);
			LCD_String(str19);
			s=0;
			_delay_ms(1000);
			LCD_Cmd(0x01);
			break;
		}
	}
}
}
