/*
* LCD.c
*
* Created: 10/9/2021 8:35:11 PM
*  Author: user
*/

#include "LCD.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void LCD_Init(void){
	DIO_Init();
	DIO_Write(LCD_RW,STD_Low);
	_delay_ms(20);
	LCD_Cmd(0x33);
	LCD_Cmd(0x32);
	LCD_Cmd(0x28);
	LCD_Cmd(0x06);
	LCD_Cmd(0x0C);
	LCD_Cmd(0x01);

}
void LCD_Cmd(Uint8 cmd){//0x33
	LCD_DataReg = (LCD_DataReg & 0x0F) | (cmd & 0xF0);// send high nipple in data
	DIO_Write(LCD_RS,STD_Low);
	DIO_Write(LCD_E,STD_Low);
	_delay_us(50);
	DIO_Write(LCD_E,STD_High);
	
	_delay_ms(5);
	
	LCD_DataReg = (LCD_DataReg & 0x0F) | (cmd<<4);// send low nipple in data
	DIO_Write(LCD_E,STD_Low);
	_delay_us(50);
	DIO_Write(LCD_E,STD_High);
	
	_delay_ms(2);
}
void LCD_Char(Uint8 data){
	LCD_DataReg = (LCD_DataReg & 0x0F) | (data & 0xF0);// send high nipple in data
	DIO_Write(LCD_RS,STD_High);
	DIO_Write(LCD_E,STD_Low);
	_delay_us(50);
	DIO_Write(LCD_E,STD_High);
	
	_delay_ms(5);
	
	LCD_DataReg = (LCD_DataReg & 0x0F) | (data<<4);// send low nipple in data
	DIO_Write(LCD_E,STD_Low);
	_delay_us(50);
	DIO_Write(LCD_E,STD_High);
	
	_delay_ms(2);
}

void LCD_String(int8 * string){
	Uint8 count = 0;
	while(string[count] != '\0'){
		LCD_Char(string[count]);
		count++;
	}
}

void LCD_SetPos(Uint8 lineNo,Uint8 charPos){
	Uint8 SendCmd = 0;
	switch (lineNo)
	{
		case 1:
		SendCmd = 0x80 | (charPos & 0x0F);
		LCD_Cmd(SendCmd);
		break;
		case 2:
		SendCmd = 0xC0 | (charPos & 0x0F);
		LCD_Cmd(SendCmd);
		break;
	}
}

void LCD_CharPos(Uint8 data,Uint8 lineNo,Uint8 charPos){
	LCD_SetPos(lineNo,charPos);
	LCD_Char(data);
}
void LCD_StringPos(int8 * string,Uint8 lineNo,Uint8 charPos){
	LCD_SetPos(lineNo,charPos);
	LCD_String(string);
}

void LCD_CustomeChar(Uint8 loc,Uint8 * msg){
	Uint8 i = 0;
	if(loc<8){
		LCD_Cmd(0x40 + (loc*8));
		for (i=0;i<8;i++)
		{
			LCD_Char(msg[i]);
		}
	}
}