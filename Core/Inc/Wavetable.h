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


// this means that each wavetable takes up 512 * 16 bits = 1024 bytes
// We have 32kB of RAM total, but let's reserve ~4kB for the stack and any other
// memory needs. Each channels gets half of that remaining 28kB for a maximum
// of 13 wave shapes per channel

#define WAVE_POINTS 512
#define MAX_WAVE_FRAMES 13
typedef uint16_t wave_idx_t;

enum WavetableGen {
	TriangleSaw5,
	TriangleSaw10,
	SineSquare10,
	PWM10
};

#ifdef __cplusplus

// this is just and array wrapper. wacky oop stuff strictly forbidden!
class WaveFrame
{
private:
	int16_t  data[WAVE_POINTS];
public: //accessors for
	WaveFrame(){}
	float getFloat(wave_idx_t idx);
	void setFloat(wave_idx_t idx, float value);
};


// main object for each of the voices
class WavetableVoice
{
private:
	WaveFrame frames[MAX_WAVE_FRAMES];


};
#endif //__cplusplus




#endif /* INC_WAVETABLE_H_ */
