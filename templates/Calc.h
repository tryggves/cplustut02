//
// Created by tryggve on 4/18/19.
//

#ifndef CPLUSTUT02_CALC_H
#define CPLUSTUT02_CALC_H

#include <type_traits>      // See class TraitCalc

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
    // Use const before reference to class <class CalcType>& reference
    CalcType add (const CalcType& a, const CalcType& b) const { return a + b; };
    CalcType sub (const CalcType& a, const CalcType& b) const { return a-b; };
    // Here is the other way: declare parameter as rvalue reference
    CalcType mul (CalcType&& a, CalcType&& b) const { return a*b; };
};

//Lot of typing - do it inline if oneliners such as above.
// Here is how it would look if separating implemented in .cpp file
/*
template <class CalcType> CalcType TCalc<CalcType>::add(CalcType a, CalcType b) { return a+b; }
template <class CalcType> CalcType TCalc<CalcType>::sub(CalcType a, CalcType b) { return a-b; }
//*/

/**
 * Here is an example of using traits for conditional handling of parameters
 * of different type - again the calculator
 */
template <class T>      // T can be pointer
class TraitCalc {
public:
    // Function will call the implementation method, one for pointers and another for non-pointers
    void add (const T& a, const T& b, T& result) const { addImpl(a, b, result, std::is_pointer<T>());  };

private:
    void addImpl(const T& a, const T& b, T& res, std::true_type) const { *res = (*a + *b); };
    void addImpl(const T& a, const T& b, T& res,  std::false_type) const { res = a + b; };
};

#endif //CPLUSTUT02_CALC_H
