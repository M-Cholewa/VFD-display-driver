/*
 * HLD336WA_State.h
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */

#ifndef HLD336WA_INC_HLD336WA_STATE_H_
#define HLD336WA_INC_HLD336WA_STATE_H_

#ifdef __cplusplus // plik.h
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx.h"

/* Public define -------------------------------------------------------------*/

/* Public macros -------------------------------------------------------------*/

/* Public typedef ------------------------------------------------------------*/

typedef union
{
	struct
	{
		uint8_t P1 :1;
		uint8_t P2 :1;
		uint8_t P3 :1;
		uint8_t P4 :1;
		uint8_t P5 :1;
		uint8_t P6 :1;
		uint8_t P7 :1;
		uint8_t P8 :1;
		uint8_t P9 :1;
		uint8_t P10 :1;
		uint8_t P11 :1;
		uint8_t P12 :1;
		uint8_t P13 :1;
		uint8_t P14 :1;
		uint8_t P15 :1;
		uint8_t P16 :1;
		uint8_t P17 :1;
		uint8_t P18 :1;
		uint8_t P19 :1;
		uint8_t P20 :1;
	} Anode;

	uint32_t Val;

} ScreenAnode_u;

/* Public constants ----------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function declaration -----------------------------------------------*/

void HLD336WA_State_SetAnodes(uint8_t grid, uint32_t val);
uint32_t HLD336WA_State_GetAnodes(uint8_t grid);

#ifdef __cplusplus // plik.h
}
#endif

#endif /* HLD336WA_INC_HLD336WA_STATE_H_ */
