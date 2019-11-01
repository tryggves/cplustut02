/**
 * Self training cplusplus features
 *
 * Some ideas:
 * pointers and references
 * auto
 * templates
 * type casting
 * standard library - selected topics
 */


#include <iostream>
#include <functional>

// Check this good explanation about std::bind
// https://stackoverflow.com/questions/37636373/how-stdbind-works-with-member-functions

void f(int a, int b, int c) {
    std::cout << "a=" << a <<"\t\tb=" << b << "\t\tc=" << c << std::endl;
}

// Replace functions f with g where one of the arguments is fixed - in this case b=4 always.
// The placeholders refers to argument positions in function g
auto g = std::bind(f, std::placeholders::_1, 4, std::placeholders::_2);
// We can even reorder the argument position to function parameter assignment
auto h = std::bind(f, std::placeholders::_2, 4, std::placeholders::_1);

int main() {
    std::cout << "Hello, World!" << std::endl;

    f(1, 2, 3);

    // Replace functions f with g where one of the arguments is fixed - in this case b=4 always.
    // The placeholders refers to argument positions in function g
    std::cout << std::endl << "b=4 always" << std::endl;
    //auto g = std::bind(f, std::placeholders::_1, 4, std::placeholders::_2);
    g(1, 2);
    h(1, 2);

    return 0;
}