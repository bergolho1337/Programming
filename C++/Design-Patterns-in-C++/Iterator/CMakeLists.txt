cmake_minimum_required(VERSION 3.0.1)
project(Restaurant)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/menu)

ADD_EXECUTABLE(Restaurant src/main.cpp)

ADD_DEPENDENCIES(Restaurant menu)

TARGET_LINK_LIBRARIES(Restaurant menu dl m)
