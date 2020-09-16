//
// Created by ori on 16/09/2020.
//

#include "Mul.h"

Mul::Mul(Expression * ex1, Expression * ex2) : BinaryOperator(ex1,ex2) { }

double Mul::calculate() {
    return (this->leftExpression->calculate() * this->rightExpression->calculate());
}