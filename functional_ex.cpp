/**
 * Self training cplusplus features
 *
 * Some ideas:
 * pointers and references
 * auto
 * templates
 * type casting
 * standard library - selected topics
 */


#include <iostream>
#include <functional>

// Check this good explanation about std::bind
// https://stackoverflow.com/questions/37636373/how-stdbind-works-with-member-functions


/**
 * The following class example illustrates the binding principle of class member functions
 * This is not using std::bind. But it shows the principle behind std::bind usage for
 * class member functions.
 */
class MyFoo {
  private:
  int value;

  public:
  // NOTE: Functions have to be public to be called from outside of class scope
  void f () { std::cout << "f(" << this->value << ")\n"; }
  void g () { std::cout << "g(" << this->value << ")\n"; }

  // Here is a function that takes parameters
  void h (int a, int b, int c) {
    std::cout << "h(" << a << "," << b << "," << c << ")\n";
  }

  MyFoo (int v) { value = v; }
};

/**
 * To call a member function you need a pointer to the object of the class
 * that defines the function and the function pointer.
 * @param foo1 Pointer to object of class MyFoo
 * @param foo2 Pointer to object of class MyFoo
 * @param fun Pointer to member function of class MyFoo with signature void(*)() such as f() and g() above
 */
void apply (MyFoo *foo1, MyFoo *foo2, void(MyFoo::*fun) ()) {
  (foo1->*fun) ();     // Call the member function in object instance foo1
  (foo2->*fun) ();     // Call the member function in object instance foo2
}


/**
 * Example of binding to function void f(int, int, int)
 */
void f(int a, int b, int c) {
    std::cout << "a=" << a <<"\t\tb=" << b << "\t\tc=" << c << std::endl;
}

// Replace functions f with g where one of the arguments is fixed - in this case b=4 always.
// The placeholders refers to argument positions in function g
auto g = std::bind(f, std::placeholders::_1, 4, std::placeholders::_2);

// We can even reorder the argument position to function parameter assignment
auto h = std::bind(f, std::placeholders::_2, 4, std::placeholders::_1);



int main() {
  std::cout << "Hello, World!" << std::endl;

  f(1, 2, 3);

  // Replace functions f with g where one of the arguments is fixed - in this case b=4 always.
  // The placeholders refers to argument positions in function g
  std::cout << std::endl << "b=4 always" << std::endl;
  //auto g = std::bind(f, std::placeholders::_1, 4, std::placeholders::_2);
  g(1, 2);
  h(1, 2);

  std::cout << "\n\n========  EXAMPLE 2  BINDING TO CLASS MEMBER FUNCTIONS  ==========\n\n";
  // Instantiate two objects of class MyFoo
  MyFoo myFoo1(10);
  MyFoo myFoo2(20);

  // This calls the declared function with object pointers and member functions.
  apply(&myFoo1, &myFoo2, &MyFoo::f);
  apply(&myFoo1, &myFoo2, &MyFoo::g);



  // NOTICE: BIND ONLY WORKS WHEN WE HAVE CREATED THE OBJECT INSTANCES - AT RUN-TIME WHEREAS THE
  // APPLY FUNCTION IS DECLARED UP FRONT BUT INVOKES THE MEMBER FUNCTIONS AT RUN-TIME (AFTER THE
  // OBJECTS HAVE BEEN INSTANTIATED.

  // Bind to myFoo1 object's member function f()
  auto myBindFunc = std::bind(&MyFoo::f, &myFoo1);
  std::cout << "Call myBindFunc: : ";
  myBindFunc();       // Call member function through binding

  // Bind to myFoo2 object's member function h(int, int, int) passing parameters, notice the return type
  // of std::bind() is an object of type std::function<void(int,int,int) i.e. the signature of h()
  // Notice the use of auto above to avoid this syntax.
  std::function<void(int, int, int)> myFoo2func;
  myFoo2func = std::bind(&MyFoo::h, &myFoo2, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
  std::cout << "Call myFoo2func : ";
  myFoo2func (1, 2, 3);


  return 0;
}