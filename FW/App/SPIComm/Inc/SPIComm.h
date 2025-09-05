/*
 * SPIComm.h
 *
 *  Created on: Sep 4, 2025
 *      Author: Mateusz
 */

#ifndef SPICOMM_INC_SPICOMM_H_
#define SPICOMM_INC_SPICOMM_H_

#ifdef __cplusplus // plik.h
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx.h"

/* Public define -------------------------------------------------------------*/

/* Public macros -------------------------------------------------------------*/

/* Public typedef ------------------------------------------------------------*/
typedef struct
{
	ErrorStatus (*Init)(void *arg);
	ErrorStatus (*Deinit)(void *arg);
	uint32_t (*GetAnodes)(uint8_t grid);
} SPIComm_ll_drv_t;

/* Public constants ----------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function declaration -----------------------------------------------*/
ErrorStatus SPIComm_Init(void);
uint32_t SPIComm_GetAnodes(uint8_t grid);
ErrorStatus SPIComm_ProcessingTask(void);

#ifdef __cplusplus // plik.h
}
#endif

#endif /* SPICOMM_INC_SPICOMM_H_ */
