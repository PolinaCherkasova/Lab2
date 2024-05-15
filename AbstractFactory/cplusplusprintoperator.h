#ifndef CPLUSPLUSPRINTOPERATOR_H
#define CPLUSPLUSPRINTOPERATOR_H
#include "printoperatorunit.h"

class CPlusPlusPrintOperator : public PrintOperatorUnit // Класс для создания конкретного продукта - оператора вывода на с++
{
public:
    CPlusPlusPrintOperator(const string& text) : PrintOperatorUnit(text) {} //Определение пустого конструктора, который принимает строку текста
    // и передает ее в конструктор PrintOperatorUnit
    string compile(unsigned int level = 0) const { // переопределение метода для генерации текста на с++, который хранится в объекте PrintOperatorUnit
        return generateShift(level) + "printf( \"" + m_text + "\" );\n"; // генерация отступа с заданным уровнем вложенности и текста m_text
    }
};

#endif // CPLUSPLUSPRINTOPERATOR_H
