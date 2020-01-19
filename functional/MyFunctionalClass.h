//
// Created by tryggve on 1/18/20.
//

#ifndef _MYFUNCTIONALCLASS_H_
#define _MYFUNCTIONALCLASS_H_
#include <functional>

/// This is a typedef to a void function taking two arguments
using MyFuncCallback = std::function<void (int a, int b)>;


class MyFunctionalClass {
private:
  int m_a, m_b;
  int m_sum;
  MyFuncCallback m_callback;

public:
  /// Member function
  int myFunction (int a, int b, int c);

  /// Register callback function - notice the typedef above.
  void onCallback(const MyFuncCallback& cb);

  /// This will demo call to callback function
  void demoCallback ();
};

#endif //_MYFUNCTIONALCLASS_H_
