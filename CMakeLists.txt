cmake_minimum_required(VERSION 3.1)

project(sfml-base)

add_subdirectory(src)

if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /subsystem:windows") 
endif(WIN32)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} src)

install(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION build)