//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_PLUS_H
#define SYALGORITHM_PLUS_H


#include "BinaryOperator.h"

class Plus : public BinaryOperator {
public:
    Plus(Expression*, Expression*);
    double calculate();
};

#endif //SYALGORITHM_PLUS_H
