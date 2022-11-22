cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(mid_project VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_executable(mid_project
    main.cpp 
    book.cpp
    date.cpp
    enums.cpp
)
