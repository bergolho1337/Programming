set(SOURCE_FILES_PLAYERS amplifier.h amplifier.cpp
                        cd_player.h cd_player.cpp
                        dvd_player.h dvd_player.cpp)

ADD_LIBRARY(players STATIC ${SOURCE_FILES_PLAYERS})

if(NOT MSVC)
    set_property(TARGET players PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()