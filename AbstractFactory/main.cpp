#include <QCoreApplication>
#include <memory>
#include <iostream>
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "cplusplusfactory.h"
#include "csharpfactory.h"
#include "javafactory.h"
using namespace std;

string generateProgram(const string& language) { // Ф-ция принимает ссылку на язык программирования, создает класс и его методы
    shared_ptr<AbstractFactory> factory; // создаем умный указатель factory на объект типа AbstractFactory

    if (language == "c++") { //Если пользователь ввел язык с++, то
        factory = make_shared<CPlusPlusFactory>(); // указателю factory присваивается умный указатель на новый объект CPlusPlusFactory
    } else if (language == "csharp") {
        factory = make_shared<CSharpFactory>();
    } else if (language == "java") {
        factory = make_shared<JavaFactory>();
    } else {
        return "Incorrect language.";
    }

    auto myClass = factory->createClass("MyClass"); // Создание экземпляра класса "MyClass" с помощью указателя на фабрику
    myClass->add(factory->createMethod("testFunc1", "void", 0), ClassUnit::PUBLIC); // Добавление в экземпляр myClass публичного метода testFunc1
    //типа void (ничего не возвращает), 0 - без модификатора доступа из перечисления Modifier.
    myClass->add(factory->createMethod("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE); //Добавление в экземпляр myClass
    // приватного статического метода testFunc2 типа void
    myClass->add(factory->createMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC); // Добавление в экземпляр
    // myClass публичного виртуального константного метода testFunc3 типа void
    shared_ptr<MethodUnit> method = factory->createMethod("testFunc4", "void", MethodUnit::STATIC); // Инициализируем умный указатель method на
    // объект типа MethodUnit статическим методом testFunc4 типа void, созданным с помощью фабрики.
    method->add(factory->createPrintOperator(R"(Hello, world!\n)")); // Добавляем в эту переменную оператор вывода для строки Hello, world!\n
    myClass->add(method, ClassUnit::PROTECTED); // Добавляем в экземпляр myClass переменную method защищенного типа, которая содержит
    // статический метод testFunc4 типа void и оператор вывода для строки Hello, world!\n


    return myClass->compile(); // Возвращаем результат работы метода compile для экземпляра класса myClass, который генерирует код
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Enter programming language: ";
    string x; cin >> x; //Вводим язык
    cout << generateProgram(x) << endl; // Выводится сгенерируемый код на заданном языке
    return a.exec();
}
