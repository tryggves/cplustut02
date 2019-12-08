//
// Created by Tryggve Sørensen on 08/12/2019.
//

#ifndef CPLUSTUT02_MYOTHERCLASS_H
#define CPLUSTUT02_MYOTHERCLASS_H

#include <string>
#include <memory>
#include "MyHandler.h"
class MyHandler;

class MyOtherClass {
private:
    std::unique_ptr<MyHandler> m_handler;
public:
    MyOtherClass ();
    std::string m_cName = "MyOtherClass";
};


#endif //CPLUSTUT02_MYOTHERCLASS_H
