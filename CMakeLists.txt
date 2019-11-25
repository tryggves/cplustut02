cmake_minimum_required(VERSION 3.13)
project(cplustut02)

set(CMAKE_CXX_STANDARD 14)

# Get googletest framework
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         release-1.8.1
)
FetchContent_MakeAvailable(googletest)

add_executable(functional_ex functional_ex.cpp)
add_executable(references_ex01 references_ex01.cpp)
add_executable(references_ex02 references_ex02.cpp)
add_executable(initialization_ex initialization_ex.cpp)

add_subdirectory(templates)
add_subdirectory(smartpointers)
add_subdirectory(classes)
add_subdirectory(threads)
add_subdirectory(containers)