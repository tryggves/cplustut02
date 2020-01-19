//
// Created by tryggve on 1/18/20.
//
#include <iostream>
#include "MyFunctionalClass.h"

int MyFunctionalClass::myFunction (int a, int b, int c) {
  m_a = a;  // Set for use by callback
  m_b = b;  // Set for use by callback
  m_sum = a + b + c;
  return m_sum;
}

/**
 * This registers a callback function of type MyFuncCallback. Declared in header file.
 * @param cb reference to callback function implementation.
 */
void MyFunctionalClass::onCallback (const MyFuncCallback &cb) {
  m_callback = cb;
}

/**
 * Demo calling callback function
 */
void MyFunctionalClass::demoCallback () {
  m_callback (m_a, m_b);
}

