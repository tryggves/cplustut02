//
// Created by Tryggve Sørensen on 11/12/2022.
//
// NOT COMPlETE!

#include <iostream>
#include <string>

class MyCat {
// struct MyCat {
  std::string m_name{""};
public:
  MyCat(std::string name) : m_name{name}
  {
  }

  std::ostream& operator<<(std::ostream& os, const MyCat& mc) {
    os << m_name;
    return os;
  }
};

int main(int argc, char* argv[]) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== REFERENCES LVALUE RVALUE EXAMPLES                                 ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  std::cout << "==========================================================================" << std::endl;

  MyCat cat1("Pus");
  std::cout << cat1 <<
}