//
// Created by Tryggve Sørensen on 2019-04-20.
//
//
// Here is an example using Standard Template Library Vector
//

#include <iostream>
#include <vector>

// EXAMPLE 2: Define class to be contained in vector
template<class T>
class MyNumContainer {
  T m_value;

public:
  // Here is the constructor - initialize member property m_value
  MyNumContainer(T val) : m_value(val) {

    // EXAMPLE: Illustrate UNSCOPED ENUM
    // The names from the enum leaks into the containing scope
    // Underlying default type for both unscoped and scoped enums is integer,
    // but that can be overridden.
    enum ContainerForm {
      small, medium, large
    }; // UNSCOPED ENUM - here it shows the normal use
    ContainerForm form = small;
    /*
    // Try to declare small as bool, but "small" has leaked into this scope
    bool small = false;       // WILL NOT COMPILE
    //*/
    // SCOPED ENUM OR CLASS ENUM WILL SOLVE THIS
    // This declaration uses specified underlying type of std::uint32_t
    enum class ContainerColor : std::uint32_t {
      white = 0, blue = 1, red = 2
    };
    ContainerColor myCont = ContainerColor::white;
    bool white = true;

  };

  // Here is how to overload the output stream operator
  // Overload: same function, different parameters or types of parameters
  // Override: same function, in derived (sub-) class
  friend std::ostream &operator<<(std::ostream &output, const MyNumContainer &mNC) {
    // std::ostream& operator<<( std::ostream& output, const MyNumContainer& mNC ) const {
    output << mNC.m_value;
    return output;
  }
};

int main(int argc, char **argv) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== STANDARD TEMPLATE LIBRARY EXAMPLE                                 ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  std::cout << "==========================================================================" << std::endl;

  std::cout << "EXAMPLE: Vector container of integers" << std::endl;
  std::vector<int> intVec;

  // Use auto in for loop deriving type of i from initialization rather than declaring i here
  // int i;

  std::cout << "Size of intVec: " << intVec.size() << std::endl;

  for (auto i = 0; i < 10; i++) {
    intVec.push_back(i);
  }
  std::cout << "Size of intVec: " << intVec.size() << std::endl;
  std::cout << "intVec contains: ";

  // Notice the compact syntax for accessing values of vector in the loop.
  for (auto x:intVec) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  // Try out the custom class example
  std::cout << "EXAMPLE 2: CUSTOM CLASS IN VECTOR" << std::endl;
  std::vector<MyNumContainer<int>> mNCvec;
  std::cout << "Size of mNCvec: " << mNCvec.size() << std::endl;
  for (auto i = 0; i < 10; i++) {
    // Unsure if auto makes sense here since we make assumption about the outcome of the
    // type expression in the for loop when instantiating the MyNumContainer object to have
    // member type int.
    MyNumContainer<int> mnc(i + 10);     // Calls the constructor of class MyNumContainer
    mNCvec.push_back(mnc);
  }
  std::cout << "Size of mNCvec: " << mNCvec.size() << std::endl;
  std::cout << "mNCvec contains: ";
  // We can use auto here to initialize x from iterator.
  // Using auto here seems to make more sense than in the for loop above.
  // for (MyNumContainer<int> x : mNCvec) {
  for (auto x : mNCvec) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  // Can we make pointers to the class
  std::cout << "EXAMPLE 3: CUSTOM CLASS POINTERS IN VECTOR" << std::endl;
  std::vector<MyNumContainer<int> *> mNCPvec;
  std::cout << "Size of mNCPvec: " << mNCPvec.size() << std::endl;
  // Pointer variable
  MyNumContainer<int> *mNCP;
  for (auto i = 0; i < 10; i++) {
    mNCP = new MyNumContainer<int>(i + 20);  // Instantiate class on heap
    mNCPvec.push_back(mNCP);
  }
  std::cout << "Size of mNCPvec: " << mNCPvec.size() << std::endl;
  std::cout << "mNCPvec contains: ";
  // We can use auto here to infer type of xp from the iterator
  // for (MyNumContainer<int>* xp:mNCPvec) {
  for (auto *xp:mNCPvec) {
    std::cout << *xp << " ";
  }
  std::cout << std::endl;

  /*
  // Can we use a reference to the contained elements
  // Unsure if & makes sense in this context.
  // THIS WILL NOT COMPILE - CANNOT CONVERT FROM INT POINTER TO INT REFERENCE
  for (MyNumContainer<int>& xr:mNCPvec) {
      std::cout << xr << " ";
  }
  //*/
}
