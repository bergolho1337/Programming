cmake_minimum_required(VERSION 3.0.1)
project(CaffeineBeverage)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/beverages)

ADD_EXECUTABLE(CaffeineBeverage src/main.cpp)

ADD_DEPENDENCIES(CaffeineBeverage beverages)

TARGET_LINK_LIBRARIES(CaffeineBeverage beverages dl m)
