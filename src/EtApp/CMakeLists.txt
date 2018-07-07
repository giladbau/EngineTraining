cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(EtApp VERSION 0.1.0 LANGUAGES CXX)

if (NOT APPLE)
    include_directories(${GLEW_INCLUDE_DIR})
endif()

include_directories(${SDL2_INCLUDE_DIR})

add_executable(EtApp
    src/EtApp.cpp)

if (NOT APPLE)
    target_link_libraries(EtApp "${GLEW_LIBRARIES}/Release/x64/glew32.lib")
endif()

if (APPLE)
    FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
    target_link_libraries(EtApp ${OpenGL_LIBRARY})
else()
    target_link_libraries(EtApp "opengl32.lib")
endif()

target_link_libraries(EtApp ${SDL2_LIBRARIES})

