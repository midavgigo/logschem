#include "input.h"


uint8_t Input::execute(){
    state = !state;
    return state;
}