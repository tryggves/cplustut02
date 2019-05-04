//
// Created by tryggve on 4/18/19.
//

#ifndef CPLUSTUT02_CALC_H
#define CPLUSTUT02_CALC_H

// Try to code a specific class first an then refactor to template class
class Calc {
public:
    //
    // NOTE:
    // Declaring member functions as const (after the parameter section) means that
    // these functions will not modify any state of Calc.
    // The function definitions (in the CPP file has to match these const declarations or the
    // compilation will fail.
    int add (int a, int b) const;
    int sub (int a, int b) const;
};

// Generic calculator
template <class CalcType>
class TCalc {
public:
    CalcType add (CalcType a, CalcType b) const { return a+b; };
    CalcType sub (CalcType a, CalcType b) const { return a-b; };
    CalcType mul (CalcType a, CalcType b) const { return a*b; };
};

//Lot of typing - do it inline if oneliners such as above.
// Here is how it would look if separating implemented in .cpp file
/*
template <class CalcType> CalcType TCalc<CalcType>::add(CalcType a, CalcType b) { return a+b; }
template <class CalcType> CalcType TCalc<CalcType>::sub(CalcType a, CalcType b) { return a-b; }
//*/

#endif //CPLUSTUT02_CALC_H
