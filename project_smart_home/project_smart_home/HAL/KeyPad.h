/*
* KeyPad.h
*
* Created: 10/15/2021 7:19:49 PM
*  Author: user
*/


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

#define r0 DIO_ChannelA4
#define r1 DIO_ChannelA5
#define r2 DIO_ChannelA6
#define r3 DIO_ChannelA7

#define c0 DIO_ChannelB0
#define c1 DIO_ChannelA1
#define c2 DIO_ChannelA2
#define c3 DIO_ChannelA3

Uint8 GetKey(void);
Uint8 GetKey2(void);


#endif /* KEYPAD_H_ */