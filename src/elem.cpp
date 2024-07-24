#include "elem.h"

uint8_t Element::add_input(Element *input){
    auto ret = this->input.insert(input);
    return (uint8_t)!ret.second;
}
uint8_t Element::add_output(Element *output){
    auto ret = this->output.insert(output);
    return (uint8_t)!ret.second;
}
void Element::set_name(char name){
    this->name = name;
}
void Element::set_func(LOGFUN(*func)){
    this->func = func;
}

uint8_t Element::execute(){
    state = func(input);
    return func(input);
}

bool Element::get_state(){
    return state;
}