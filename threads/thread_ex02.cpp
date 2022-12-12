//
// Created by Tryggve Sørensen on 08/12/2022.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <random>

// Examples from C++ standard library book
// Here is the worker function to be run by thread
void doSomething(char c) {
  std::default_random_engine dre(c);
  std::uniform_int_distribution<int> id(10, 1000);

  for (int i=0; i<10; i++) {
    // Loop and print character after sleep
    std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
    std::cout.put(c).flush();
  }
}

int main(int argc, char **argv) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== THREADS EXAMPLE 02                                                ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  std::cout << "==========================================================================" << std::endl;

  std::cout << "Starting two threads simultaneously" << std::endl;
}