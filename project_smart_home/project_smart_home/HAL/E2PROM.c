/*
* E2PROM.c
*
* Created: 11/13/2021 7:39:18 PM
*  Author: user
*/

#include "E2PROM.h"
//0b10100000
void E2PROM_Write(uint8 WDeviceAdd,uint8 WLocationAdd,uint8 data){
	if(TWI_Start() == 0x08){
		if(TWI_Send(WDeviceAdd) == 0x18){
			if(TWI_Send(WLocationAdd) == 0x28){//from the master side it is data
				if(TWI_Send(data) == 0x28){
					TWI_Stop();
				}
			}
		}
	}
}

uint8 E2PROM_Read(uint8 DeviceAdd,uint8 LocationAdd){
	uint8 wDeviceAdd = (DeviceAdd & 0xFE);//clear first bit
	uint8 rDeviceAdd = (DeviceAdd | (1<<0));//set first bit
	uint8 readValue = 0;
	if(TWI_Start() == 0x08){
		if(TWI_Send(wDeviceAdd) == 0x18){
			if(TWI_Send(LocationAdd) == 0x28){
				if(TWI_Start() == 0x10){
					if(TWI_Send(rDeviceAdd) == 0x40){
						TWI_Read_NACK(&readValue);
						TWI_Stop();
					}
				}
			}
		}
	}
	return readValue;
}