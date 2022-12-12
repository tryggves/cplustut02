//
// Created by tryggve on 12/7/22.
//
// https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/
// 1. Static cast
// 2. Dynamic cast
// 3. Const cast
// 4. Reinterpret cast
#include <iostream>
using namespace std;

// See C++ Programming Language chapter 22.
//
class MyBaseClass1 {
    // Private declaration of print()
    void print()
    {
      cout << "MyBaseClass1 class" << endl;
    }
};

class MyDerivedClass1 : public MyBaseClass1 {
public:
    void print()
    {
      cout << "MyDerivedClass1 class" << endl;
    }
};

class MyDerivedClass2: public MyBaseClass1 {
    void print() {
      cout << "MyDerivedClass2 class" << endl;
    }
};

int main (int argc, char **argv) {
  cout << "==========================================================================" << endl;
  cout << "=== TYPECASTING              EXAMPLES                                 ====" << endl;
  cout << "=== Program name: " << argv[0] << endl;
  cout << "=== Number of arguments: " << argc << endl;
  cout << "==========================================================================" << endl;

  MyDerivedClass1 derived1;

  // Function print() is public
  derived1.print();

  // Base class pointer hold derived1
  // This is 'upcasting' (from derived to base class casting)
  MyBaseClass1 *basePtr = dynamic_cast<MyBaseClass1*>(&derived1);
  // This will not compile because print() is private
  // basePtr->print();


}