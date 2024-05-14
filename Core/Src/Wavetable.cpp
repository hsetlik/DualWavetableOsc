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



