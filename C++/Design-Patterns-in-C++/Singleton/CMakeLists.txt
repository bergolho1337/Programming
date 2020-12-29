cmake_minimum_required(VERSION 3.0.1)
project(Chocolate)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

FIND_PACKAGE(Threads)

ADD_SUBDIRECTORY(src/chocolate)
ADD_SUBDIRECTORY(src/utils)

ADD_EXECUTABLE(Chocolate src/main.cpp)

ADD_DEPENDENCIES(Chocolate chocolate utils)

TARGET_LINK_LIBRARIES(Chocolate chocolate utils ${CMAKE_THREAD_LIBS_INIT} dl m)
