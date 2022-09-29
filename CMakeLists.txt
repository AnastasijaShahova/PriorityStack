cmake_minimum_required(VERSION 3.5)

project(priorityStack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(priorityStack main.cpp PriorityStack.h)

install(TARGETS priorityStack
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
