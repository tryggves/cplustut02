//
// Created by Tryggve Sørensen on 08/12/2019.
//

#include "MyOtherClass.h"

MyOtherClass::MyOtherClass() {
    m_handler = std::make_unique<MyHandler>(0);
}