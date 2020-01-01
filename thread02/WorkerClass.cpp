//
// Created by Tryggve Sørensen on 23/12/2019.
//

#include <thread>
#include "WorkerClass.h"

/**
 *
 * @param name
 */
WorkerClass::WorkerClass (std::string name) : m_name{name},
                                            m_localState {0},
                                            m_stopRequest{false} {

}

void WorkerClass::run(SharedState & state) {
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;


    while (true) {
        std::cout << "Thread: " << std::this_thread::get_id() << " ticktack...\n";

        /// \todo Shared state access to be synchronized.
        state.countOneMore();

        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (m_stopRequest) {
            std::cout << "Thread: " << std::this_thread::get_id() << " Stop thread was requested. Exiting...\n";

            /// EXIT THE EVENT LOOP
            break;
        }
    }
}

void WorkerClass::simpleRun() {
    std::cout << "In WorkerClass::simpleRun() \n";
}

void WorkerClass::simpleRunValueParam(int x) {
    for (int i=0; i<10; i++) {
        std::cout << "In WorkerClass::simpleRunValueParam() x=" << x << std::endl;
        x++;
    }
}

/// Can also be coded as:
/// void WorkerClass::simpleRunReferenceParam(int const & x) {
void WorkerClass::simpleRunReferenceParam(const int & x) {
    int& y = const_cast<int &>(x);

    for (int i=0; i<10; i++) {
        std::cout << "In WorkerClass::simpleRunReferenceParam() y=" << y << std::endl;
        y++;
    }
}

void WorkerClass::stopWorker() {
    m_stopRequest = true;
}

