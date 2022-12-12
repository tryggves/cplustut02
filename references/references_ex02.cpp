//
// Created by tryggve on 4/15/19.
//
// lvalue and rvalue
// lvalue can appear on both left and right side of = sign.
// rvalue can only appear on right side of = sign.

#include <iostream>
// Will compile, but x is local variable and undefined when out of function scope
/*
int& foo() {int x=10; return x;}
//*/

// This will work with global static variable
int x_glob = 23;        // Global variable that can be returned by function globref

// This function parameter is reference to int, which is returned. Just as an example
int& globref (int& x) {return x;}

template <typename T>
void mytempfunc (T param) {
    std::cout << "In function mytempfunc() param is: " << param << std::endl;
}

// Function template where the param is declared as rvalue reference
template <typename T>
void mytempfunc_b (T&& param) {
    std::cout << "In mytempfunc_b() param is: " << param << std::endl;
    // Try a side effect
    param = 467;
}

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
    // */
    std::cout << "=== EXAMPLE 1" << std::endl;
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

    std::cout << "=== EXAMPLE 2" << std::endl;
    int k = 34;
    std::cout << "Before assignment: k = " << k << "\t\tx_glob = " << x_glob << std::endl;
    k = globref(x_glob);
    std::cout << "After assignment: k = " << k << std::endl;

    // Try globref() function on the left hand side of the assignment
    std::cout << "=== EXAMPLE 3" << std::endl;
    std::cout << "Before assignment: x_glob = " << x_glob << std::endl;
    globref(x_glob) = 3487;     // Assign new number to the global variable
    std::cout << "After assignment: x_glob = " << x_glob << std::endl;

    // Try out copy by value
    std::cout << "=== EXAMPLE 4" << std::endl;
    int m_var1 = 1;
    const int m_var2 = m_var1;
    const int& m_var3 = m_var1;
    mytempfunc(m_var1);
    mytempfunc(m_var2);     // const is ignored
    mytempfunc(m_var3);     // const is ignored

    // Try out rvalue param template function
    std::cout << "=== EXAMPLE 5" << std::endl;
    int m_var4 = 25;
    const int m_var5 = m_var4;
    const int& m_var6 = m_var4;
    mytempfunc_b(m_var4);
    std::cout << "After int: m_var4 = " << m_var4 << std::endl;

    // This gives compile error because the function tries to assign value to const argument
    // mytempfunc_b(m_var5);
    // std::cout << "After const int: m_var5 = " << m_var5 << std::endl;
    // mytempfunc_b(m_var6);
    // std::cout << "After const int&: m_var4 = " << m_var4 << std::endl;
}
