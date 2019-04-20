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
    MyNumContainer (T val) : m_value (val) {};

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

    std::cout << "EXAMPLE: Vector container" << std::endl;
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
        MyNumContainer<int> mnc(i);
        mNCvec.push_back(mnc);
    }
    std::cout << "Size of mNCvec: " << mNCvec.size() << std::endl;
    std::cout << "mNCvec contains: ";
    for (MyNumContainer<int> x:mNCvec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

}
