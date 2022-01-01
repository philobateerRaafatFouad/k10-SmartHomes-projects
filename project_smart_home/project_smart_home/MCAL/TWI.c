/*
* TWI.c
*
* Created: 11/12/2021 9:37:09 PM
*  Author: user
*/

#include "TWI.h"

void TWI_Init(uint8 address){
	TWAR = address;//TO SET THE DEVICE ADDRESS
	TWBR = MyTWBR;//TO SET THE CLOCK
}
uint8 TWI_Start(void){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while (!(TWCR & (1<<TWINT)));//waiting the flag to be one
	return TWI_Status();
}
void TWI_Stop(void){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}
uint8 TWI_Status(void){
	return (TWSR & (0xF8));//to get the status
}
uint8 TWI_Send(uint8 data){
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);//clear the flag and enable TWI
	while (!(TWCR & (1<<TWINT)));//waiting the flag to be one
	return TWI_Status();
}
uint8 TWI_Read_ACK(uint8 * data){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);//clear the flag & enable TWI & ACK.
	while (!(TWCR & (1<<TWINT)));//waiting the flag to be one
	*data  = TWDR;
	return TWI_Status();
}
uint8 TWI_Read_NACK(uint8 * data){
	TWCR = (1<<TWINT)|(1<<TWEN);//clear the flag & enable TWI
	while (!(TWCR & (1<<TWINT)));//waiting the flag to be one
	*data  = TWDR;
	return TWI_Status();
}