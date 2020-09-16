//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_INTERPRETER_H
#define SYALGORITHM_INTERPRETER_H

#include <iostream>
#include <stack>
#include <queue>
#include <regex>
#include <string>
#include <map>
#include "Variable.h"
#include "Value.h"
#include "UnaryOperators/UMinus.h"
#include "UnaryOperators/UPlus.h"
#include "BinaryOperators/Minus.h"
#include "BinaryOperators/Mul.h"
#include "BinaryOperators/Plus.h"
#include "BinaryOperators/Div.h"




class Interpreter {
private: map<string,double> map1;
public:
    Expression* interpret(string);
    void setVariables(string);
    void printMap();
    bool isOperator(char);
    bool isDigit(char);
    double strToDoule(string);
};

#endif //SYALGORITHM_INTERPRETER_H
