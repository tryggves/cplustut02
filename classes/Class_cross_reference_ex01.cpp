//
// Created by Tryggve Sørensen on 08/12/2019.
//

#include <iostream>
#include <memory>
#include "MyOtherClass.h"

int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== CLASSES EXAMPLE 03                                                ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    std::unique_ptr<MyOtherClass> myOtherClass;
    myOtherClass = std::make_unique<MyOtherClass>();

    return 0;
}