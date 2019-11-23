//
// Created by Tryggve Sørensen on 17/11/2019.
//

#include <iostream>
#include <vector>
#include <deque>
#include <map>

/**
 * Deque is a double ended array where it is cheap to insert elements
 * in the front and the end.
 */
void example3 () {
    std::cout << "==========================================================================\n";
    std::cout << "EXAMPLE 3: DEQUE\n";
    std::cout << "==========================================================================\n";

    std::deque<float> myFltDeque;       // Declares empty

    // Notice this initialization of i in the for loop
    for (int i : {1,2,3,4,5,6}) {
        std::cout << "i: " << i << "\n";
        // This pushes numbers to the front of the vector
        myFltDeque.push_front(i*1.1);
    }

    // Iterate through the array
    std::cout << "myFltDeque: ";
    for (auto e : myFltDeque) {
        std::cout << e << ", ";
    }
    std::cout << "\n";

    // Push to back of vector
    // Notice this initialization of i in the for loop
    std::cout << "Push to back of vector...\n";
    for (int i : {1,2,3,4,5,6}) {
        std::cout << "i: " << i << "\n";
        // This pushes numbers to the back of the vector
        myFltDeque.push_back(i*1.1);
    }

    // Iterate through the array
    std::cout << "myFltDeque: ";
    for (auto e : myFltDeque) {
        std::cout << e << ", ";
    }
    std::cout << "\n";
}


void example2 () {
    std::cout << "==========================================================================\n";
    std::cout << "EXAMPLE 2: VECTOR\n";
    std::cout << "==========================================================================\n";
    std::vector<int> myIntVec {1, 2, 3, 4, 5, 6};
    int sum {0};

    std::cout << "Size: " << myIntVec.size() << "\n";
    for (auto x : myIntVec) {
        std::cout << "Adding " << x << " to sum\n";
        sum += x;
    }
    std::cout << "Sum: " << sum << "\n";

    // access elements of vector
    sum = myIntVec[3] + myIntVec[4];
    std::cout << "Sum: " << sum << "\n";
}

int main (int argc, char **argv){
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== VECTOR EXAMPLES                                                   ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    std::map<std::string, std::string> pMap1 {
            {"vdbExchange", "MessagingExchange"},
            {"vdbTopic", "Vessebus.topic1"},
            {"adapterType", "FORWARD"}
    };


    std::map<std::string, std::string> pMap2 {{
            {"vdbExchange", "MessagingExchange"},
            {"vdbTopic", "Vessebus.topic2"},
            {"adapterType", "INTERNAL"}}
    };

    std::vector<std::map<std::string, std::string>> listeners;
    listeners.push_back(pMap1);
    listeners.push_back(pMap2);

    example2();
    example3();

}
