#ifndef __FUNC_H__
#define __FUNC_H__
#include "elem.h"
#include <iostream>

#define PARSE(a) ((uint8_t)(a) > 1 ? 1 : 0)
#define FUNC_ARGS std::set<Element*> input

uint8_t and_f(FUNC_ARGS);

uint8_t or_f(FUNC_ARGS);

uint8_t not_f(FUNC_ARGS);

uint8_t nand_f(FUNC_ARGS);

uint8_t nor_f(FUNC_ARGS);

uint8_t xor_f(FUNC_ARGS);


#endif