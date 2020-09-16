//
// Created by ori on 16/09/2020.
//

#include "UPlus.h"

UPlus::UPlus(Expression* ex) : UnaryOperator(ex) { }

double UPlus::calculate() {
    return this->expression->calculate();
}