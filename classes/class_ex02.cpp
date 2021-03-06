//
// Created by tryggve on 5/21/19.
//
#include <iostream>
#include <memory>

// Anonymous namespace
namespace {
    // This example shows a container class - the popular Vector container - similar to the std::vector class
    class Vector {
    private:
        double *elem;       // Array of vector elements (to be allcoated)
        int sz;             // Size of the vector
        std::string id = "class Vector";    // Identifier - TODO maybe some std:: methods can provide this

    public:
        // Constructor of double vector of size s and initialized each element to zero.
        Vector(int s) : elem{new double[s]}, sz{s} {
            for(int i=0; i<s; ++i) elem[i]=0;
        }

        // Initializer list constructor using std::initilizer_list
        Vector (std::initializer_list<double> l) {}

        // Destructor - release the resources
        ~Vector() {
            std::cout << id << ": In destructor" << std::endl;
            delete[] elem;  // Deletes the double array
        }

        // Here is how to overload the output stream operator
        friend std::ostream& operator<<( std::ostream& output, const Vector& vec ) {
            output << vec.id;
            return output;
        }

        double& operator[](int i) { return elem[i]; };
        int size() const { return sz; };
    };

    // Abstract class
    class Container {
    public:
        //
        // = 0 means pure virtual means Container is an interface
        virtual double& operator[](int) = 0;
        virtual int size() const = 0;
        virtual ~Container() {}
    };

    // Implementation class
    class Vector_container: public Container {
    private:
        Vector  v;

    public:
        Vector_container(int s) : v(s) {}
        ~Vector_container() { std::cout << "In Vector_container destructor...\n"; }

        double& operator[](int i) { return v[i]; }
        int size() const { return v.size(); }
    };
}

void run_example1() {
    Vector_container vc(10);

    std::cout << "Example 01\n";
    std::cout << "vc content: ";
    for (int i=0; i<vc.size(); ++i) {
        std::cout << vc[i] << " ";
    }
    std::cout << std::endl;
}

void run_example2() {
    // Create Vector_container on heap

    std::cout << "\nExample 02\n";
    Vector_container* vc = new Vector_container(10);
    std::cout << "Created Vector container of size: " << vc->size() << std::endl;

    // Go out of scope, but destructor not called.
}

void run_example3() {
    // Create smartpointer to vector on heap

    std::cout << "\nExample 03\n";
    std::unique_ptr<Vector_container> vc = std::make_unique<Vector_container>(20);
    std::cout << "Created Vector container of size: " << vc->size() << std::endl;

    // Go out of scope, destructor is called
}

int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== CLASSES EXAMPLE 02                                                ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;

    //*
    run_example1();

    run_example2();

    run_example3();
    //*/
}