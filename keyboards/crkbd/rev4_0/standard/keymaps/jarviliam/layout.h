/*
 * Copyright(c) 2025 Liam Jarvis.All Rights Reserved.
 */

// clang-format off

#define LAYOUT_LR( \
    k01, k02, k03, k04, k05, k06, \
    k41, k42, k43, k44, k45, k46, \
    k11, k12, k13, k14, k15, k16, \
    k51, k52, k53, k54, k55, k56, \
    k21, k22, k23, k24, k25, \
    k62, k63, k64, k65, k66, \
    k34, k35, k36, \
    k70, k71, k72) \
      LAYOUT_split_3x5_3_ex2( \
        k01, k02, k03, k04, k05, k06,  k41, k42, k43, k44, k45, k46, \
        k11, k12, k13, k14, k15, k16,  k51, k52, k53, k54, k55, k56, \
        k21, k22, k23, k24, k25,            k62, k63, k64, k65, k66, \
                            k34, k35, k36,  k70, k71, k72)
