//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_UMINUS_H
#define SYALGORITHM_UMINUS_H


#include "UnaryOperator.h"

class UMinus : public UnaryOperator {
public:
    UMinus(Expression*);
    double calculate();
};


#endif //SYALGORITHM_UMINUS_H
