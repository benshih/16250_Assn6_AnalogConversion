#include "mg2.h"

void waitforbutton(void)
{
	while(!buttonPressed())
	{
		setLED(1,0,0);
		_delay_ms(50);
		setLED(0,0,0);
		_delay_ms(200);
	}
}

int main(void)
{
	unsigned int sensor1;
	unsigned int sensor2;
	unsigned int sensor3;
	unsigned int blink_time;
	
	initSystem();

	waitforbutton();

	while(1)
	{
		// Read in all three
		sensor1 = readChannel(SENSOR1);	
		sensor2 = readChannel(SENSOR2);
		sensor3 = readChannel(SENSOR3);
		blink_time = 255;
		// If sensor1 is being pulled down by something, set our blink time to it
		if(sensor1 < 250)
		{
			setLED(1,1,0);
			_delay_ms(blink_time*3);
			blink_time = sensor1;
		}
		// If sensor2 is being pulled down by something, set our blink time to it
		if(sensor2 < 250)
		{
			setLED(1,1,0);
			_delay_ms(blink_time*3);
			blink_time = sensor2;
		}
		// If sensor3 is being pulled down by something, set our blink time to it - note our preference is to sensor3 if multiple sensors are plugged in
		if(sensor3 < 250)
		{
			blink_time = sensor3;
			setLED(1,1,0);
			_delay_ms(blink_time*3);
		}
		
		if(blink_time != 255) {
			setLED(1,1,1);
			_delay_ms(blink_time*3);
			setLED(0,0,0);
			_delay_ms(blink_time*3);
		}
	}
	return 0;
}