#ifndef __ENGINE_H__
#define __ENGINE_H__
#include "elem.h"
#include "func.h"
#include "output.h"
#include "input.h"
#include <vector>
#define ELSIZE elements.size()
#define INSIZE inputs.size()

class ElemController;
class Engine;

struct point{
    uint16_t x, y;
};

class ElemController{
    friend class Engine;
private:
    Element *element;
    bool exec = false;
    point pos = {0, 0};
public:
    ElemController(Element *element);
    uint8_t add_input(ElemController controller);
    uint8_t add_output(ElemController controller);
    void clr_exec();
    bool get_exec();
    uint8_t execute();
    point *get_point();
};

enum LogElems{
    NOT,
    AND,
    OR,
    NAND,
    NOR,
    XOR,
    ELEM_NUM
};

class Engine{
private:
    std::vector<Input> inputs;
    std::vector<Element> elements;
    Output output; 
public:
    ElemController add_elem(LogElems le);
    ElemController add_input(char name);
    vec<ElemController> get_elems();
    vec<ElemController> get_inputs();
    uint8_t set_output(ElemController elem);
};
#endif