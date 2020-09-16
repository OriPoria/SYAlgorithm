//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_DIV_H
#define SYALGORITHM_DIV_H


#include "BinaryOperator.h"

class Div : public BinaryOperator {
public:
    Div(Expression*, Expression*);
    double calculate();
};


#endif //SYALGORITHM_DIV_H
