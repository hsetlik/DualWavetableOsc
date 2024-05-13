/*
 * Wavetable.h
 *
 *  Created on: May 11, 2024
 *      Author: hayden
 */

#ifndef INC_WAVETABLE_H_
#define INC_WAVETABLE_H_

#include "stm32f4xx_hal.h"

// tentatively storing our waves as 16-bit samples,

#define WAVE_POINTS 512

// this means that each wavetable takes up 512 * 16 bits = 1024 bytes
// We have 32kB of RAM total, but let's reserve ~4kB for the stack and any other
// memory needs. Each channels gets half of that remaining 28kB for a maximum
// of 13 wave shapes per channel

class Wave
{
private:
	int16_t  data[WAVE_POINTS];

};




#endif /* INC_WAVETABLE_H_ */
