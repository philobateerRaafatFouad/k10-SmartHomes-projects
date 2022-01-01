/*
 * ADC.h
 *
 * Created: 10/22/2021 9:23:43 PM
 *  Author: user
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "DIO.h"
#include "LCD.h"

void ADC_Init(void);
unsigned short ADC_Read(unsigned char channel);




#endif /* ADC_H_ */