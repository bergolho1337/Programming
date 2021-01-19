cmake_minimum_required(VERSION 3.0.1)
project(Command)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/devices)
ADD_SUBDIRECTORY(src/utils)

ADD_EXECUTABLE(Command src/main.cpp)

ADD_DEPENDENCIES(Command devices utils)

TARGET_LINK_LIBRARIES(Command devices utils dl m)
