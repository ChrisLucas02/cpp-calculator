// Copyright (c) 2021 Haute école d'ingénierie et d'architecture de Fribourg
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// This is the class file implementing the CCalculator class
// Christopher Lucas - 01. Oct. 2021

#include "CCalculator.h"
#include "math.h"

CCalculator::CCalculator() = default;
CCalculator::~CCalculator() = default;

/* ------ Private method --------------------------------------------- */
double addition(double a, double b) {
    return a + b;
}

double substitution(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    return a / b;
}



/* ------ Public method --------------------------------------------- */
double CCalculator::calculate(double a, double b, enum Symbole r) {
    switch (r) {
        case Symbole::plus:
            CCalculator::curr_value = addition(a,b);
            break;
        case Symbole::minus:
            CCalculator::curr_value = substitution(a,b);
            break;
        case Symbole::times:
            CCalculator::curr_value = multiplication(a,b);
            break;
        case Symbole::divide:
            if (b == 0){
                return -1;
            } else {
                CCalculator::curr_value = division(a,b);
            }
            break;
        case Symbole::power:
            CCalculator::curr_value = pow(a,b);
            break;
        default: /* empty */;
    }
    return CCalculator::curr_value;
}

enum Symbole CCalculator::checkSymbol(char& txt) {
    enum Symbole result = Symbole::error;
    switch (txt) {
        case '+':
            result = Symbole::plus;
            break;
        case '-':
            result = Symbole::minus;
            break;
        case '*':
            result = Symbole::times;
            break;
        case '/':
            result = Symbole::divide;
            break;
        case '^':
            result = Symbole::power;
            break;
        case '#':
            result = Symbole::end;
            break;
        default: /* empty */;
    }
    return result;
}