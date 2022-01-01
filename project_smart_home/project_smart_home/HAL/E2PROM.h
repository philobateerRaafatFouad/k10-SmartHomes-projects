/*
 * E2PROM.h
 *
 * Created: 11/13/2021 7:39:33 PM
 *  Author: user
 */ 


#ifndef E2PROM_H_
#define E2PROM_H_

#include "TWI.h"

void E2PROM_Write(uint8 WDeviceAdd,uint8 WLocationAdd,uint8 data);
uint8 E2PROM_Read(uint8 DeviceAdd,uint8 LocationAdd);

#endif /* E2PROM_H_ */