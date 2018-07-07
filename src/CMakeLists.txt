cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(EngineTraining VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)

find_package(glm REQUIRED)

find_package(SDL2 REQUIRED)
set(SDL2_INCLUDE_DIR "${SDL2_DIR}/../include")
set(SDL2_LIBRARIES "${SDL2_DIR}/../lib/SDL2.lib;${SDL2_DIR}/../lib/SDL2main.lib")

find_package(GLEW REQUIRED)

add_subdirectory(EtApp)
add_subdirectory(EtRenderer)

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
