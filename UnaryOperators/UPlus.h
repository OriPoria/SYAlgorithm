//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_UPLUS_H
#define SYALGORITHM_UPLUS_H


#include "UnaryOperator.h"

class UPlus : public UnaryOperator {
public:
    UPlus(Expression*);
    double calculate();
};

#endif //SYALGORITHM_UPLUS_H
