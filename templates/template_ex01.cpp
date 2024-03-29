//
// Created by Tryggve Sørensen on 2019-04-18.
//
# include <iostream>
#include "Calc.h"

// Try to code a specific class first and then refactor to template class
// Coded class Calc with is an integer calculator

// Now try to generalize by allowing other types for the operations'
// See Calc.h file

int main(int argc, char* argv[]) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== REFERENCES TEMPLATES                                              ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    std::cout << "EXAMPLE 1: Normal class" << std::endl;
    Calc myCalc;
    int c = myCalc.add(1, 2);
    std::cout << "1 + 2 = " << c << std::endl;
    std::cout << "1 - 2 = " << myCalc.sub(1, 2) << std::endl;

    std::cout << "EXAMPLE 2: Template class" << std::endl;
    TCalc<float> myFloatCalc;
    std::cout << "2.0 + 3.0 = " << myFloatCalc.add(2.0, 3.0) << std::endl;
    std::cout << "2.0 - 3.0 = " << myFloatCalc.sub(2.0, 3.0) << std::endl;
    std::cout << "2.0 * 3.0 = " << myFloatCalc.mul(2.0, 3.0) << std::endl;

    std::cout << "EXAMPLE 3: Type traits class" << std::endl;
    int val1 = 2;
    int val2 = 3;
    int result;
    int *pVal1 {&val1}, *pVal2 {&val2}, *pRes {&result};

    // Pointer arguments
    TraitCalc<int*> myPtrCalc;
    myPtrCalc.add(pVal1, pVal2, pRes);
    std::cout << "pVal1 + pVal2 = " << result << std::endl;

    // Non-pointer arguments
    TraitCalc<int> myTraitCalc;
    myTraitCalc.add(10, 20, result);
    std::cout << "10 + 20 = " << result << std::endl;
}