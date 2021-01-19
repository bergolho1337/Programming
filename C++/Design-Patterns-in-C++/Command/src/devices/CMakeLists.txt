set(SOURCE_FILES_DEVICES  light/light.cpp light/light.h
                        ceiling_fan/ceiling_fan.cpp ceiling_fan/ceiling_fan.h
                        garage_door/garage_door.cpp garage_door/garage_door.h
                        stereo/stereo.cpp stereo/stereo.h
                        remote/remote.cpp remote/remote.h
                        command.cpp command.h)

ADD_LIBRARY(devices STATIC ${SOURCE_FILES_DEVICES})

if(NOT MSVC)
    set_property(TARGET devices PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()