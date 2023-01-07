//
// Created by Tryggve Sørensen on 07/01/2023.
//
// http://thbecker.net/articles/rvalue_references/section_01.html

#include <iostream>

int my_int = 38;

int& foo() {
  // This will compile as my_int is lvalue
  return my_int;

  // This will not compile as 0 is rvalue
  // return 0;

  // Warning as foo_int is on the call stack
  /*
  int foo_int = 100;
  return foo_int;
  // */
}

int main(int argc, char* argv[]) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== REFERENCES LVALUE RVALUE EXAMPLES                                 ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  std::cout << "==========================================================================" << std::endl;

  int a = 42;
  int b = 43;

  // a and b are both l-values:
  a = b; // ok
  b = a; // ok
  a = a * b; // ok

  // a * b is an rvalue:
  int c = a * b; // ok, rvalue on right hand side of assignment
  // a * b = 42; // error, rvalue on left hand side of assignment

  // lvalues:
  //
  int i = 42;
  i = 43; // ok, i is an lvalue
  int* p = &i; // ok, i is an lvalue
  int& foo(); // This is just a (forward) declaration. Function is defined above!

  // Function returns reference to int (int&) which is global variable my_int (defined above)
  foo() = 42; // ok, foo() is an lvalue. my_int changes value to 42
  int* p1 = &foo(); // ok, foo() is an lvalue.

  // Define pointer to foo function
  // https://www.cprogramming.com/tutorial/function-pointers.html
  int& (*p2)() = &foo; // Note that the function name is a lvalue (associated with memory location)
  // call the function - note that the function call p2() is an rvalue
  int result1 = p2();
  // Same as above
  int& result2 = p2();

}