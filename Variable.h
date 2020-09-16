//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_VARIABLE_H
#define SYALGORITHM_VARIABLE_H


#include <string>
#include "Expression.h"

class Variable : public Expression {
private:
    string name;
    double value;
public:
    Variable(string, double);
    double calculate();
    Variable& operator++();
    Variable& operator--();
    Variable& operator+=(double);
    Variable& operator-=(double);
    Variable& operator++(int);
    Variable& operator--(int);
};


#endif //SYALGORITHM_VARIABLE_H
