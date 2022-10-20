set(SOURCE_FILES_PERCEPTRON perceptron.h perceptron.cpp
                            training.h training.cpp)

ADD_LIBRARY(perceptron STATIC ${SOURCE_FILES_PERCEPTRON})

if(NOT MSVC)
    set_property(TARGET perceptron PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()