cmake_minimum_required(VERSION 3.0.1)
project(HomeTheater)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/home_theater)

ADD_EXECUTABLE(HomeTheater src/main.cpp)

ADD_DEPENDENCIES(HomeTheater home_theater players light popcorn screen)

TARGET_LINK_LIBRARIES(HomeTheater home_theater players light popcorn screen dl m)
