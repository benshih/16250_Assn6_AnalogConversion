#ifndef __MINIGADGET2_H__
#define __MINIGADGET2_H__

#define __DELAY_BACKWARD_COMPATIBLE__

#include <avr/io.h>
#include <util/delay.h>

// You must define these for the program to work correctly
#define SENSOR1 0
#define SENSOR2 1
#define SENSOR3 4

// The rest stays the same
void initADC(void);
unsigned int readChannel(uint8_t );
void initLED(void);
void setLED(int,int,int);
void initButton(void);
int	 buttonPressed(void);

void initSystem(void);


#endif