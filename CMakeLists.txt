cmake_minimum_required(VERSION 3.20)
project(learn_cpp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -pthread")

include_directories(include)

# Core Library
add_library(learn_cpp_lib
    src/roadmap.cpp
    src/thread_pool.cpp
)

# Main Executable
add_executable(learn_cpp
    src/main.cpp
)
target_link_libraries(learn_cpp PRIVATE learn_cpp_lib)

# Tests Executable
enable_testing()
add_executable(test_runner
    tests/test_main.cpp
)
target_link_libraries(test_runner PRIVATE learn_cpp_lib)
add_test(NAME test_runner COMMAND test_runner)
