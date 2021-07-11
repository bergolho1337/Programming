set(SOURCE_FILES_DBM dbm.h dbm.cpp
                    grid.h grid.cpp
                    cell.h cell.cpp)

ADD_LIBRARY(dbm STATIC ${SOURCE_FILES_DBM})

if(NOT MSVC)
    set_property(TARGET dbm PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()
