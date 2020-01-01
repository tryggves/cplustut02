//
// Created by Tryggve Sørensen on 22/12/2019.
//
/**
 * This program should have a main loop working on the shared resource with worker
 * threads.
 */

#include <iostream>
#include <csignal>
#include <thread>
#include <chrono>
#include <vector>

#include "SharedState.h"
int getSharedState();       // Forward declare function - used in signal handler
#include "WorkerClass.h"

SharedState mySharedState(0);
/// Test global variable passed by value and reference
int x = 10;
/// Hold a vector of worker threads
std::vector<std::thread> workers;
std::vector<WorkerClass *> workerObjects;

void signal_handler (int signal_num) {
    std::cout << "Received signal: The interrupt signal is (" << signal_num << "). \n";

    /// Stop any worker threads
    for(int i=0; i<workerObjects.size(); i++) {
        workerObjects.at(i)->stopWorker();
    }
    for (int i=0; i<workers.size(); i++) {
        workers.at(i).join();
    }

    std::cout << "Shared counter value: " << getSharedState() << std::endl;

    // terminate program
    /// \todo We should pass information to workers to simulate that they need to
    ///       to prepare for shutdown - eg. cleaning up local resources.
    exit(signal_num);
}



int getSharedState () {
    return mySharedState.getCounter();
}

/// Try out simple callbackfunction
void threadCallback () {
    std::cout << "In callback function...\n";
}

int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== WORKERS EXAMPLE 01                                                ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    /// Register the signal handler
    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);

    /// Instantiate worker class to prepare for running it in a separate thread
    WorkerClass *worker1 = new WorkerClass("Task 1");
    /// Address of the callback member function, pointer to class instance
    std::thread task1 (&WorkerClass::simpleRun, worker1);

    task1.join();

    /// Create another thread to callback with value parameter
    /// Address of the callback member function, pointer to class instance, parameter value
    /// But this will not result in referenced parameter modified by thread!! See next example.
    std::thread task2(&WorkerClass::simpleRunValueParam, worker1, x);
    task2.join();
    std::cout << "After task2 x=" << x << std::endl;

    /// Create another thread to callback with reference parameter
    /// Have to use std::ref() to pass value by reference. Without it the reference will
    /// be a copy on the thread stack and updates will not be reflected.
    /// https://thispointer.com//c11-multithreading-part-3-carefully-pass-arguments-to-threads/
    std::thread task3(&WorkerClass::simpleRunReferenceParam, worker1, std::ref(x));
    task3.join();
    std::cout << "After task3 x=" << x << std::endl;

    /// This threads will run an event loop defined in the worker class.
    WorkerClass *worker2 = new WorkerClass("worker2");
    WorkerClass *worker3 = new WorkerClass("worker3");
    workers.push_back(std::thread(&WorkerClass::run, worker2, std::ref(mySharedState)));
    workerObjects.push_back(worker2);
    workers.push_back(std::thread(&WorkerClass::run, worker3, std::ref(mySharedState)));
    workerObjects.push_back(worker3);


    /// Enter the endless loop, signal will terminate the program
    while (true) {
        std::cout << "ticktack:::\n";
        mySharedState.countOneMore();

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}