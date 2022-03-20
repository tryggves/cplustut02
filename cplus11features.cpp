//
// Created by Tryggve Sørensen on 15/03/2022.
//

#include <iostream>

class MyFeaturesClass {
public:
  void my_func(std::string *p_string) {
    if (p_string == nullptr) {
      std::cout << "Nullpointer parameter\n";
    } else {
      // This prints the pointer address
      std::cout << "Parameter pointer is " << p_string << std::endl;
      // This prints the value
      std::cout << "Parameter value is \"" << *p_string << "\"" << std::endl;
    }
  }

  // Overload the function
  void my_func(std::nullptr_t aNullptr) {
    std::cout << "Nullpointer parameter ended in overloaded class\n";
  }
};




int main(int argc, char **argv) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== C++11 EXAMPLEs                                              ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  std::cout << "==========================================================================" << std::endl;

  MyFeaturesClass myFeaturesClass;
  myFeaturesClass.my_func(nullptr);

  std::string my_hello = "Hello world";
  myFeaturesClass.my_func(&my_hello);

}