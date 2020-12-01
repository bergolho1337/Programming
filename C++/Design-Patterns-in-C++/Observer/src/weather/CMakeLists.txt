set(SOURCE_FILES_DUCK weather.cpp weather.h
                    observer.cpp observer.h)

ADD_LIBRARY(weather STATIC ${SOURCE_FILES_DUCK})

if(NOT MSVC)
    set_property(TARGET weather PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()