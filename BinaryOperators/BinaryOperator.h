//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_BINARYOPERATOR_H
#define SYALGORITHM_BINARYOPERATOR_H


#include "../Expression.h"

class BinaryOperator : public Expression {
protected:
    Expression* leftExpression;
    Expression* rightExpression;
public:
    BinaryOperator(Expression*, Expression*);
    ~BinaryOperator();

};


#endif //SYALGORITHM_BINARYOPERATOR_H
