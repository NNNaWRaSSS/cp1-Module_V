cmake_minimum_required(VERSION 3.14)

project(Bank LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_subdirectory(test)

add_executable(bank src/main.c src/bank.c)