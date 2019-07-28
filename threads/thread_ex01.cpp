//
// Created by tryggve on 5/26/19.
//

// Multiple thread example.

#include <iostream>
#include <thread>
#include <chrono>

const int numIterations=1000;       // Number of iterations to be performed by tasks

// TASK: Function or function object.
void task1() {
    std::cout << "Hello, I am task1: ";

    for (int i=0; i<numIterations; ++i) {
        std::cout << "1";

        // Print newline on every 20th iteration
        if ((i % 20) == 0) {
            std::cout << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << ".";
}

// TASK
void task2() {
    std::cout << "Hello, I am task2: ";

    for (int i=0; i<numIterations; ++i) {
        std::cout << "2";

        // Print newline on every 20th iteration
        if ((i % 20) == 0) {
            std::cout << std::endl;
        }

        // sleeping 50% longer on each iteration for this task will show up in the output, as
        // task 1 has to wait for this  task to finish.
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
    std::cout << "\nTask 2 number of iterations: " << numIterations << std::endl;
}

int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== CLASSES EXAMPLE 02                                                ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;

    std::thread t1 {task1};
    std::thread t2 {task2};

    t1.join();
    t2.join();

    std::cout << std::endl;

}