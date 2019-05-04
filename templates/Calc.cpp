//
// Created by tryggve on 4/18/19.
//

#include "Calc.h"

// Integer calculator implementation
// NOTE: The const after the function declaration signals that the function will not modify
// the Calc object state.
int Calc::add(int a, int b) const { return a+b; }
int Calc::sub(int a, int b) const { return a-b; }

