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

// This is the header file containing the CCalculator class declaration
// Christopher Lucas - 01. Oct. 2021

#ifndef TP_CCALCULATOR_H
#define TP_CCALCULATOR_H

// This calculator will be capable to do the following operators:
// + - * / ^
enum class Symbole{plus, minus, times, divide, power, end, error};
// This class will do the required maths
class CCalculator {
private:
    double curr_value;
public:
    CCalculator();
    ~CCalculator();
    /**
     * Calculates the result of the provide parameters
     *
     * @param a is the first number
     * @param b is the second number
     * @param op is the operator
     *
     * @return the result of the operation
     */
    double calculate(double a, double b, enum Symbole op);
    /**
     * Checks if the calculator knows the operator
     *
     * @param txt is the given operator
     *
     * @return the Symbole from the character
     */
    enum Symbole checkSymbol(char& txt);
};


#endif //TP_CCALCULATOR_H
