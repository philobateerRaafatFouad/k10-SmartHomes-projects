/*
 * LCD.h
 *
 * Created: 10/9/2021 8:17:29 PM
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"

#define LCD_RS DIO_ChannelB1
#define LCD_RW DIO_ChannelB2
#define LCD_E DIO_ChannelB3

#define LCD_DataReg PORTC_Reg

void LCD_Init(void);
void LCD_Cmd(Uint8 cmd);
void LCD_Char(Uint8 data);
void LCD_String(int8 * string);
void LCD_SetPos(Uint8 lineNo,Uint8 charPos);
void LCD_CharPos(Uint8 data,Uint8 lineNo,Uint8 charPos);
void LCD_StringPos(int8 * string,Uint8 lineNo,Uint8 charPos);
void LCD_CustomeChar(Uint8 loc,Uint8 * msg);


#endif /* LCD_H_ */