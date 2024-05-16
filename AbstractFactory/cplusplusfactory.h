#ifndef CPLUSPLUSFACTORY_H
#define CPLUSPLUSFACTORY_H
#include "abstractfactory.h"
#include "cplusplusclass.h"
#include "cplusplusmethod.h"
#include "cplusplusprintoperator.h"

class CPlusPlusFactory : public AbstractFactory //Конкретная фабрика CPlusPlusFactory, наследуемая от абстрактной, для создания продуктов на с++
{
public:
    shared_ptr<ClassUnit> createClass(const string& name) { // переопределение метода для создания конкретного класса на с++ с заданным именем
        return shared_ptr<ClassUnit> (new CPlusPlusClass(name)); //создаем объект CPlusPlusClass с конкретным именем в динамической памяти(new)
        // и возвращаем умный указатель на этот объект
    }
    shared_ptr<MethodUnit> createMethod(const string& name, const string& returnType, Unit::Flags flags) { // переопределение метода для создания
    // конкретного метода на с++ с заданным именем, возвращаемым типом и флагом(static, const или virtual)
        return shared_ptr<MethodUnit> (new CPlusPlusMethod(name, returnType, flags));
    }
    shared_ptr<PrintOperatorUnit> createPrintOperator(const string& text) { // переопределение метода для создания конкретного оператора вывода на
    // с++ с заданным текстом
        return shared_ptr<PrintOperatorUnit> (new CPlusPlusPrintOperator(text));
    }
};

#endif // CPLUSPLUSFACTORY_H
