cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(EtRenderer VERSION 0.1.0 LANGUAGES CXX)

add_library(EtRenderer
    src/EtRenderer.cpp)

target_include_directories(EtRenderer PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

target_compile_features(EtRenderer
    PUBLIC cxx_auto_type
    PRIVATE cxx_variadic_templates)

target_link_libraries(EtRenderer
    glm)

# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS EtRenderer EXPORT EtRendererConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT EtRendererConfig DESTINATION share/MyLibrary/cmake)

export(TARGETS EtRenderer FILE EtRendererConfig.cmake)
