set(SOURCE_FILES_PIZZA pizza.cpp pizza.h
                    store.cpp store.h
                    ingredient.cpp ingredient.h)

ADD_LIBRARY(pizza STATIC ${SOURCE_FILES_PIZZA})

if(NOT MSVC)
    set_property(TARGET pizza PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()