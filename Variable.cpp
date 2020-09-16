//
// Created by ori on 16/09/2020.
//

#include "Variable.h"
Variable::Variable(string str, double val) {
    this->name = str;
    this->value = val;
}
double Variable::calculate() {
    return this->value;
}
Variable& Variable::operator++() {
    this->value++;
    return *this;
}
Variable& Variable::operator--() {
    this->value--;
    return *this;
}
Variable& Variable::operator+=(double num) {
    this->value+=num;
    return *this;
}
Variable& Variable::operator-=(double num) {
    this->value-=num;
    return *this;
}
Variable& Variable::operator++(int) {
    this->value++;
    return *this;
}
Variable& Variable::operator--(int) {
    this->value--;
    return *this;
}