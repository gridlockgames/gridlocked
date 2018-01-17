cmake_minimum_required(VERSION 3.9)
project(gridlocked)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_HOME_DIRECTORY}/cmake/Modules" ${CMAKE_MODULE_PATH})

# SFML
set(SFML_ROOT "C:/Program Files (x86)/SFML")
set(SFML_USE_STATIC_STD_LIBS TRUE)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

# ImGui

set(IMGUI_SRC
    src/imgui/imgui.cpp
    src/imgui/imgui_draw.cpp
    src/imgui/imgui-SFML.cpp
)
include_directories(include/imgui)
add_library(imgui-sfml STATIC ${IMGUI_SRC})
target_link_libraries(imgui-sfml
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
)

# Sources & includes
include_directories(include)

set(GRIDLOCKED_SRC
    src/main.cpp
)

add_executable(gridlocked ${GRIDLOCKED_SRC})
target_link_libraries(gridlocked
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
    imgui-sfml
)