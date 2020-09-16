#include <iostream>
#include "Expression.h"
#include "Interpreter.h"

int main() {

    Interpreter* i2 = new Interpreter();
    Expression* e5 = nullptr;
    try {
        i2->setVariables("x=2;y=4");
        i2->setVariables("x=3");
        e5 = i2->interpret("2*(-(x+y))");
        cout << e5->calculate() << endl;//-14
        delete e5;
    } catch (const char* e) {
        if (e5!= nullptr) {
            delete e5;
        } //deleting i2 in the next example
        std::cout << e << std::endl;
    }
    return 0;
}