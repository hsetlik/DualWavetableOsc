/*
 * StatusLEDs.cpp
 *
 *  Created on: May 13, 2024
 *      Author: hayden
 */
#include "StatusLEDs.h"

StatusLEDs::StatusLEDs(GPIO_TypeDef* gpio, uint16_t red, uint16_t green) :
ioType(gpio),
redPin(red),
grnPin(green),
redState(0),
grnState(0),
lastRedToggle(0),
lastGreenToggle(0),
status(Waiting)
{

}


void StatusLEDs::setRed(uint8_t state)
{
	if(redState != state){
		HAL_GPIO_TogglePin(ioType, redPin);
		redState = state;
		lastRedToggle = HAL_GetTick();
	}
}

void StatusLEDs::setGrn(uint8_t state)
{
	if(grnState != state){
		HAL_GPIO_TogglePin(ioType, grnPin);
		grnState = state;
		lastGrnToggle = HAL_GetTick();
	}

}

void StatusLEDs::tick(uint32_t ms)
{
	switch(status){
		case Normal: { // red is off and green in on constantly
			setRed(0);
			// turn the green LED off after 30 secs to save power
			if(ms < 30000)
				setGrn(1);
			else
				setGrn(0);
			break;
		}
		case Waiting: { // in wait mode, red is on and green blinks slowly
			setRed(1);
			if(ms - lastGrnToggle >= SLOW_BLINK_MS){
				uint8_t newState = 1;
				if(grnState)
					newState = 0;
				setGrn(newState);
			}

			break;
		}
		case Error: { // both LEDs blink quickly
			if(ms - lastRedToggle >= FAST_BLINK_MS){
				uint8_t newState = 1;
				if(redState)
					newState = 0;
				setRed(newState);
				setGrn(newState);
			}
			break;
		}
		default:
			break;
	}
}




