//
// Created by Tryggve Sørensen on 22/12/2019.
//
/**
 * This is to simulate a shared state between threads.
 */

#ifndef CPLUSTUT02_SHAREDSTATE_H
#define CPLUSTUT02_SHAREDSTATE_H

class SharedState {
private:
    int counter;

public:
    SharedState(int initialValue) : counter {initialValue} {}
    int getCounter () { return counter; }
    void countOneMore () { counter++; }
};
#endif //CPLUSTUT02_SHAREDSTATE_H
