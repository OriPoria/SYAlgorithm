//
// Created by ori on 16/09/2020.
//

#include "Interpreter.h"
bool Interpreter::isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    } else return false;
}
bool Interpreter::isDigit(char c) {
    if (c <= '9' && c >= '0') {
        return true;
    } else return false;
}
double Interpreter::strToDoule(string s) {
    std::string::size_type sz;
    return std::stod(s,&sz);
}
Expression* Interpreter::interpret(string str) {
    stack<string> operatorStack;
    queue<string> polsihQueue;
    stack<string> unaryOperator;
    for (unsigned int i = 0; i < str.size(); ++i) {
        /*
         * check if the char is a start of the variable name or a number.
         * create this string until we see one of these chars: operator or '(  or ').
         * we check if we have an unary operator that we  need to push to the queue for the number
         * signed as '-D'
         */
        if ((!isOperator(str[i])) && str[i] != '(' && str[i] != ')') {
            string num;
            while (((!isOperator(str[i])) && str[i] != '(' && str[i] != ')') && i < str.size()) {
                num = num + str[i];
                i++;
            }
            polsihQueue.push(num);
            if ((!unaryOperator.empty()) && (unaryOperator.top() == "-D")) {
                polsihQueue.push(unaryOperator.top());
                unaryOperator.pop();
            }
            i--;
        } else if (isOperator(str[i])) {
            if ((i > 0) && (isOperator(str[i - 1]))) {
                throw ("Iligal expression: 2 operators in a row");
            }
            if (str[i] == '+' || str[i] == '-') {
                string oper;
                oper.push_back(str[i]);
                //check if the operator in functioned as unary operator
                if ((str[i + 1] == '(' && (i == 0 || str[i - 1] == '(')) ||
                (isDigit(str[i + 1]) && (i == 0 || str[i - 1] == '('))){
                    string st;
                    st.push_back(str[i]);
                    //check if the unary operator is before a number or an expression
                    if (str[i + 1] == '(') {
                        st.push_back('U');
                    } else {
                        st.push_back('D');
                    }
                    //pushing the unary operator to the queue with the sign of the type, if it is before an expression or a number to know when to pop it
                    unaryOperator.push(st);
                    continue;
                }
                while ((!operatorStack.empty()) && (operatorStack.top() == "*" || operatorStack.top() == "/")) {
                    polsihQueue.push(operatorStack.top());
                    operatorStack.pop();
                } operatorStack.push(oper);
            } else if (str[i] == '/' || str[i] == '*') {
                string st;
                st.push_back(str[i]);
                operatorStack.push(st);
            }
        } else if (str[i] == '(') {
            //if the expression has a form of (*( or (/(
            if ((i == 1 || (i > 1 && str[i - 2] == '(')) && (str[i - 1] == '*' || str[i -1] == '/')) {
                throw ("Iligal expression: operator without an expression");
            }
            if (i > 0 && str[i - 1] != '-') {
                unaryOperator.push("dummy");
            }
            string s;
            s.push_back(str[i]);
            operatorStack.push(s);
        } else if (str[i] == ')') {
            if (isOperator(str[i - 1])) {
                throw ("Iligal expression: operator without an expression");
            }
            while (!(operatorStack.empty()) && !(operatorStack.top() == "(")) {
                polsihQueue.push(operatorStack.top());
                operatorStack.pop();
            }
            if (operatorStack.empty()) {
                throw ("Iligal expression: close brackets without open");
            }
            //pop the unary operator at the end of the brackets
            if (!unaryOperator.empty()) {
                if (unaryOperator.top() == "-U" || unaryOperator.top() == "+U") {
                    polsihQueue.push(unaryOperator.top());
                }
                unaryOperator.pop();
            }
            operatorStack.pop();
        }

    }
    while (!operatorStack.empty()) {
        if (!(isOperator(operatorStack.top()[0]))) {
            throw ("Iligal expression: open brackets without close");
        }
        polsihQueue.push(operatorStack.top());
        operatorStack.pop();
    }

    //regular expression of the variable name and double
    regex isDoubleOrInt ("^([0-9]+[\\.][0-9]+)|[0-9]+");
    regex isVariable ("^[(A-Z)|(a-z)]+[[:w:]]*");
    stack<Expression*>exStack;
    Expression* ex;
    while (!polsihQueue.empty()) {

        string str2 = polsihQueue.front();
        polsihQueue.pop();
        if (regex_match(str2, isVariable)) {
            if (this->map1.find(str2) == this->map1.end()) {
                throw ("Invalid variable name: not exist in the expression");
            }
            double d = this->map1.at(str2);
            ex = new Variable(str2, d);
            exStack.push(ex);
        } else if (regex_match(str2, isDoubleOrInt)) {
            std::string::size_type sz;
            ex = new Value(std::stod(str2,&sz));
            exStack.push(ex);
        } else if (isOperator(str2[0])) {
            if (str2.size() == 2) {
                Expression* ex1 = exStack.top();
                exStack.pop();
                if (str2[0] == '-') {
                    ex = new UMinus(ex1);
                } else if (str2[0] == '+') {
                    ex = new UPlus(ex1);
                }
            } else {
                Expression* ex1 = exStack.top();
                exStack.pop();
                Expression* ex2 = exStack.top();
                exStack.pop();
                if (str2[0] == '+') {
                    ex = new Plus(ex2, ex1);
                } else if (str2[0] == '-') {
                    ex = new Minus(ex2, ex1);
                } else if (str2[0] == '*') {
                    ex = new Mul(ex2, ex1);
                } else if (str2[0] == '/') {
                    ex = new Div(ex2, ex1);
                }
            }

            exStack.push(ex);
        } else {
            throw ("Invalid variable name");
        }
    } ex = exStack.top();

    return ex;

}

void Interpreter::setVariables(string str) {
    regex isVariable ("^[(A-Z)|(a-z)]+[[:w:]]*");
    regex isDoubleOrInt ("^([0-9]+[\\.][0-9]+)|[0-9]+");
    for (unsigned int i = 0; i < str.size(); i++) {
        while (i < str.size()) {
            string var;
            while ((!(str[i] == '=')) && (i < str.size())) {
                var.push_back(str[i]);
                i++;
            } if (!regex_match(var, isVariable)) {
                throw ("Illegal variable assignment");
            }
            string num;
            i++;
            while((!(str[i] == ';')) && (i < str.size())) {
                num.push_back(str[i]);
                i++;
            }
            if (!regex_match(num,isDoubleOrInt)) {
                throw ("Illegal variable assignment: value is not a number");
            }
            double d = strToDoule(num);
            this->map1[var] = d;
            i++;
        }
    }
}
