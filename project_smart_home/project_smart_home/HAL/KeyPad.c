/*
* KeyPad.c
*
* Created: 10/15/2021 7:23:53 PM
*  Author: user
*/

#include "KeyPad.h"

Uint8 KeyPadRow[4] = {r0,r1,r2,r3};
Uint8 KeyPadCol[4] = {c0,c1,c2,c3};
Uint8 KeyPad[4][4] = {{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'C','0','=','+'}};

Uint8 GetKey(void){

	Uint8 x=0;
	while(x ==0){
	for(Uint8 w=0;w<4;w++){//PORTD = 0b1111 1111
		DIO_Write(KeyPadRow[w],STD_High);
		DIO_Write(KeyPadCol[w],STD_High);
	}
	for(Uint8 i=0;i<4;i++){
		DIO_Write(KeyPadRow[i],STD_Low);//PORTD = 0b1111 1110 //PORTD = 0b1111 1101
		for(Uint8 j=0;j<4;j++){
			if(DIO_Read(KeyPadCol[j]) == STD_Low){
				while(DIO_Read(KeyPadCol[j]) == STD_Low);
				return KeyPad[i][j];
				x=1;
			}
		}
		DIO_Write(KeyPadRow[i],STD_High);//PORTD = 0b1111 1111
	}
//	return 0;
}
}
Uint8 GetKey2(void){

	
		for(Uint8 w=0;w<4;w++){//PORTD = 0b1111 1111
			DIO_Write(KeyPadRow[w],STD_High);
			DIO_Write(KeyPadCol[w],STD_High);
		}
		for(Uint8 i=0;i<4;i++){
			DIO_Write(KeyPadRow[i],STD_Low);//PORTD = 0b1111 1110 //PORTD = 0b1111 1101
			for(Uint8 j=0;j<4;j++){
				if(DIO_Read(KeyPadCol[j]) == STD_Low){
					while(DIO_Read(KeyPadCol[j]) == STD_Low);
					return KeyPad[i][j];
				}
			}
			DIO_Write(KeyPadRow[i],STD_High);//PORTD = 0b1111 1111
		}
			return 0;
	}

