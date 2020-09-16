//
// Created by ori on 16/09/2020.
//

#include "UnaryOperator.h"

UnaryOperator::UnaryOperator(Expression* ex)  {
    this->expression = ex;
}
UnaryOperator::~UnaryOperator() {
    delete (this->expression);
}