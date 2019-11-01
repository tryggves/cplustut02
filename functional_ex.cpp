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

// The following class example illustrates the binding principle of class member functions
// This is not using std::bind. But it shows the principle behind std::bind usage for
// class member functions.
class MyFoo {
private:
    int value;

public:
    // NOTE: Functions have to be public to be called from outside of class scope
    void f() { std::cout << "f(" << this->value << ")\n"; }
    void g() { std::cout << "g(" << this->value << ")\n"; }
    MyFoo(int v) { value = v; }
};

// To call a member function you need a pointer to the object of the class
// that defines the function and the function pointer.
void apply (MyFoo* foo1, MyFoo* foo2, void(MyFoo::*fun)()) {
    (foo1->*fun)();     // Call the member function in object instance foo1
    (foo2->*fun)();     // Call the member function in object instance foo2
}

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

    MyFoo myFoo1(10);
    MyFoo myFoo2(20);

    apply(&myFoo1, &myFoo2, &MyFoo::f);

    return 0;
}