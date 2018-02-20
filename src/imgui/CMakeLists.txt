include_directories(${PROJECT_SOURCE_DIR}/include/imgui)

find_package(SFML 2 COMPONENTS graphics window REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(IMGUI_SRC
    imgui.cpp
    imgui_draw.cpp
    imgui-SFML.cpp
)

add_library(imgui-sfml STATIC ${IMGUI_SRC})

target_link_libraries(imgui-sfml
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
)

if (UNIX)
    target_link_libraries(imgui-sfml GL)
endif()

