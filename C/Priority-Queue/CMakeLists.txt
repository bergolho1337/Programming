cmake_minimum_required(VERSION 3.0.1)
project(PriorityQueue)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/queue)

ADD_EXECUTABLE(PriorityQueue src/main.c)

ADD_DEPENDENCIES(PriorityQueue pqueue)

TARGET_LINK_LIBRARIES(PriorityQueue pqueue dl m)
