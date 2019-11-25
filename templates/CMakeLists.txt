# Get googletest framework
include(FetchContent)

macro(PopulateAndAdd lib)
    string(TOLOWER ${lib} lib_lower)
    FetchContent_GetProperties(${lib})
    if(NOT ${lib_lower}_POPULATED)
        FetchContent_Populate(${lib})
        add_subdirectory(${${lib_lower}_SOURCE_DIR} ${${lib_lower}_BINARY_DIR})
    endif()
    unset(lib_lower)
endmacro()

FetchContent_Declare(
        googletest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         release-1.8.0
)
# FetchContent_MakeAvailable(googletest)
PopulateAndAdd(googletest)

set(gmock_SOURCE_DIR ${googletest_SOURCE_DIR}/googlemock)
set(gtest_SOURCE_DIR ${googletest_SOURCE_DIR}/googletest)
message("gmock_SOURCE_DIR=${gmock_SOURCE_DIR}")
target_include_directories(gmock      INTERFACE "${gtest_SOURCE_DIR}/include")
target_include_directories(gmock_main INTERFACE "${gtest_SOURCE_DIR}/include")

add_executable(template_ex01 template_ex01.cpp Calc.cpp)
add_executable(template_ex02 template_ex02.cpp)

add_executable(testcalc
        TestCalc.cpp Calc.cpp)
target_include_directories(testcalc PRIVATE  ${gmock_SOURCE_DIR}/include ${gtest_SOURCE_DIR}/include)
target_link_libraries(testcalc gmock_main)

add_test(NAME TestCalc COMMAND testcalc)