//
// Created by ori on 16/09/2020.
//

#include "UMinus.h"
UMinus::UMinus(Expression* ex) : UnaryOperator(ex) { }

double UMinus::calculate() {
    return -(this->expression->calculate());
}