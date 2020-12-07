set(SOURCE_FILES_STARBUZZ beverage.cpp beverage.h
                        condiment.cpp condiment.h)

ADD_LIBRARY(starbuzz STATIC ${SOURCE_FILES_STARBUZZ})

if(NOT MSVC)
    set_property(TARGET starbuzz PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()