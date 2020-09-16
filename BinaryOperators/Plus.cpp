//
// Created by ori on 16/09/2020.
//

#include "Plus.h"
Plus::Plus(Expression * ex1, Expression * ex2) : BinaryOperator(ex1,ex2) { }

double Plus::calculate() {
    return (this->leftExpression->calculate() + this->rightExpression->calculate());
}