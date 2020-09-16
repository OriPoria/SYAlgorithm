//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_MUL_H
#define SYALGORITHM_MUL_H


#include "BinaryOperator.h"

class Mul : public BinaryOperator {
public:
    Mul(Expression*, Expression*);
    double calculate();
};

#endif //SYALGORITHM_MUL_H
