/*
 * dcmotor.h
 *
 * Created: 12/6/2021 2:07:47 PM
 *  Author: Kerolos
 */ 


#ifndef DCMOTOR_H_
#define DCMOTOR_H_
#include "DIO.h"

typedef enum{
	dcmotor_stop,
	dcmotor_cw,
	dcmotor_acw
	}dcmotor_state;
void dcmotor_init(void);
void dcmotor_rotate(dcmotor_state state );


#endif /* DCMOTOR_H_ */