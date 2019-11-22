//
// Created by Tryggve Sørensen on 2019-04-21.
//
// Examples of initialization of variables.
//
// Many ways to initialize:
// equal
// parantheses
// braces


#include <iostream>

// EXAMPLE 2 CLASS EXAMPLE
// Using initilization in class - parentheses does not work
class MyC {
public:
    int a = 10;
    int b{20};
    // int c(0);       // Does not work
};

/**
 * Uniform initialization was introduced with C++11
 */
struct MySt {
    int num1 {10};
    int num2 {20};
};

int main (int argc, char *argv[]) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== INITIALIZATION EXAMPLES                                           ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    std::cout << "EXAMPLE 1: VARIABLE INITIALIZATION" << std::endl;
    int var1 = 1;       // Equal initialization
    int var2(2);       // Parentheses initialization
    int var3{3};       // Braces initialization
    std::cout << "var1 = " << var1 << std::endl;
    std::cout << "var2 = " << var2 << std::endl;
    std::cout << "var3 = " << var3 << std::endl;

    std::cout << "EXAMPLE 2: CLASS VARIABLES" << std::endl;
    // Initialize variable of a class
    MyC c1;     // NOT ASSIGNMENT: This calls the default constructor
    std::cout << "c1.a = " << c1.a
              << "\tc1.b = " << c1.b << std::endl;
    MyC c2 = c1;    // NOT ASSIGNMENT:  This calls the (default) copy constructor
    std::cout << "c2.a = " << c2.a
              << "\tc2.b = " << c2.b << std::endl;
    c2.b = 222;       // Just to show c2 and c1 reference different instances
    c1 = c2;    // ASSIGNMENT: This calls the copy operator=
    std::cout << "c1.a = " << c1.a
              << "\tc1.b = " << c1.b << std::endl;

    std::cout << "EXAMPLE 3: UNIFORM INITIALIZATION\n";
    MySt mySt;
    std::cout << "mySt.num1: " << mySt.num1 << "\n";
    std::cout << "mySt.num2: " << mySt.num2 << "\n";
}