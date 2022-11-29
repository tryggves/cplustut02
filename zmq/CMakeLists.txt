
message("ZeroMQ include dir is ${ZeroMQ_INCLUDE_DIR}")

add_executable(hwserver hwserver.cpp)
target_include_directories(hwserver PRIVATE ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(hwserver zmq)