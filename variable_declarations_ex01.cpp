//
// Created by Tryggve Sørensen on 03/01/2020.
//

#include <iostream>

int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== VARIABLE DECLARATIONS EX                                          ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    /// Try out const

    /// Note: Initialize a using initializer list. This can provide multiple values in initializer
    struct myPair {
        int m_a;
        int m_b;
    };
    const struct myPair p {1, 2};

    const int a {2};
    const int b {3};
    int c {4};

    /// Here is a pointer to a const int (but the pointer itself is not const)
    const int *pInt = &a;

    std::cout << "a=" << a << std::endl;
    std::cout << "Address of a pointer pInt=" << pInt << std::endl;
    std::cout << "Value a of pointer pInt=" << *pInt << std::endl;

    /// Now point pInt to b
    pInt = &b;
    std::cout << "Address of b pointer pInt=" << pInt << std::endl;
    std::cout << "Value b of pointer pInt=" << *pInt << std::endl;
    /// This will not compile
    // *pInt = 10;

    pInt = &c;
    std::cout << "Address of c pointer pInt=" << pInt << std::endl;
    std::cout << "Value c of pointer pInt=" << *pInt << std::endl;
    /// This will not compile either
    /// *pInt = 10;

    /// Pointer qInt is declared to point at read/write integer variable
    int *qInt {&c};
    std::cout << "Address of c pointer qInt=" << qInt << std::endl;
    std::cout << "Value c of pointer qInt=" << *qInt << std::endl;
    /// Hence we can change the value of the variable.
    *qInt = 10;
    std::cout << "Address of c pointer qInt=" << qInt << std::endl;
    std::cout << "Value c of pointer qInt=" << *qInt << std::endl;

}