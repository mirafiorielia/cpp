cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(group_42)

include_directories(include)

add_library(${PROJECT_NAME}
			src/book.cpp
			src/date.cpp
			src/enums.cpp
            )

add_executable(main src/main.cpp)

target_link_libraries(main ${PROJECT_NAME})
