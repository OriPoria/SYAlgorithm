//
// Created by ori on 16/09/2020.
//

#ifndef SYALGORITHM_EXPRESSION_H
#define SYALGORITHM_EXPRESSION_H

using namespace std;

class Expression {
public:
    virtual double calculate() = 0;
    virtual ~Expression() {}

};


#endif //SYALGORITHM_EXPRESSION_H
