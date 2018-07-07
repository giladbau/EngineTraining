cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(EngineTraining VERSION 0.1.0 LANGUAGES CXX)

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

include(GNUInstallDirs)

find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)

if (NOT APPLE)
    find_package(GLEW REQUIRED)
endif()

add_subdirectory(EtApp)
add_subdirectory(EtRenderer)
