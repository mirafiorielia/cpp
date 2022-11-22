cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(group_42 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(group_42
    main.cpp 
    book.cpp
    date.cpp
    enums.cpp
)
