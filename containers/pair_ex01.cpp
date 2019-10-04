//
// Created by trysoe on 10/3/19.
//
// This shows the use of utility class template 'pair' from standard library
//

#include <iostream>
#include <utility>




int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== CONTAINER: PAIR EXAMPLE                                           ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;


    std::cout << "\n\n\n";
    std::cout << "====== EXAMPLE 1 =========================================================\n";
    // Define a pair of integers.
    std::pair<int, int> myPair(10, 19);

    std::cout << "Here is my integer pair: (" << myPair.first << "," << myPair.second << ")\n";
    std::cout << "=========================================================================\n";

    exit(0);
}