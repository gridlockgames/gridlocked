include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(SFML 2 COMPONENTS window graphics system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(GAME_SRC
    main.cpp
)

set(GAME_LIBS
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
    imgui-sfml
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    list(APPEND GAME_LIBS debug-tools)
endif()

add_executable(game ${GAME_SRC})

target_link_libraries(game ${GAME_LIBS})
