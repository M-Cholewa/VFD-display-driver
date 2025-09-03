/*
 * HLD336WA_Dev.h
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */


#ifndef HLD336WA_INC_HLD336WA_DEV_H_
#define HLD336WA_INC_HLD336WA_DEV_H_

#ifdef __cplusplus // plik.h
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "HLD336WA.h"

/* Public define -------------------------------------------------------------*/

/* Public macros -------------------------------------------------------------*/

/* Public typedef ------------------------------------------------------------*/

/* Public constants ----------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function declaration -----------------------------------------------*/
ErrorStatus HLD336WADev_Init(void);
ErrorStatus HLD336WADev_ProcessingTask(void);

#ifdef __cplusplus // plik.h
}
#endif

#endif /* HLD336WA_INC_HLD336WA_DEV_H_ */
