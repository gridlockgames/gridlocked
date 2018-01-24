find_package(SFML 2 COMPONENTS window graphics system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

set(GAME_SRC
    main.cpp
)

add_executable(game ${GAME_SRC})
target_link_libraries(game
    ${SFML_LIBRARIES}
    ${SFML_DEPENDENCIES}
    imgui-sfml
)
