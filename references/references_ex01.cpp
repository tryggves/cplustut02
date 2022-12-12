//
// Created by tryggve on 4/14/19.
//
#include <iostream>

// Function returning reference to its parmeter. Note the parameter declared as reference
// to its argument (from the caller). If not, the call will be call by value and this issues
// compiler warning
int& foo(int &x) {
    return x;
}

// Function templates
template <typename T>
void f(T& param) {
    std::cout << "Function f():";
    std::cout << "param + 1 = " << param+1 << std::endl;
}

template <typename T>
void g(T& param) {
    std::cout << "Function g():";
    std::cout << "param + 1 = " << param+1 << std::endl;
    param = 2;
}

template <typename T>
void h(T param) {
    std::cout << "Function h():";
    std::cout << "param + 1 = " << param + 1 << std::endl;
}
int main (int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== REFERENCES LVALUE RVALUE EXAMPLES                                 ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    // lvalues
    int i = 42;     // i is lvalue - resolves to memory location
    i = 43;         // should work
    int  *p = &i;   // i is lvalue

    // int& foo(int &x) {
    int& q = foo(i);
    std::cout << "i=" << i << "\t\tq=" << q << std::endl;
    std::cout << "Testing function templates." << std::endl;

    f(i);
    f(i);
    // Does not compile
    // f(41.2);
    // Function g() has side effects since it modifies its argument (reference to float j)
    float j = 41.2;
    g(j);
    float cj = j;
    g(cj);

    float& rj = j;
    g(rj);

    int h_ = 5;
    h(h_);  // call with lvalue
    h(25);  // call with rvalue

    int& href = h_; // href is a reference to h_
    h(href);
    int* ph_ = &h_;
    h(ph_);         // prints pointer value
    h(*ph_);        // prints the integer value of h_

    return (0);
}