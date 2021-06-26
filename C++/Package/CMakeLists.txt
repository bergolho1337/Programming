cmake_minimum_required(VERSION 2.8)

PROJECT(Package)

SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin" )

ADD_SUBDIRECTORY(src/package)

ADD_EXECUTABLE(Package MACOSX_BUNDLE src/main.cpp)

ADD_DEPENDENCIES(Package package)

TARGET_LINK_LIBRARIES(Package package dl m)
