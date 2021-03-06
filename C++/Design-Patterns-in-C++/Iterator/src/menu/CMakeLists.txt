set(SOURCE_FILES_MENU item.h item.cpp
                      pancake.h pancake.cpp
                      diner.h diner.cpp
                      iterator.h iterator.cpp
                      waitress.h waitress.cpp)

ADD_LIBRARY(menu STATIC ${SOURCE_FILES_MENU})

if(NOT MSVC)
    set_property(TARGET menu PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()