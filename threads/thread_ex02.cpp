//
// Created by Tryggve Sørensen on 2019-06-16.
//


#include <iostream>
#include <vector>
#include <functional>           // For using std::ref()
#include <thread>               // For using thread


// Passing data to thread functions

// This function takes a reference to vector of double
void task1 (std::vector<double>& v)  {
    double sum = 0.0;

    for (double element : v) {
        sum += element;
    }
    std::cout << "Sum1 = " << sum << std::endl;
}

// Here is a function object
struct Task2 {
    std::vector<double> v;
    // Explicit contructor - see Stroustrup 16.2.6 (explicit Constructors)
    explicit Task2(std::vector<double>& vv) : v{vv} { }      // Constructor
    void operator() () {
        double sum = 0.0;
        for (double element : v) {
            sum += element;
        }
        std::cout << "Sum2 = " << sum << std::endl;
    }
};



int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== CLASSES EXAMPLE 02                                                ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;

    std::vector<double> myVec {1.0, 2.0, 1.5, 4, 3.8, 5.2, 4,7, 1.0, 2.0, 1.5, 4, 3.8, 5.2, 4,7};

    std::thread t1{task1, std::ref(myVec)};
    std::thread t2{Task2{myVec}};

    t1.join();
    t2.join();

    /*
    // Test task1
    task1( myVec );

    // Test task2
    Task2 t2(myVec);
    t2();
    //*/

}