//
// Created by wangyunlong01 on 2022/6/30.
//

#ifndef HELLOC_UTIL_H
#define HELLOC_UTIL_H

#endif //HELLOC_UTIL_H

#include <cstdlib>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define EXIT_ON_FAILURE(expr)       \
do {                                \
       bool success = (expr);       \
       if (!success) {              \
           exit(EXIT_FAILURE);      \
       }                            \
} while(0)
