//
// Created by tryggve on 4/18/19.
//

#ifndef CPLUSTUT02_CALC_H
#define CPLUSTUT02_CALC_H

// Try to code a specific class first an then refactor to template class
class Calc {
public:
    int add (int a, int b);
    int sub (int a, int b);
};

// Generic calculator
template <class CalcType>
class TCalc {
public:
    CalcType add (CalcType a, CalcType b) { return a+b; };
    CalcType sub (CalcType a, CalcType b) { return a-b; };
    CalcType mul (CalcType a, CalcType b) { return a*b; };
};

//Lot of typing - do it inline if oneliners such as above.
// Here is how it would look if separating implemented in .cpp file
/*
template <class CalcType> CalcType TCalc<CalcType>::add(CalcType a, CalcType b) { return a+b; }
template <class CalcType> CalcType TCalc<CalcType>::sub(CalcType a, CalcType b) { return a-b; }
//*/

#endif //CPLUSTUT02_CALC_H
