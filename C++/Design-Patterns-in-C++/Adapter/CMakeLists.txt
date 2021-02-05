cmake_minimum_required(VERSION 3.0.1)
project(DucksAdapter)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/ducks)
ADD_SUBDIRECTORY(src/utils)

ADD_EXECUTABLE(DucksAdapter src/main.cpp)

ADD_DEPENDENCIES(DucksAdapter duck utils)

TARGET_LINK_LIBRARIES(DucksAdapter duck utils dl m)
