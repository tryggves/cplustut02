//
// Created by tryggve on 4/15/19.
//
// lvalue and rvalue
// lvalue can appear on both left and right side of = sign.
// rvalue can only appear on right side of = sign.

#include <iostream>
// Will compile, but x is local variable and undefined when out of function scope
int& foo() {int x=10; return x;}

// This will work with global static variable
int x_glob = 23;
int& globref (int& x) {return x;}

int main(int argc, char* argv[]) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== REFERENCES LVALUE RVALUE EXAMPLES                                 ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    int a;
    int b;

    a = 10;
    b = 20;

    // An lvalue is an expression that refers to a memory location and allows us to take the address
    // of that memory location via the & operator. An rvalue is an expression that is not an lvalue.

    /*
    a*b = 20;       // will not compile as a*b is a rvalue
    //*/
    int c = a*b;
    std::cout << "a = " << a << "\t\tb = " << b << std::endl;
    std::cout << "a * b = " << c << std::endl;

    /*
    //int foo() {return 10;};
    int j = 34;
    std::cout << "j = " << j << std::endl;
    j = foo();      // will not compile, foo() undefined reference.
    std::cout << "\t\t\tj = " << j << std::endl;    // Causes SIGSEGV
    //*/

    int k = 34;
    std::cout << "k = " << k << "\t\tx_glob = " << x_glob << std::endl;
    k = globref(x_glob);
    std::cout << "k = " << k << std::endl;
}
