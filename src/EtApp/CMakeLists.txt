cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(EtApp VERSION 0.1.0 LANGUAGES CXX)

include_directories(${GLEW_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIR})

add_executable(EtApp
    src/EtApp.cpp)

target_link_libraries(EtApp "${GLEW_LIBRARIES}/Release/x64/glew32.lib")
target_link_libraries(EtApp "opengl32.lib")
target_link_libraries(EtApp ${SDL2_LIBRARIES})

