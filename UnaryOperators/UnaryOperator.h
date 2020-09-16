//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_UNARYOPERATOR_H
#define SYALGORITHM_UNARYOPERATOR_H


#include "../Expression.h"

class UnaryOperator : public Expression {
protected:
    Expression* expression;
public:
    UnaryOperator(Expression*);
    ~UnaryOperator();

};


#endif //SYALGORITHM_UNARYOPERATOR_H
