cmake_minimum_required(VERSION 3.23)
project(currencier)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/curlpp-0.8.1)

add_executable(currencier main.cpp)

target_link_libraries(currencier curlpp)

target_include_directories(currencier PUBLIC libs/curlpp-0.8.1/include)
