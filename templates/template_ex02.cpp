//
// Created by Tryggve Sørensen on 2019-04-20.
//
//
// Here is an example using Standard Template Library Vector
//

#include <iostream>
#include <vector>


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

}
