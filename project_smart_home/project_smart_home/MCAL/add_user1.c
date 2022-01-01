/*
 * add_user1.c
 *
 * Created: 12/6/2021 3:02:16 AM
 *  Author: Kerolos
 */ 
#include "add_user.h"
Uint8 password1 =56;
Uint8 password2 = 43;
Uint8 password3 = 76;

void add_user1(void){
	E2PROM_Write(0b10100000,0b00000011,password1);
		E2PROM_Read(0b10100000,0b00000011);

}
void add_user2(void){
	E2PROM_Write(0b10100000,0b00000111,password2);
	E2PROM_Read(0b10100000,0b00000111);

}
void add_user3(void){
	E2PROM_Write(0b10100000,0b00001111,password3);
	E2PROM_Read(0b10100000,0b00001111);

}