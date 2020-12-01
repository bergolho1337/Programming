cmake_minimum_required(VERSION 3.0.1)
project(WeatherApp)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/shared-libs)

ADD_SUBDIRECTORY(src/weather)
ADD_SUBDIRECTORY(src/utils)

ADD_EXECUTABLE(WeatherApp src/main.cpp)

ADD_DEPENDENCIES(WeatherApp weather utils)

TARGET_LINK_LIBRARIES(WeatherApp weather utils dl m)
