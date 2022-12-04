//
// Created by Tryggve Sørensen on 04/12/2022.
//

#include <iostream>

// Lambda function syntax
// auto l_func = [] (int x, int y) { return x=y: }
// [] is the capture list - lambda access to names (variables) in the defining environment
// () contains the parameters to the lambda function
// { } contains the function statements
// The lambda function itself declares a callable (object)

// Lambda function with parameters
auto lambdaF1 = [] (int x) { std::cout << "x is: " << x << std::endl; };
// Return something from lanbda function
auto lambdaSum = [] (int x, int y) { return x=y; };

int main (int argc, char **argv) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== LAMBDA                   EXAMPLES                                 ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  std::cout << "==========================================================================" << std::endl;

  // Declare local variable to be accessed from lambda
  int l_x = 10101;
  int l_y = 0;

  // Declare variable lambdaFunc pointing to lambda function
  // This is a simple lambda function
  auto lambdaFunc = [] { std::cout << "Hello lambda function" << std::endl; };

  // Call the lambda function
  lambdaFunc();
  lambdaF1(100);
  std::cout << "100 + 200 = " << lambdaSum(100, 200) << std::endl;

  // This lambda function shall access l_x
  // This is done in the capture list [&] where '&' means capture by reference
  // Capture by value [=]
  auto l_func_double_ref = [&] { return (l_x * 2); };
  auto l_func_double = [=] { return (l_x * 2); };
  std::cout << "Multiply by 2: " << l_func_double() << std::endl;
  std::cout << "Multiply by 2: " << l_func_double_ref() << std::endl;

  // Lambda function can have side effects assigning variables outside its scope
  auto l_func_assign = [&] { l_y = 10000; };
  std::cout << "Before: " << l_y << std::endl;
  l_func_assign();
  std::cout << "After: " << l_y << std::endl;


}