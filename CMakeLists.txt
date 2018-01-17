cmake_minimum_required(VERSION 3.9)
project(gridlocked)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake/Modules" ${CMAKE_MODULE_PATH})

include_directories(include)

# SFML
set(SFML_ROOT "C:/Program Files (x86)/SFML")
set(SFML_USE_STATIC_STD_LIBS TRUE)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable(gridlocked main.cpp)
target_link_libraries(gridlocked ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})