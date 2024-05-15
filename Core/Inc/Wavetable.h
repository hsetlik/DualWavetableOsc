/*
 * Wavetable.h
 *
 *  Created on: May 11, 2024
 *      Author: hayden
 */

#ifndef INC_WAVETABLE_H_
#define INC_WAVETABLE_H_

#include "stm32f4xx_hal.h"
#include "Util.h"

// tentatively storing our waves as 16-bit samples,


// this means that each wavetable takes up 512 * 16 bits = 1024 bytes
// We have 32kB of RAM total, but let's reserve ~4kB for the stack and any other
// memory needs. Each channels gets half of that remaining 28kB for a maximum
// of 13 wave shapes per channel

#define WAVE_POINTS 512
#define MAX_WAVE_FRAMES 13
typedef uint16_t wave_idx_t;
// alias for a single wavetable worth of data
typedef int16_t wave_arr_t[WAVE_POINTS];

enum WavetableGen {
	TriangleSaw5,
	TriangleSaw10,
	SinePulse10,
	PWM10
};

#ifdef __cplusplus

// this is just and array wrapper. wacky oop stuff strictly forbidden!
class WaveFrame
{
private:
	wave_arr_t  data;
	// helpers
	static void createPulseWave(int16_t* wave, float dutyCycle);
	static void createSawWave(int16_t* wave);
	static void createTriangleWave(int16_t* wave);
	static void createSineWave(int16_t* wave);
public: //accessors for
	WaveFrame(){}
	float getFloat(wave_idx_t idx);
	void setFloat(wave_idx_t idx, float value);
	void setInt16(wave_idx_t idx, int16_t value);
	int16_t* getBits(wave_idx_t idx);
	// builder function
	static void generateWavetables(WaveFrame* frm, uint8_t* numTables, WavetableGen gen);
};


// main object for each of the voices
class WavetableVoice
{
private:
	WaveFrame frames[MAX_WAVE_FRAMES];
	uint8_t numFrames;
public:
	WavetableVoice(WavetableGen g=PWM10);
};
#endif //__cplusplus




#endif /* INC_WAVETABLE_H_ */
