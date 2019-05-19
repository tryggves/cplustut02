//
// Created by tryggve on 5/11/19.
//

#include <iostream>
#include <initializer_list>
#include <vector>

// Anonymous namespace - limits scope of names to the source file
namespace {


// Example container class Vector of double elements.

// CONCRETE CLASSES:
// First example are classes defined the same way as built-in types.
// Later we will deal with abstract classes and class hierarchies etc.

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

// Vector with initializer list constructor
class ILVector {
private:
    std::vector<double> elem ;       // Array of vector elements (to be allcoated)
    int sz;             // Size of the vector
    std::string id = "class ILVector";    // Identifier - TODO maybe some std:: methods can provide this

public:

    // Initializer list constructor using std::initilizer_list
    ILVector (std::initializer_list<double> l) : elem(l) { sz = elem.size(); }


    // Destructor - release the resources
    ~ILVector() {
        std::cout << id << ": In destructor" << std::endl;
        //delete[] elem;  // Deletes the double array
    }

    // Here is how to overload the output stream operator
    friend std::ostream& operator<<( std::ostream& output, const ILVector& vec ) {
        output << vec.id;
        return output;
    }

    double& operator[](int i) { return elem[i]; };
    int size() const { return sz; };
};
}   // END NAMESPACE

void run_example1() {
    std::cout << "\n=== EXAMPLE 1 ===\n";

    Vector myVector(10);
    // Calling operator << on Vector
    std::cout << "Created object: " << myVector
    << " of size: " << myVector.size() << std::endl;

    std::cout << myVector << " contents: ";
    for (int i=0; i<myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    /*
     * NOTE: This is a concrete class. We dont have to call the destructor becuase
     * it is called by default when the object goes out of scope.
     * AS A USER OF VECTOR, IT BEHAVES AS A BUILT-IN TYPE. USERS DONT HAVE TO WORRY ABOUT FREEING RESOURCES.
     *
    delete myVector;
    //*/
}

// Create Vector on the head using new operator
void run_example2() {
    std::cout << "\n=== EXAMPLE 2 ===\n";

    Vector* myVectorPointer = new Vector(10);
    std::cout << "Created object: " << *myVectorPointer
              << " of size: " << myVectorPointer->size() << std::endl;

    // NOTE!
    // Forget to call destructor and you will have a memory leak
    delete(myVectorPointer);
}

// Try the initializer_list constructor
void run_example3() {
    std::cout << "\n=== EXAMPLE 3 ===\n";

    ILVector iListVector {1,2,3,4,5};
    std::cout << "iListVector content: ";
    for (int i=0; i<iListVector.size(); ++i){
        std::cout << iListVector[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== CLASSES EXAMPLE 01                                                ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    run_example1();
    run_example2();
    run_example3();
}