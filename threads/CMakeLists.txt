add_executable(thread_ex01 thread_ex01.cpp)
target_link_libraries(thread_ex01 pthread)

add_executable(asynch_ex01 asynch_ex01.cpp)
target_link_libraries(asynch_ex01 pthread)

add_executable(asynch_ex02 asynch_ex02.cpp)
target_link_libraries(asynch_ex02 pthread)