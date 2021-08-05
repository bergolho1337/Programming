set(SOURCE_FILES_PERCEPTRON multilayer.cpp multilayer.h)

ADD_LIBRARY(multilayer STATIC ${SOURCE_FILES_PERCEPTRON})

if(NOT MSVC)
    set_property(TARGET multilayer PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()