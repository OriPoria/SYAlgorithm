//
// Created by ori on 16/09/2020.
//

#include "Value.h"

Value::Value(double val) {
    this->value = val;
}
double Value::calculate() {
    return this->value;
}