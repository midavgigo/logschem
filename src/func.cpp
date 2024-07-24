#include "func.h"

uint8_t and_f(FUNC_ARGS){
    bool result = 1;
    for(auto i = input.begin(); i != input.end(); i++){
        result = result&&(*i)->get_state();
        if(!result){
            return 0;
        }
    }
    return 1;
}

uint8_t or_f(FUNC_ARGS){
    bool result = 0;
    for(auto i = input.begin(); i != input.end(); i++){
        result = result||(*i)->get_state();
        if(result){
            return 1;
        }
    }
    return 0;
}

uint8_t not_f(FUNC_ARGS){
    if(input.size() > 1){
        return input.size();
    }
    return PARSE(!(*input.begin())->get_state());
}

uint8_t nand_f(FUNC_ARGS){
    return PARSE(!and_f(input));
}

uint8_t nor_f(FUNC_ARGS){
    return PARSE(!or_f(input));
}

uint8_t xor_f(FUNC_ARGS){
    uint8_t result = 0;
    for(auto i = input.begin(); i != input.end(); i++){
        result ^= PARSE((*i)->get_state());
    }
    return result;
}