//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_VALUE_H
#define SYALGORITHM_VALUE_H


#include "Expression.h"

class Value : public Expression {
private:
    double value;
public:
    Value(double);
    double calculate();
};


#endif //SYALGORITHM_VALUE_H
