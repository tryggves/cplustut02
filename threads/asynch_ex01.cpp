//
// Created by trysoe on 10/4/19.
//

//
// This example demonstrates the use of standard library future, async, promise
// functionality for handling synchronisation of threads, passing of state etc.
//


#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <csignal>
#include <cstring>

namespace {
  bool stopped;                   // Shared variable to signal stop to threads


  class Adapter {
  private:


  public:
    Adapter();                            // Constructor
    void run();                           // Main loop
    void addSignalHandlers();             // Terminate process
    static void StopAll(int signal=0);    // Stop and cleanup
    void asyncRunTask(int);               // Some asynchronous worker
  };

  Adapter::Adapter() {
    // Catch signals
    stopped = false;                      // Initialize adapter to be in started mode
    addSignalHandlers();                  // This will result in stop mode
  }

  void Adapter::addSignalHandlers() {
    int quitSignals[]={ SIGINT, SIGTERM, SIGQUIT, 0 };
    struct sigaction sig;

    for(int i=0; quitSignals[i]>0; i++) {
      sigaction(quitSignals[i], NULL, &sig);

      sig.sa_handler=Adapter::StopAll;
      sig.sa_flags=0;

      sigaction(quitSignals[i], &sig, NULL);
    }
  }

  // ================================================================================================
  // Main thread main loop
  // =================================================================================================
  void Adapter::run() {
    std::future<void> asyncStatus;

    int countIterations = 0;

    while (!stopped) {
      std::cout << "Adapter running... Thread id: " << std::this_thread::get_id() << ".\n";
      countIterations++;
      std::this_thread::sleep_for(std::chrono::seconds(2));

      if (countIterations==10) {
        // Run aynchronous thread
        asyncStatus = std::async(std::launch::async, &Adapter::asyncRunTask, this, 100);

        // This call makes the  main thread wait until the asyncRunTask has finished.
        asyncStatus.wait();
        countIterations = 0;    // Reset counter
      }
    }

    std::cout << "Received stop order. Thread: " << std::this_thread::get_id() << ".\n";
  }

  void Adapter::StopAll(int signal) {
    std::cout << "STOP SIGNAL RECEIVED: " << signal << "=" << strsignal(signal) << ". HALTING...\n";

    // Any cleanup should be done here.
    stopped = true;

  }

  //=============================================================================================
  // ASYNC FUNCTION
  //
  // This is the function that will be executed by calling std::async()
  void Adapter::asyncRunTask(int aNumber) {
    std::cout << "Starting asyncRunTask with thread id: " << std::this_thread::get_id() << "...\n";
    std::cout << "asyncRunTask parameter is: " << aNumber << ".\n";

    // Simulate doing work:
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "asyncRunTask completed\n";

    // When it returns the future will be set to valid state
  }


}

int main(int argc, char **argv) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== ASYNC/SYNC EXAMPLE 01                                             ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;

  std::cout << "\nEnter main loop...\n";
  Adapter myAdapter;
  myAdapter.run();

}