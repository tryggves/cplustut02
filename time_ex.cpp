
//
// Created by trysoe on 11/23/22.
//
//
// Stdc++ handling of dates, time, epoch etc.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include <string>

class MyLocalTime {
private:
  std::chrono::system_clock::time_point m_timePoint;
public:
  // Default constructor initialized time to now
  MyLocalTime() {
    m_timePoint = std::chrono::system_clock::now();
  }

  std::string calendarTimeAsStr() const {
    const std::time_t myTime = std::chrono::system_clock::to_time_t(m_timePoint);
    std::string myTimeStr = std::ctime(&myTime);    // Convert to calendar time
    myTimeStr.resize(myTimeStr.size()-1);       // Skip trailing newline

    return myTimeStr;
  }

  long epochTime() const {
    const std::time_t myTime = std::chrono::system_clock::to_time_t(m_timePoint);
    return myTime;
  }
};

int main(int argc, char **argv) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== DATE AND TIME EX                                                  ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  for (auto i=0; i<argc; i++) {
    std::cout << "=== Argument " << i << ": " << argv[i] << std::endl;
  }
  std::cout << "==========================================================================" << std::endl;

  // Replace with class implementation
  //  std::chrono::system_clock::time_point timePoint;
  //  timePoint = std::chrono::system_clock::now();
  //  const std::time_t myTime = std::chrono::system_clock::to_time_t(timePoint);
  //  std::string myTimeStr = std::ctime(&myTime);    // Convert to calendar time
  //  myTimeStr.resize(myTimeStr.size()-1);       // Skip trailing newline
  //  std::cout << "Calendar time: " << myTimeStr << std::endl;

  MyLocalTime localTime;
  std::cout << "Calendar time: " << localTime.calendarTimeAsStr() << std::endl;
  std::cout << "Epoch time: " << localTime.epochTime() << std::endl;
  return 0;
}