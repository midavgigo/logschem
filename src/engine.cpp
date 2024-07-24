#include "engine.h"

ElemController::ElemController(Element *element): element(element){}

uint8_t ElemController::add_input(ElemController controller){
    return element->add_input(controller.element);
}

uint8_t ElemController::add_output(ElemController controller){
    return element->add_output(controller.element);
}

void ElemController::clr_exec(){
    exec = false;
}

bool ElemController::get_exec(){
    return exec;
}

uint8_t ElemController::execute(){
    return element->execute();
}

point *ElemController::get_point(){
    return &pos;
}

Element make_elem(char name, LOGFUN(*func)){
    Element el;
    el.set_name(name);
    el.set_func(func);
    return el;
}

ElemController Engine::add_elem(LogElems el){
    LOGFUN(*funcs[6]) = {
        not_f, 
        and_f, 
        or_f, 
        nand_f, 
        nor_f, 
        xor_f
    };
    char names[] = {
        '!', 
        '&', 
        '1', 
        'v', 
        '|', 
        '+'};
    elements.emplace_back(make_elem(names[static_cast<int>(el)], funcs[static_cast<int>(el)]));
    return ElemController(&elements[ELSIZE-1]);
}

ElemController Engine::add_input(char name){
    Input input;
    input.set_name(name);
    inputs.emplace_back(input);
    return ElemController(&inputs[INSIZE-1]);
}

vec<ElemController> Engine::get_elems(){
    vec<ElemController> ret;
    for(int i = 0; i < ELSIZE; i++){
        ret.emplace_back(ElemController(&elements[i]));
    }
    return ret;
}