cmake_minimum_required(VERSION 2.8.12)

PROJECT(MultilayerPerceptron)

SET(CMAKE_BUILD_TYPE "Debug")
SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin" )

ADD_SUBDIRECTORY(src/multilayer)
ADD_SUBDIRECTORY(src/matrix)
ADD_SUBDIRECTORY(src/utils)

ADD_EXECUTABLE(MultilayerPerceptron MACOSX_BUNDLE src/main.cpp)

ADD_DEPENDENCIES(MultilayerPerceptron multilayer matrix utils)

TARGET_LINK_LIBRARIES(MultilayerPerceptron multilayer matrix utils dl m)
