//
// Created by Tryggve Sørensen on 08/12/2019.
//
#include "MyHandler.h"

MyHandler::MyHandler (int value) { m_counter = std::make_unique<int>(value); }

void MyHandler::func1 () { std::cout << "In func1=n"; }

void MyHandler::func2 (MyOtherClass *moc) { std::cout << moc->m_cName << std::endl; }