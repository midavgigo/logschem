#ifndef __OUTPUT_H__
#define __OUTPUT_H__
#include "elem.h"

class Output: public Element{
public:
    uint8_t execute(){
        state = (*input.begin())->get_state();
        return state;
    }
};

#endif