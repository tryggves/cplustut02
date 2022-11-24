
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
  std::time_t m_timestampEpoch;
public:
  // Default constructor initialized time to now
  MyLocalTime() {
    std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
    m_timestampEpoch = std::chrono::system_clock::to_time_t(timePoint);
  }

  // Constructor with timestamp in seconds since epoch
  MyLocalTime(long secsSinceEpoch) {
    m_timestampEpoch = secsSinceEpoch;
  }

  std::string calendarTimeAsStr() const {
    std::string myTimeStr = std::ctime(&m_timestampEpoch);    // Convert to calendar time
    myTimeStr.resize(myTimeStr.size()-1);       // Skip trailing newline

    return myTimeStr;
  }

  long epochTime() const {
    return m_timestampEpoch;
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

  std::cout << "Initialize time to now..." << std::endl;
  MyLocalTime localTime;
  std::cout << "Calendar time: " << localTime.calendarTimeAsStr() << std::endl;
  std::cout << "Epoch time: " << localTime.epochTime() << std::endl;

  std::cout << "\nInitialize time to Thursday, November 24, 2022 2:00:00 AM GMT+01:00..." << std::endl;
  MyLocalTime novFirstTime(1669251600);
  std::cout << "Calendar local time: " << novFirstTime.calendarTimeAsStr() << std::endl;
  std::cout << "Epoch time: " << novFirstTime.epochTime() << std::endl;
  return 0;
}