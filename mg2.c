/*  This is the only file you need to edit, and the only functions you need to modify are:
 *  setLED
 *  initLED
 *  buttonPressed
 *  initButton
 */

#include "mg2.h"

#define RED PB1
#define GREEN PA7
#define BLUE PA3
#define BUTTON PB2
#define READBUTTON PINB & _BV(PB2)
#define SENSORPOWER PB0
#define CLK125 0x6 //Prescaler select bits for 64 division factor

void initADC()
{
	// First, make sure to turn on power to the sensors. Set pin B0 to be an output and to be on (logic high):
	DDRB |= _BV(SENSORPOWER);
	PORTB |= _BV(SENSORPOWER);

	// In this function you should set up and enable the ADC with the following characteristics:
	// Left adjust the result so that you can return 8-bit results easily
	ADCSRB = _BV(ADLAR);
	// Set the ADC prescalar to a division factor of 64 so that the ADC clock is 8 MHz/64 = 125 KHz
	ADCSRA = _BV(ADEN) | _BV(CLK125);
}

unsigned int readChannel(uint8_t channel)
{
	// Four lines:
	// Set analog input to your channel - hint, use regular =, not | or &
	ADMUX = channel;
	
    // start a conversion, 
	ADCSRA |= _BV(ADSC);
	// wait for the conversion to complete, 
	while(!(ADCSRA & _BV(ADIF)));
	ADCSRA |= _BV(ADIF);
	// and then return the result
	return ADCH;
}




/*  In the if-else statements here you should set the appropriate
    LED pin to high or low based on the input.  For example, if r
	is a value other than 0, the red element of the LED should be turned
	on. */
void setLED(int r, int g, int b)
{
	if(r) // True if r != 0.
	{
		PORTB &= ~_BV(RED); // Turn on RED by setting the output to low (because we are active low).
	}
	else
	{
		PORTB |= _BV(RED); // Turn off RED.
	}
	if(g)
	{
		PORTA &= ~_BV(GREEN); // Turn on GREEN.
	}
	else
	{
		PORTA |= _BV(GREEN); // Turn off GREEN.
	}
	if(b)
	{
		PORTA &= ~_BV(BLUE); // Turn on BLUE.
	}
	else
	{
		PORTA |= _BV(BLUE); // Turn off BLUE.
	}
}

/* In this function you should set the LED pins to be outputs and
   set them high to turn them off (because our LEDs are active low)  */
void initLED()
{
	// Set LED pin direction to output
	DDRB |= _BV(RED);
	DDRA |= _BV(GREEN);
	DDRA |= _BV(BLUE);

	// Start pins off active high (which corresponds to LED off)
	PORTB |= _BV(RED);
	PORTA |= _BV(GREEN);
	PORTA |= _BV(BLUE);	
}

/*  In this function you should set the button pin to be an input */
void initButton()
{
	DDRB &= ~_BV(BUTTON);
}

/*  In this function, return a non-zero value if the button was pressed, and 0
    if it is not pressed. */
int buttonPressed()
{
	if(READBUTTON)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


// You do not need to modify any code beyond this point
void initSystem()
{

	initLED();
	initButton();
	initADC();

}
