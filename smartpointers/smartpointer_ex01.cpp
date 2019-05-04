//
// Created by tryggve on 5/4/19.
//

#include <iostream>
#include <memory>

class Rectangle {
private:
    float m_width;
    float m_height;
    std::string m_id;
public:

    // NOTE: const after the argument list indicates that this function will not alter/modify the
    // state of the object (of type Rectangle).
    // The const at the start is different. It says that the return of the function is a const string reference
    // See Stroustrup 16.2.9.1
    const std::string &getId() const {
        return m_id;
    }

    void setId(const std::string &mId) {
        m_id = mId;
    }

public:
    // Constructor
    Rectangle (float w, float h) : m_width(w) , m_height(h) {}
    float area() {return m_width * m_height;}

    // Destructor
    ~Rectangle(){std::cout << m_id << ": Rectangle destructor" << std::endl;}
};

int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== SMARTPOINTER EXAMPLE                                              ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    std::cout << "Creating raw pointer myRect...\n";
    Rectangle* myRect = new Rectangle(1, 1);
    myRect->setId("myRect");
    std::cout << "The area of myRect is: " << myRect->area() << std::endl;

    std::cout << "Creating shared pointer mySharedRect...\n";
    std::shared_ptr<Rectangle> mySharedRect = std::make_shared<Rectangle>(1, 2);
    mySharedRect->setId("mySharedRect");
    std::cout << "The area of mySharedRect is: " << mySharedRect->area() << std::endl;
}