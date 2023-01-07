//
// Created by tryggve on 1/7/23.
//

#include <iostream>
#include <vector>

class X {
private:
  std::vector<int> *m_pResource;
public:
  // Default constructor
  X() {
    m_pResource = new std::vector<int>();
    m_pResource->push_back(10);
    m_pResource->push_back(20);
    m_pResource->push_back(30);
  }

  // Copy assignment operator
  // This operator handles both a lvalue and rvalue rhs parameter
  X& operator=(X const & rhs){
    // make a clone of rhs m_pResource
    std::vector<int> *tmp =  new std::vector<int>();
    for (auto& value : *rhs.m_pResource) {
      tmp->push_back(value);
    }
    delete m_pResource;   // Delete the old m_pResource vector
    m_pResource = tmp;    // Resource now points to copy of rhs resource
    return *this;
  }

  /**
   * Calculate the sum of all elements in the resource
   * @return int sum of all elements held by the resource
   */
  int sum() {
    auto result = 0;
    for (auto& vectorValue : *m_pResource) {
      result += vectorValue;
    }
    return result;
  }

  /**
   * Add value X
   * @param value int new value
   */
  void addValue(int value) {
    m_pResource->push_back(value);
  }
};

int main(int argc, char* argv[]) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "===            LVALUE RVALUE EXAMPLES                                 ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  std::cout << "==========================================================================" << std::endl;

  X my_x;
  std::cout << "Vector sum of my_x is: " << my_x.sum() << std::endl;
  my_x.addValue(1020);
  std::cout << "Vector sum of my_x is: " << my_x.sum() << std::endl;

  X my_x2;
  my_x2 = my_x;
  std::cout << "Vector sum of my_x2 is: " << my_x.sum() << std::endl;
}
