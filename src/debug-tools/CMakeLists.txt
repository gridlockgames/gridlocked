include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(SFML 2 COMPONENTS window graphics system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(DT_SRC
    logger.cpp
    dt.cpp
)

add_library(debug-tools STATIC ${DT_SRC})
target_link_libraries(debug-tools
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
    imgui-sfml
)
