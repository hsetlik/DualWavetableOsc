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

enum DeviceStatus
{
	Normal,
	Waiting,
	Error
};

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
class StatusLEDs
{
private:
	// for the HAL calls
	GPIO_TypeDef* ioType;
	uint16_t redPin;
	uint16_t grnPin;

	// the current state of each LED
	uint8_t redState;
	uint8_t grnState;
	uint32_t lastRedToggle;
	uint32_t lastGrnToggle;

	// state
	uint8_t initializedFlag;
	DeviceStatus status;

	// helpers for the GPIO
	void setRed(uint8_t state);
	void setGrn(uint8_t state);
public:
	StatusLEDs();
	StatusLEDs(GPIO_TypeDef* gpio, uint16_t red, uint16_t green);
	void init(GPIO_TypeDef* gpio, uint16_t red, uint16_t green);
	void setStatus(DeviceStatus s) { status = s;  }
	void tick(uint32_t ms);
};
#endif //__cplusplus

// ok now we need to make this bogus c-compatible

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

typedef void* status_led_t;

EXTERNC status_led_t create_status_led();
EXTERNC void destroy_status_led(status_led_t leds);
EXTERNC void init_status_led(status_led_t led, GPIO_TypeDef* gpio, uint16_t red, uint16_t green);
EXTERNC void tick_status_led(status_led_t led, uint32_t ms);
EXTERNC void status_normal(status_led_t led);
EXTERNC void status_start_wait(status_led_t led);
EXTERNC void status_error(status_led_t led);



#undef EXTERNC




#endif /* INC_STATUSLEDS_H_ */
