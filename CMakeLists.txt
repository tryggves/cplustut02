cmake_minimum_required(VERSION 3.16...3.19)
project(cplustut02)

set(CMAKE_CXX_STANDARD 14)
# CMake find_package script directory where these are not provided off-the-shelf
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# include(FetchContent)
# FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY  https://github.com/google/googletest.git
#        GIT_TAG         release-1.10.0
# )
# FetchContent_MakeAvailable(googletest)

# find_package(ZeroMQ  REQUIRED)
find_package(cppzmq  REQUIRED)

add_executable(functional_ex functional_ex.cpp)
add_executable(references_ex01 references_ex01.cpp)
add_executable(references_ex02 references_ex02.cpp)
add_executable(initialization_ex initialization_ex.cpp)
add_executable(variable_declarations_ex01 variable_declarations_ex01.cpp)
# add_executable(cplus11features cplus11features.cpp time_ex.cpp)
add_executable(time_ex time_ex.cpp)
add_executable(lambda_ex01 lambda_ex01.cpp)

add_subdirectory(templates)
add_subdirectory(smartpointers)
add_subdirectory(classes)
add_subdirectory(threads)
add_subdirectory(containers)
add_subdirectory(thread02)
add_subdirectory(functional)
add_subdirectory(header-msg)
add_subdirectory(zmq)
