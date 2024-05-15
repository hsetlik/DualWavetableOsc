/*
 * Wavetable.cpp
 *
 *  Created on: May 11, 2024
 *      Author: hayden
 */
#include "Wavetable.h"

float WaveFrame::getFloat(wave_idx_t idx)
{
	return (float)data[idx] / 32768.0f;
}


void WaveFrame::setFloat(wave_idx_t idx, float value)
{
	data[idx] = (int16_t)(value * 32768.0f);
}


void WaveFrame::setInt16(wave_idx_t idx, int16_t value)
{
	data[idx] = value;
}


int16_t* WaveFrame::getBits(wave_idx_t idx)
{
	return &data[idx];
}

//-------------------------------------------------------------------------
void WaveFrame::createPulseWave(int16_t* wave, float dutyCycle)
{
	const float dPhase = 1.0f / (float)WAVE_POINTS;
	float phase = 0.0f;
	for(wave_idx_t i = 0; i < WAVE_POINTS; i++){
		phase += dPhase;
		if(phase < dutyCycle)
			wave[i] = -32768;
		else
			wave[i] = 32768;
	}

}

void WaveFrame::createSawWave(int16_t* wave)
{
	float value = 1.0f;
	const float dValue = 2.0f / (float)WAVE_POINTS;
	for(wave_idx_t i = 0; i < WAVE_POINTS; i++){
		value -= dValue;
		wave[i] = (int16_t)(value * 32768.0f);
	}
}

void WaveFrame::createTriangleWave(int16_t* wave)
{
	const float dPhase = 1.0f / (float)WAVE_POINTS;
	float phase = 0.0f;
	float value = 1.0f;
	const float dValue = 4.0f / (float)WAVE_POINTS;
	for(wave_idx_t i = 0; i < WAVE_POINTS; i++){

		if(phase >= 0.5f)
			value += dValue;
		else
			value -= dValue;
		phase += dPhase;
		wave[i] = (int16_t)(value * 32768.0f);
	}
}

void WaveFrame::createSineWave(int16_t* wave)
{
	const float fullRads = M_PI * 2.0f;
	const float dRads = fullRads / (float)WAVE_POINTS;
	float angle = 0.0f;
	for(wave_idx_t i = 0; i < WAVE_POINTS; i++)
	{
		wave[i] = (int16_t)(sinf(angle) * 32768.0f);
		angle += dRads;
	}
}


void WaveFrame::generateWavetables(WaveFrame* frm, uint8_t* numTables, WavetableGen gen)
{
	*numTables = 0;
	switch(gen){
	case TriangleSaw5:
	{
		const float dPhase = 1.0f / 5.0f;
		float phase = 0.0f;
		int16_t triangle[WAVE_POINTS];
		createTriangleWave(triangle);
		int16_t saw[WAVE_POINTS];
		createSawWave(saw);
		for(uint8_t i = 0; i < 5; i++){
			for(wave_idx_t s = 0; s < WAVE_POINTS; s++){
				frm[i].setInt16(s, Util::lerp(triangle[s], saw[s], phase));
			}
			phase += dPhase;
			*numTables += 1;
		}
		break;
	}
	case TriangleSaw10:
	{
		const float dPhase = 1.0f / 10.0f;
		float phase = 0.0f;
		int16_t triangle[WAVE_POINTS];
		createTriangleWave(triangle);
		int16_t saw[WAVE_POINTS];
		createSawWave(saw);
		for(uint8_t i = 0; i < 10; i++){
			for(wave_idx_t s = 0; s < WAVE_POINTS; s++){
				frm[i].setInt16(s, Util::lerp(triangle[s], saw[s], phase));
			}
			phase += dPhase;
			*numTables += 1;
		}
		break;
	}
	case SinePulse10:
	{
		const float dPhase = 1.0f / 10.0f;
		float phase = 0.0f;
		int16_t sine[WAVE_POINTS];
		createSineWave(sine);
		int16_t pulse[WAVE_POINTS];
		createPulseWave(pulse, 0.5f);
		for(uint8_t i = 0; i < 10; i++){
			for(wave_idx_t s = 0; s < WAVE_POINTS; s++){
				frm[i].setInt16(s, Util::lerp(sine[s], pulse[s], phase));
			}
			phase += dPhase;
			*numTables += 1;
		}
		break;
	}
	case PWM10:
	{
		const float dPhase = 1.0f / 10.0f;
		float phase = 0.0f;
		int16_t pulse1[WAVE_POINTS];
		createPulseWave(pulse1, 0.15f);
		int16_t pulse2[WAVE_POINTS];
		createPulseWave(pulse2, 0.85f);
		for(uint8_t i = 0; i < 10; i++){
			for(wave_idx_t s = 0; s < WAVE_POINTS; s++){
				frm[i].setInt16(s, Util::lerp(pulse1[s], pulse2[s], phase));
			}
			phase += dPhase;
			*numTables += 1;
		}
		break;
	}
	}

}



