/*
 * ASCII_14_Segm.h
 *
 *  Created on: Sep 3, 2025
 *      Author: Mateusz
 */

/*
 *  Project     Segmented LED Display - ASCII Library
 *  @author     David Madison
 *  @link       github.com/dmadison/Segmented-LED-Display-ASCII
 *  @license    MIT - Copyright (c) 2017 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

/*
 * Special thanks to @hans-jorg:
 * https://github.com/dmadison/LED-Segment-ASCII/issues/2
 *
 */


#ifndef HLD336WA_INC_HLD336WA_SEGM_H_
#define HLD336WA_INC_HLD336WA_SEGM_H_

#ifdef __cplusplus // plik.h
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Public define -------------------------------------------------------------*/

/* Public macros -------------------------------------------------------------*/

/* Public typedef ------------------------------------------------------------*/

/* Public constants ----------------------------------------------------------*/

#define _G_HALF (0b1 << 7) // there is additional "dot" in the middle of my screen (with idx 7). I add it to G1 and G2

#define _DP (0b1 << 15)
#define _L  (0b1 << 10)
#define _M  (0b1 << 11)
#define _N  (0b1 << 12)
#define _K  (0b1 << 4)
#define _J  (0b1 << 3)
#define _H  (0b1 << 2)
#define _G2 ((0b1 << 8) + _G_HALF) // + additional "dot"
#define _G1 ((0b1 << 6) + _G_HALF) // + additional "dot"
#define _F  (0b1 << 1)
#define _E  (0b1 << 9)
#define _D  (0b1 << 14)
#define _C  (0b1 << 13)
#define _B  (0b1 << 5)
#define _A  (0b1 << 0)

const uint16_t FourteenSegmentASCII[128] = {
			 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, /* margin */
			 0,                                           /* (space) */
			  _DP |_C |_B ,                                   /* ! */
			  _J |_B ,                                        /* " */
			  _M |_J |_G2 |_G1 |_D |_C |_B ,                  /* # */
			  _M |_J |_G2 |_G1 |_F |_D |_C |_A ,              /* $ */
			  _N |_M |_L |_K |_J |_H |_G2 |_G1 |_F |_C ,      /* % */
			  _N |_J |_H |_G1 |_E |_D |_A ,                   /* & */
			  _J ,                                            /* ' */
			  _N |_K ,                                        /* ( */
			  _L |_H ,                                        /* ) */
			  _N |_M |_L |_K |_J |_H |_G2 |_G1 ,              /* * */
			  _M |_J |_G2 |_G1 ,                              /* + */
			  _L ,                                            /* , */
			  _G2 |_G1 ,                                      /* - */
			  _DP ,                                           /* . */
			  _L |_K ,                                        /* / */
			  _L |_K |_F |_E |_D |_C |_B |_A ,                /* 0 */
			  _K |_C |_B ,                                    /* 1 */
			  _G2 |_G1 |_E |_D |_B |_A ,                      /* 2 */
			  _G2 |_D |_C |_B |_A ,                           /* 3 */
			  _G2 |_G1 |_F |_C |_B ,                          /* 4 */
			  _N |_G1 |_F |_D |_A ,                           /* 5 */
			  _G2 |_G1 |_F |_E |_D |_C |_A ,                  /* 6 */
			  _C |_B |_A ,                                    /* 7 */
			  _G2 |_G1 |_F |_E |_D |_C |_B |_A ,              /* 8 */
			  _G2 |_G1 |_F |_D |_C |_B |_A ,                  /* 9 */
			  _M |_J ,                                        /* : */
			  _L |_J ,                                        /* ; */
			  _N |_K |_G1 ,                                   /* < */
			  _G2 |_G1 |_D ,                                  /* = */
			  _L |_H |_G2 ,                                   /* > */
			  _DP |_M |_G2 |_B |_A ,                          /* ? */
			  _J |_G2 |_F |_E |_D |_B |_A ,                   /* @ */
			  _G2 |_G1 |_F |_E |_C |_B |_A ,                  /* A */
			  _M |_J |_G2 |_D |_C |_B |_A ,                   /* B */
			  _F |_E |_D |_A ,                                /* C */
			  _M |_J |_D |_C |_B |_A ,                        /* D */
			  _G1 |_F |_E |_D |_A ,                           /* E */
			  _G1 |_F |_E |_A ,                               /* F */
			  _G2 |_F |_E |_D |_C |_A ,                       /* G */
			  _G2 |_G1 |_F |_E |_C |_B ,                      /* H */
			  _M |_J |_D |_A ,                                /* I */
			  _E |_D |_C |_B ,                                /* J */
			  _N |_K |_G1 |_F |_E ,                           /* K */
			  _F |_E |_D ,                                    /* L */
			  _K |_H |_F |_E |_C |_B ,                        /* M */
			  _N |_H |_F |_E |_C |_B ,                        /* N */
			  _F |_E |_D |_C |_B |_A ,                        /* O */
			  _G2 |_G1 |_F |_E |_B |_A ,                      /* P */
			  _N |_F |_E |_D |_C |_B |_A ,                    /* Q */
			  _N |_G2 |_G1 |_F |_E |_B |_A ,                  /* R */
			  _G2 |_G1 |_F |_D |_C |_A ,                      /* S */
			  _M |_J |_A ,                                    /* T */
			  _F |_E |_D |_C |_B ,                            /* U */
			  _L |_K |_F |_E ,                                /* V */
			  _N |_L |_F |_E |_C |_B ,                        /* W */
			  _N |_L |_K |_H ,                                /* X */
			  _G2 |_G1 |_F |_D |_C |_B ,                      /* Y */
			  _L |_K |_D |_A ,                                /* Z */
			  _F |_E |_D |_A ,                                /* [ */
			  _N |_H ,                                        /* \ */
			  _D |_C |_B |_A ,                                /* ] */
			  _N |_L ,                                        /* ^ */
			  _D ,                                            /* _ */
			  _H ,                                            /* ` */
			  _M |_G1 |_E |_D ,                               /* a */
			  _N |_G1 |_F |_E |_D ,                           /* b */
			  _G2 |_G1 |_E |_D ,                              /* c */
			  _L |_G2 |_D |_C |_B ,                           /* d */
			  _L |_G1 |_E |_D ,                               /* e */
			  _M |_K |_G2 |_G1 ,                              /* f */
			  _K |_G2 |_D |_C |_B ,                           /* g */
			  _M |_G1 |_F |_E ,                               /* h */
			  _M ,                                            /* i */
			  _L |_J |_E ,                                    /* j */
			  _N |_M |_K |_J ,                                /* k */
			  _F |_E ,                                        /* l */
			  _M |_G2 |_G1 |_E |_C ,                          /* m */
			  _M |_G1 |_E ,                                   /* n */
			  _G2 |_G1 |_E |_D |_C ,                          /* o */
			  _H |_G1 |_F |_E ,                               /* p */
			  _K |_G2 |_C |_B ,                               /* q */
			  _G1 |_E ,                                       /* r */
			  _N |_G2 |_D ,                                   /* s */
			  _G1 |_F |_E |_D ,                               /* t */
			  _E |_D |_C ,                                    /* u */
			  _L |_E ,                                        /* v */
			  _N |_L |_E |_C ,                                /* w */
			  _N |_L |_K |_H ,                                /* x */
			  _J |_G2 |_D |_C |_B ,                           /* y */
			  _L |_G1 |_D ,                                   /* z */
			  _L |_H |_G1 |_D |_A ,                           /* { */
			  _M |_J ,                                        /* | */
			  _N |_K |_G2 |_D |_A ,                           /* } */
			  _L |_K |_G2 |_G1 ,                              /* ~ */
			 0                                               /* (del) */
};


/* Public variables ----------------------------------------------------------*/

/* Public function declaration -----------------------------------------------*/

#ifdef __cplusplus // plik.h
}
#endif

#endif /* HLD336WA_INC_HLD336WA_SEGM_H_ */
