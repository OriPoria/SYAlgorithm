//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_MINUS_H
#define SYALGORITHM_MINUS_H


#include "BinaryOperator.h"

class Minus : public BinaryOperator {
public:
    Minus(Expression*, Expression*);
    double calculate();
};


#endif //SYALGORITHM_MINUS_H
