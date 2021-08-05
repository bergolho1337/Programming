cmake_minimum_required(VERSION 2.8.12)

PROJECT(Matrix)

SET(CMAKE_BUILD_TYPE "Debug")
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin" )

ADD_SUBDIRECTORY(src/matrix)
ADD_SUBDIRECTORY(src/utils)

ADD_EXECUTABLE(Matrix src/main.cpp)

ADD_DEPENDENCIES(Matrix matrix utils)

TARGET_LINK_LIBRARIES(Matrix matrix utils dl m)
