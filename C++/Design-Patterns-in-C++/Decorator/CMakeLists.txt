cmake_minimum_required(VERSION 3.0.1)
project(Starbuzz)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/starbuzz)
ADD_SUBDIRECTORY(src/utils)

ADD_EXECUTABLE(Starbuzz src/main.cpp)

ADD_DEPENDENCIES(Starbuzz starbuzz utils)

TARGET_LINK_LIBRARIES(Starbuzz starbuzz utils dl m)
