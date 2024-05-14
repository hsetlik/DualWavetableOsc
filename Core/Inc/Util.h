/*
 * Util.h
 *
 *  Created on: May 13, 2024
 *      Author: hayden
 */

#ifndef INC_UTIL_H_
#define INC_UTIL_H_

#include "stm32f4xx_hal.h"


#ifdef __cplusplus
namespace Util
{
	// mandatory math stuff
	template <typename T>
	T lerp(T a, T b, float ratio);

	template <typename T>
	T valueAtPhase(T* arr, uint16_t len, float phase);
}
#endif //__cplusplus




#endif /* INC_UTIL_H_ */
