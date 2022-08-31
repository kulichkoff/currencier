cmake_minimum_required(VERSION 3.23)
project(currencier)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/curlpp-0.8.1)
add_subdirectory(libs/json-3.11.2)

add_executable(currencier main.cpp
        src/http_client.cc src/http_client.h
        src/currency_parser.cc src/currency_parser.h
        )

target_link_libraries(currencier PUBLIC curlpp_static nlohmann_json)

target_include_directories(currencier PUBLIC
        libs/curlpp-0.8.1/include
        libs/json-3.11.2/include
        )
