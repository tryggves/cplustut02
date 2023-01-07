
message("ZeroMQ include dir is ${ZeroMQ_INCLUDE_DIR}")
message("ZeroMQ libraries ${ZeroMQ_LIBRARIES}")

add_executable(hwserver hwserver.cpp)
target_include_directories(hwserver PRIVATE ${ZeroMQ_INCLUDE_DIR})
target_link_directories(hwserver PUBLIC ${ZeroMQ_ROOT_DIR}/lib)
target_link_libraries(hwserver zmq)