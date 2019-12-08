//
// Created by Tryggve Sørensen on 08/12/2019.
//

#ifndef CPLUSTUT02_MYOTHERCLASS_H
#define CPLUSTUT02_MYOTHERCLASS_H

#include <string>
#include <memory>
#include "MyHandler.h"
/**
 * Example of two classes cross referencing each other. This is
 * implemented using forward declaration of the other class in this
 * header file as next statement. But to make this work there cannot be
 * any implementation dependencies in the header.
 */
class MyHandler;

class MyOtherClass {
private:
    std::unique_ptr<MyHandler> m_handler;
public:
    MyOtherClass ();
    std::string m_cName = "MyOtherClass";
};


#endif //CPLUSTUT02_MYOTHERCLASS_H
