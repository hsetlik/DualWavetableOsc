/*
 * Util.cpp
 *
 *  Created on: May 13, 2024
 *      Author: hayden
 */
#include "Util.h"

template<typename T>
T Util::lerp(T a,T b, float ratio){
	T diff = (T)((float)(b - a) * ratio);
	return a + diff;
}

template <typename T>
T Util::valueAtPhase(T* arr, uint16_t len, float phase){
	uint16_t lower = (uint16_t)(phase * (float) len);
	uint16_t upper = (lower + 1) % len;
	float ratio = (phase * (float)len) - (float)lower;
	return Util::lerp(arr[lower], arr[upper], ratio);
}




