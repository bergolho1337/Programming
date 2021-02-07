set(SOURCE_FILES_THEATER home_theater.h home_theater.cpp)

ADD_SUBDIRECTORY(players)
ADD_SUBDIRECTORY(lights)
ADD_SUBDIRECTORY(popcorn)
ADD_SUBDIRECTORY(screen)

ADD_LIBRARY(home_theater STATIC ${SOURCE_FILES_THEATER})

if(NOT MSVC)
    set_property(TARGET home_theater PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()