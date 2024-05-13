/*
 * StatusLEDs.h
 *
 *  Created on: May 13, 2024
 *      Author: hayden
 */

#ifndef INC_STATUSLEDS_H_
#define INC_STATUSLEDS_H_

#define SLOW_BLINK_MS 850
#define FAST_BLINK_MS 300

// these forward declarations get implemented and attached to the hardware in main.c
void status_StartWait();
void status_Normal();
void status_Error();

enum DeviceStatus : uint8_t
{
	Normal,
	Waiting,
	Error
};

#include "stm32f4xx_hal.h"

class StatusLEDs
{
private:
	// for the HAL calls
	GPIO_TypeDef* const ioType;
	const uint16_t redPin;
	const uint16_t grnPin;

	// the current state of each LED
	uint8_t redState;
	uint8_t grnState;
	uint32_t lastRedToggle;
	uint32_t lastGrnToggle;

	//
	DeviceStatus status;

	// helpers for the GPIO
	void setRed(uint8_t state);
	void setGrn(uint8_t state);
public:
	StatusLEDs(GPIO_TypeDef* gpio, uint16_t red, uint16_t green);
	void setStatus(DeviceStatus s) { status = s;  }
	void tick(uint32_t ms);




};




#endif /* INC_STATUSLEDS_H_ */
