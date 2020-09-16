//
// Created by ori on 16/09/2020.
//

#include "Div.h"

Div::Div(Expression* left, Expression* right) : BinaryOperator(left,right) { }

double Div::calculate() {
    return this->leftExpression->calculate() / this->rightExpression->calculate();
}
