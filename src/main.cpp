#include "engine.h"
#include <iostream>

int main (){
    Engine eng;
    ElemController s = eng.add_input('s');
    ElemController r = eng.add_input('r');
    ElemController out = eng.add_elem(LogElems::NOR);
    out.add_input(s);
    ElemController sec = eng.add_elem(LogElems::NOR);
    out.add_input(sec);
    sec.add_input(r);
    sec.add_input(out);
    eng.set_output(out);
    
    return 0;
}