#ifndef __ELEM_H__
#define __ELEM_H__
#include <cstdint>
#include <set>
#define LOGFUN(func) uint8_t (func)(std::set<Element*>)
#define vec std::vector
class Element{
protected:
    std::set<Element*> input;        //Массив указателей на входные элементы
    std::set<Element*> output;       //Массив указателей на выходные элементы
    bool state = false;         //Выходное состояние
    char name = '\0';           //Символ который будет отображаться на элементе
    LOGFUN(*func) = nullptr;           //Функция обработки входных сигналов
public:
    uint8_t add_input(Element *input);      //Добавить входной элемент
    uint8_t add_output(Element *output);    //Добавить выходной элемент
    void set_name(char name);               //Установить имя
    void set_func(LOGFUN(*func));                  //Установить логическую функцию
    virtual uint8_t execute();              //Обработка сигналов. 0 - успешно, иначе ошибка
    bool get_state();                       //Возвращает выходное состояние 
};
#endif