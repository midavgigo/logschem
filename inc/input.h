#ifndef __INPUT_H__
#define __INPUT_H__
#include "elem.h"
class Input:public Element{
public:
    void change_state(bool new_state);
    uint8_t execute(){
        return 0;
    }
};

#endif