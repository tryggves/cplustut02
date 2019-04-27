//
// Created by Tryggve Sørensen on 2019-04-20.
//
//
// Here is an example using Standard Template Library Vector
//

#include <iostream>
#include <vector>

// EXAMPLE 2: Define class to be contained in vector
template <class T>
class MyNumContainer {
    T m_value;

public:
    // Here is the constructor - initialize member property m_value
    MyNumContainer (T val) : m_value (val) {

        // EXAMPLE: Illustrate UNSCOPED ENUM
        // The names from the enum leaks into the containing scope
        // Underlying default type for both unscoped and scoped enums is integer,
        // but that can be overridden.
        enum ContainerForm {small, medium, large}; // UNSCOPED ENUM - here it shows the normal use
        ContainerForm form = small;
        /*
        // Try to declare small as bool, but Heltall has leaked into this scope
        bool small = false;       // WILL NOT COMPILE
        //*/
        // SCOPED ENUM OR CLASS ENUM WILL SOLVE THIS
        // This declaration uses specified underlying type of std::uint32_t
        enum class ContainerColor: std::uint32_t {white = 0, blue = 1, red = 2};
        ContainerColor myCont = ContainerColor ::white;
        bool white = false;

    };

    // Here is how to overload the output stream operator
    friend std::ostream& operator<<( std::ostream& output, const MyNumContainer& mNC ) {
        output << mNC.m_value;
        return output;
    }
};

int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== STANDARD TEMPLATE LIBRARY EXAMPLE                                 ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    std::cout << "EXAMPLE: Vector container of integers" << std::endl;
    std::vector<int> intVec;
    int i;

    std::cout << "Size of intVec: " << intVec.size() << std::endl;

    for (i=0; i<10; i++) {
        intVec.push_back(i);
    }
    std::cout << "Size of intVec: " << intVec.size() << std::endl;
    std::cout << "intVec contains: ";

    // Notice the compact syntax for accessing values of vector in the loop.
    for (int x:intVec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Try out the custom class example
    std::cout << "EXAMPLE 2: CUSTOM CLASS IN VECTOR" << std::endl;
    std::vector<MyNumContainer<int>> mNCvec;
    for (i=0; i<10; i++) {
        MyNumContainer<int> mnc(i);     // Calls the constructor of class MyNumContainer
        mNCvec.push_back(mnc);
    }
    std::cout << "Size of mNCvec: " << mNCvec.size() << std::endl;
    std::cout << "mNCvec contains: ";
    for (MyNumContainer<int> x:mNCvec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Can we make pointers to the class
    std::cout << "EXAMPLE 3: CUSTOM CLASS POINTERS IN VECTOR" << std::endl;
    std::vector<MyNumContainer<int>*> mNCPvec;
    std::cout << "Size of mNCPvec: " << mNCPvec.size() << std::endl;
    // Pointer variable
    MyNumContainer<int>* mNCP;
    for (i=0; i<10; i++) {
        mNCP = new MyNumContainer<int>(i);  // Instantiate class on heap
        mNCPvec.push_back(mNCP);
    }
    std::cout << "Size of mNCPvec: " << mNCPvec.size() << std::endl;
    std::cout << "mNCPvec contains: ";
    for (MyNumContainer<int>* xp:mNCPvec) {
        std::cout << *xp << " ";
    }
    std::cout << std::endl;
}
