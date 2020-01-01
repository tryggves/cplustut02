//
// Created by Tryggve Sørensen on 23/12/2019.
//
/**
 * This class is to we executed by a worker thread.
 * Useful site: https://www.learncpp.com/learn-cpp-site-index/
 */

#ifndef CPLUSTUT02_WORKERCLASS_H
#define CPLUSTUT02_WORKERCLASS_H

#include <iostream>
#include "SharedState.h"

class WorkerClass {
private:
    std::string m_name;         // Identify the class instance (for logging)
    int m_localState;            // Some internal state
    bool m_stopRequest;          // A stop thread request causing thread to exit its event loop

    /// The class should also be able to handle access with shared state
    /// This needs to be synchronized

public:
    WorkerClass (std::string name);

    /// The entry point for the worker thread
    void run (SharedState& shared);

    /// No shared state passed
    void simpleRun ();

    /// Entry point with parameter passed by value
    void simpleRunValueParam (int x);

    /// Entry point with parameter passed by reference - notice that the reference
    /// is declared as const (does not work without).
    /// https://thispointer.com//c11-multithreading-part-3-carefully-pass-arguments-to-threads/
    void simpleRunReferenceParam (const int & x);

    /// Request any worker thread on this object to halt its main loop
    void stopWorker ();
};

#endif //CPLUSTUT02_WORKERCLASS_H
