//
// Created by Tryggve Sørensen on 08/12/2019.
//

#ifndef CPLUSTUT02_MYHANDLER_H
#define CPLUSTUT02_MYHANDLER_H

#include <iostream>
#include <memory>
#include "MyOtherClass.h"
/**
 * Example of two classes cross referencing each other. This is
 * implemented using forward declaration of the other class in this
 * header file as next statement. But to make this work there cannot be
 * any implementation dependencies in the header.
 */
class MyOtherClass;

class MyHandler {
private:
    std::unique_ptr<int> m_counter;
public:
    explicit MyHandler (int value);
    void func1 ();
    void func2 (MyOtherClass *moc);
};

#endif //CPLUSTUT02_MYHANDLER_H
