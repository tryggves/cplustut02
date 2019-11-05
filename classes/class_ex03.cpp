//
// Created by trysoe on 05/11/2019.
//

#include <iostream>

/**
 * Demo class inheritance.
 * For a good explanation see:
 * https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance
 */

// Base class
class MyBaseClass {
public:
    // Everyone can access public members
    const std::string name = "MyBaseClass";
    int a = 0;

protected:
    // Subclasses of MyBaseClass can access protected members
    int b = 0;

private:
    // Only MyBaseClass can access private members
    int c = 0;
};

// Subclass inherit from MyBaseClass and the inheritance chain is visible to everyone
class MyPubSubClass : public MyBaseClass {
public:
    int a = 0;
    const std::string name = "MySubClass";
};

// Subclass inherit from MyBaseClass and the inheritance chain is visible to children of MyProtSubClass
class MyProtSubClass : protected MyBaseClass {
public:
    const std::string name = "MyProtSubClass";
};

// Subclass inherit from MyBaseClass and the inheritance chain is visible to this class only
class MyPrivSubClass : private MyBaseClass {
public:
    const std::string name = "MyPrivSubClass";
};


/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== CLASSES EXAMPLE 03                                                ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    // Instantiate classes.
    MyPubSubClass pubClass;
    MyProtSubClass protClass;
    MyPrivSubClass privClass;

    std::cout << "MyPubClass name: " << pubClass.name << "\n";
    // Access the base class members - notice syntax - this is due to multiple inheritance in
    // c++. There is nothing like a super() implicit method like in Java.
    std::cout << "MyPubClass base class name: " << pubClass.MyBaseClass::name << "\n";

    // NB! This is overkill as MyBaseClass::a is accessible through child class
    // pubClass.a = 2 will give the same effect unless child class overrides the member a
    pubClass.MyBaseClass::a = 20;       // Base class member a
    pubClass.a = 2;                     // Child class member a
    std::cout << "Child class member a value: " << pubClass.a << "\n";
    std::cout << "Base class member a value: " << pubClass.MyBaseClass::a << "\n";

    std::cout << "MyProtClass name: " << protClass.name << "\n";
    // This will not work compile since the inheritance is protected
    // std::cout << "Superclass name: " << protClass.MyBaseClass::name << "\n";


    exit (0);
}