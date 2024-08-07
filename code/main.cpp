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

// This file contains the main function of ou program
// Christopher Lucas - 01. Oct. 2021

#include <iostream>
#include "CCalculator.h"

/**
 * Ask the user for an operator
 *
 * @return the input character
 */
char fetchOperator(){
    char op;
    std::cout << "Type an operator: ";
    std::cin >> op;
    return op;
}

/**
 * Asks and waits for the user to input a number. It will check for a number.
 *
 * @return the input number
 */
double fetchNumber(){
    double x;
    // Exit loop when ever a number is inputed
    while (true){
        std::cout << "Type a number: ";
        // Check if valid number
        if (std::cin >> x){
            break;
        } else {
            std::cout << " *** Invalide number" << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n') ;
        }
    }
    return x;
}

int main() {
    // Create CCalculator object
    CCalculator calc;
    // Get first number
    double nb = fetchNumber();
    // get input operator & convert char to enum
    char op = fetchOperator();
    // check the input operator
    enum Symbole r = calc.checkSymbol(op);
    // Program loop
    while (r != Symbole::end) {
        // Check if operator valide
        if (r == Symbole::error) {
            std::cout << " *** Not Valide operator" << std::endl;
        } else {
            // Get other number
            double *old_nb = &nb;
            // calculate the result
            nb = calc.calculate(nb, fetchNumber(), r);
            // check for bad result
            if (nb == -1) {
                std::cout << " *** Division by 0 not allowed" << std::endl;
                nb = *old_nb;
            }
            std::cout <<  " *** Current value is = " +  std::to_string(nb) << std::endl;
        }
        // Get next operator & convert char to enum
        char op2 = fetchOperator();
        // check the input operator
        r = calc.checkSymbol(op2);
    }
    return 0;
}
