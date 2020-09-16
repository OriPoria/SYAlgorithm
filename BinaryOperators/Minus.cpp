//
// Created by ori on 16/09/2020.
//

#include "Minus.h"

Minus::Minus(Expression * ex1, Expression * ex2) : BinaryOperator(ex1,ex2) { }

double Minus::calculate() {
    return (this->leftExpression->calculate() - this->rightExpression->calculate());
}