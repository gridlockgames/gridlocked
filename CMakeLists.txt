cmake_minimum_required(VERSION 3.9)
project(gridlocked)

# CMake options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake/Modules" ${CMAKE_MODULE_PATH})

# Sources & includes
include_directories(./include)

# SFML
if (WINDOWS)
    set(SFML_ROOT "C:/Program Files (x86)/SFML")
    set(SFML_USE_STATIC_STD_LIBS TRUE)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

add_subdirectory(src)
