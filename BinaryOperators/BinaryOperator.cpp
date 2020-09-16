//
// Created by ori on 16/09/2020.
//

#include "BinaryOperator.h"

BinaryOperator::BinaryOperator(Expression* left, Expression* right) {
    this->leftExpression = left;
    this->rightExpression = right;
}
BinaryOperator::~BinaryOperator() {
    delete(this->leftExpression);
    delete(this->rightExpression);
}