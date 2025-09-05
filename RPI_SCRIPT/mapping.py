#again thanks to github.com/dmadison/Segmented-LED-Display-ASCII

_G_HALF =  (0b1 << 7) # there is additional "dot" in the middle of my screen (with idx 7). I add it to G1 and G2
_DP =  (0b1 << 15)
_L =   (0b1 << 10)
_M =   (0b1 << 11)
_N =   (0b1 << 12)
_K =   (0b1 << 4)
_J =   (0b1 << 3)
_H =   (0b1 << 2)
_G2 =  ((0b1 << 8) + _G_HALF) # + additional "dot"
_G1 =  ((0b1 << 6) + _G_HALF) # + additional "dot"
_F =   (0b1 << 1)
_E =   (0b1 << 9)
_D =   (0b1 << 14)
_C =   (0b1 << 13)
_B =   (0b1 << 5)
_A =   (0b1 << 0)


itms = [
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, # margin */
0,                                              # (space) */
_DP |_C |_B ,                                   # ! */
_J |_B ,                                        # " */
_M |_J |_G2 |_G1 |_D |_C |_B ,                  # # */
_M |_J |_G2 |_G1 |_F |_D |_C |_A ,              # $ */
_N |_M |_L |_K |_J |_H |_G2 |_G1 |_F |_C ,      # % */
_N |_J |_H |_G1 |_E |_D |_A ,                   # & */
_J ,                                            # ' */
_N |_K ,                                        # ( */
_L |_H ,                                        # ) */
_N |_M |_L |_K |_J |_H |_G2 |_G1 ,              # * */
_M |_J |_G2 |_G1 ,                              # + */
_L ,                                            # , */
_G2 |_G1 ,                                      # - */
_DP ,                                           # . */
_L |_K ,                                        # / */
_L |_K |_F |_E |_D |_C |_B |_A ,                # 0 */
_K |_C |_B ,                                    # 1 */
_G2 |_G1 |_E |_D |_B |_A ,                      # 2 */
_G2 |_D |_C |_B |_A ,                           # 3 */
_G2 |_G1 |_F |_C |_B ,                          # 4 */
_C |_G1 | _G2 |_F |_D |_A ,                     # 5 */
_G2 |_G1 |_F |_E |_D |_C |_A ,                  # 6 */
_C |_B |_A ,                                    # 7 */
_G2 |_G1 |_F |_E |_D |_C |_B |_A ,              # 8 */
_G2 |_G1 |_F |_D |_C |_B |_A ,                  # 9 */
_M |_J ,                                        # : */
_L |_J ,                                        # ; */
_N |_K |_G1 ,                                   # < */
_G2 |_G1 |_D ,                                  # = */
_L |_H |_G2 ,                                   # > */
_DP |_M |_G2 |_B |_A ,                          # ? */
_J |_G2 |_F |_E |_D |_B |_A ,                   # @ */
_G2 |_G1 |_F |_E |_C |_B |_A ,                  # A */
_M |_J |_G2 |_D |_C |_B |_A ,                   # B */
_F |_E |_D |_A ,                                # C */
_M |_J |_D |_C |_B |_A ,                        # D */
_G1 |_F |_E |_D |_A ,                           # E */
_G1 |_F |_E |_A ,                               # F */
_G2 |_F |_E |_D |_C |_A ,                       # G */
_G2 |_G1 |_F |_E |_C |_B ,                      # H */
_M |_J |_D |_A ,                                # I */
_E |_D |_C |_B ,                                # J */
_N |_K |_G1 |_F |_E ,                           # K */
_F |_E |_D ,                                    # L */
_K |_H |_F |_E |_C |_B ,                        # M */
_N |_H |_F |_E |_C |_B ,                        # N */
_F |_E |_D |_C |_B |_A ,                        # O */
_G2 |_G1 |_F |_E |_B |_A ,                      # P */
_N |_F |_E |_D |_C |_B |_A ,                    # Q */
_N |_G2 |_G1 |_F |_E |_B |_A ,                  # R */
_G2 |_G1 |_F |_D |_C |_A ,                      # S */
_M |_J |_A ,                                    # T */
_F |_E |_D |_C |_B ,                            # U */
_L |_K |_F |_E ,                                # V */
_N |_L |_F |_E |_C |_B ,                        # W */
_N |_L |_K |_H ,                                # X */
_G2 |_G1 |_F |_D |_C |_B ,                      # Y */
_L |_K |_D |_A ,                                # Z */
_F |_E |_D |_A ,                                # [ */
_N |_H ,                                        # \ */
_D |_C |_B |_A ,                                # ] */
_N |_L ,                                        # ^ */
_D ,                                            # _ */
_H ,                                            # ` */
_M |_G1 |_E |_D ,                               # a */
_N |_G1 |_F |_E |_D ,                           # b */
_G2 |_G1 |_E |_D ,                              # c */
_L |_G2 |_D |_C |_B ,                           # d */
_L |_G1 |_E |_D ,                               # e */
_M |_K |_G2 |_G1 ,                              # f */
_K |_G2 |_D |_C |_B ,                           # g */
_M |_G1 |_F |_E ,                               # h */
_M ,                                            # i */
_L |_J |_E ,                                    # j */
_N |_M |_K |_J ,                                # k */
_F |_E ,                                        # l */
_M |_G2 |_G1 |_E |_C ,                          # m */
_M |_G1 |_E ,                                   # n */
_G2 |_G1 |_E |_D |_C ,                          # o */
_H |_G1 |_F |_E ,                               # p */
_K |_G2 |_C |_B ,                               # q */
_G1 |_E ,                                       # r */
_N |_G2 |_D ,                                   # s */
_G1 |_F |_E |_D ,                               # t */
_E |_D |_C ,                                    # u */
_L |_E ,                                        # v */
_N |_L |_E |_C ,                                # w */
_N |_L |_K |_H ,                                # x */
_J |_G2 |_D |_C |_B ,                           # y */
_L |_G1 |_D ,                                   # z */
_L |_H |_G1 |_D |_A ,                           # { */
_M |_J ,                                        # | */
_N |_K |_G2 |_D |_A ,                           # } */
_L |_K |_G2 |_G1 ,                              # ~ */
0                                               # (del) */
]