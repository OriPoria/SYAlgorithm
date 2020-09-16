cmake_minimum_required(VERSION 3.15)
project(SYAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(SYAlgorithm main.cpp Expression.h BinaryOperators/BinaryOperator.cpp BinaryOperators/BinaryOperator.h
        BinaryOperators/Plus.cpp BinaryOperators/Plus.h BinaryOperators/Minus.cpp BinaryOperators/Minus.h BinaryOperators/Mul.cpp BinaryOperators/Mul.h BinaryOperators/Div.cpp BinaryOperators/Div.h UnaryOperators/UnaryOperator.cpp UnaryOperators/UnaryOperator.h UnaryOperators/UPlus.cpp UnaryOperators/UPlus.h
        UnaryOperators/UMinus.cpp UnaryOperators/UMinus.h Variable.cpp Variable.h Value.cpp Value.h Interpreter.cpp Interpreter.h UnaryOperators/UnaryOperator.cpp
        UnaryOperators/UnaryOperator.h)