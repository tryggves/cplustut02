//
// Created by tryggve on 1/18/20.
//
#include <iostream>
#include <memory>
#include <functional>

#include "MyFunctionalClass.h"

/// This callback will be registered in MyFunctionalClass
class MyCallbackClass {
public:
  void callbackImpl (int a, int b, int c) {
    std::cout << "Callback implementation class";
    std::cout << " a=" << a << " b=" << b << " c=" << c << std::endl;
  }
} callbackInstance;

int main (int argc, char** argv) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== FUNCTIONAL EXAMPLE 01                                             ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  std::cout << "==========================================================================" << std::endl;


  // MyCallbackClass callback;

  /// Declare and call constructor
  std::shared_ptr<MyFunctionalClass> shptr;
  shptr = std::make_shared<MyFunctionalClass>();

  /// Binding call
  /**
   * Notice: We do the call directly without associating the function to a variable, this is the
   * same as shprt->myFunction(10,2,3)
   * std::bind() returns the function pointer
   */
  int result = 0;
  result = std::bind(&MyFunctionalClass::myFunction, shptr, std::placeholders::_1, 2, 3)(10);
  std::cout << "Result is: " << result << std::endl;

  /// Register the callback function inside the callback class inside the functional class.
  /// Note that there is one more parameter in the callback implementation than the method signature in the functional
  /// class declares, this is magic... The placeholders, allows parameters to be passed from the functional class. The last
  /// parameter is provided by this scope!!
  int localInt = 40;
  shptr->onCallback (std::bind (&MyCallbackClass::callbackImpl, callbackInstance, std::placeholders::_1,
    std::placeholders::_2, localInt));
  shptr->demoCallback ();

  exit (0);
}