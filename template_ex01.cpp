//
// Created by Tryggve Sørensen on 2019-04-18.
//
# include <iostream>

// Try to code a specific class first an then refactor to template class
class Calc {
public:
    int add (int a, int b) { return a + b; }
    int sub (int a, int b) { return a - b; }
};

int main(int argc, char* argv[]) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== REFERENCES LVALUE RVALUE EXAMPLES                                 ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    Calc myCalc;
    int c = myCalc.add(1, 2);
    std::cout << "1 + 2 = " << c << std::endl;
    std::cout << "1 - 2 = " << myCalc.sub(1, 2) << std::endl;
}