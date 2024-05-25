#ifndef CSHARPCLASS_H
#define CSHARPCLASS_H
#include "classunit.h"

class CSharpClass : public ClassUnit // Класс для создания конкретного продукта - класса на с#
{
public:
    CSharpClass(const string& name) : ClassUnit(name) {} // Определение пустого конструктора, который принимает константную строковую ссылку
  // на имя класса и передает ее в конструктор ClassUnit
    string compile(unsigned int level) const //Переопределение метода, который генерирует класс на C# и возвращает строку. В качестве аргумента
        // метод принимает параметр level - уровень вложенности узла дерева для корректной расстановки отступов в начале строк генерируемого кода.
    {
        string result = generateShift(level) + "class " + m_name + " {\n"; // Создание строки, содержащей объявление класса с его именем и открывающей
        // фигурной скобкой для начала объявления класса. Уровень вложенности определяется с помощью вызова generateShift(level) для кол-ва отступов.
        for(size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) { // Цикл для прохода по всем модификаторам доступа
            if(m_fields[i].empty()) { // Если вектор элементов для текущего модификатора пуст, то
                continue; // переходим к следующему модификатору - на начало цикла for
            }

            for(const auto& f : m_fields[i]) { // Цикл по всем элементам вектора для данного модификатора
                result += ACCESS_MODIFIERS[i]; // добавляем строку с индексом на текущий модификатор доступа в результат.
                result += f->compile(level + 1); //рекурсивный вызов для каждого элемента f метода compile с уровнем вложенности +1 и добавление в результат
            }
            result += "\n"; //добавление пустой строки после элементов текущего модификатора
        }
        result += generateShift(level) + "};\n"; // добавляем закрывающую фигурную скобку для завершения объявления класса
        return result;
    }
};

#endif // CSHARPCLASS_H
