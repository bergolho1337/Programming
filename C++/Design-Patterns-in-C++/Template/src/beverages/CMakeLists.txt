set(SOURCE_FILES_THEATER beverage.h beverage.cpp
                        coffe/coffe.h coffe/coffe.cpp
                        tea/tea.h tea/tea.cpp)

ADD_LIBRARY(beverages STATIC ${SOURCE_FILES_THEATER})

if(NOT MSVC)
    set_property(TARGET beverages PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()