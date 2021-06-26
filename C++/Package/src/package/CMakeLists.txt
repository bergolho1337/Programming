set(SOURCE_FILES_PACKAGE package.h package.cpp
                         linked-list.h linked-list.cpp)

ADD_LIBRARY(package STATIC ${SOURCE_FILES_PACKAGE})

if(NOT MSVC)
    set_property(TARGET package PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()