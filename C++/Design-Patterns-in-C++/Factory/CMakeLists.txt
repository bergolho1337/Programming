cmake_minimum_required(VERSION 3.0.1)
project(PizzaStore)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/pizza)
ADD_SUBDIRECTORY(src/utils)

ADD_EXECUTABLE(PizzaStore src/main.cpp)

ADD_DEPENDENCIES(PizzaStore pizza utils)

TARGET_LINK_LIBRARIES(PizzaStore pizza utils dl m)
