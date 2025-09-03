/*
 * AssertUtils.h
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */


#ifndef UTILS_ASSERTUTILS_H_
#define UTILS_ASSERTUTILS_H_

#ifdef __cplusplus // plik.h
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Public define -------------------------------------------------------------*/

/* Public macros -------------------------------------------------------------*/

#ifndef ASSERT_PARAM
#define ASSERT_PARAM(_msg_, _expr_) do {	\
		if (!(_expr_)) {            		\
			return ERROR;         			\
		}                        			\
	} while (0)
#endif /* ASSERT_PARAM */

/* Public typedef ------------------------------------------------------------*/

/* Public constants ----------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function declaration -----------------------------------------------*/

#ifdef __cplusplus // plik.h
}
#endif

#endif /* UTILS_ASSERTUTILS_H_ */
