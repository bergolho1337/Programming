set(SOURCE_FILES_DUCK duck.cpp duck.h
                    turkey.cpp turkey.h)

ADD_LIBRARY(duck STATIC ${SOURCE_FILES_DUCK})

if(NOT MSVC)
    set_property(TARGET duck PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()