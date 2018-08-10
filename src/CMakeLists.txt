cmake_minimum_required(VERSION 3.1)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(LIBS ${LIBS}
    sfml-graphics
    sfml-audio
    )

set(SRC_FILES
    statemanager.cpp
    assetmanager.cpp
    game.cpp
    examplestate.cpp
    animation.cpp
    animatedsprite.cpp
    )

add_library(src ${SRC_FILES})
if(WIN32)
    target_link_libraries(src sfml-main)
endif(WIN32)

target_link_libraries(src ${LIBS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})