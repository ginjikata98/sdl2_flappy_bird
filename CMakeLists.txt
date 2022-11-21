cmake_minimum_required(VERSION 3.23)
project(flappy_bird C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

FILE(GLOB SOURCE_FILES src/*.h src/*.c)

add_executable(flappy_bird ${SOURCE_FILES})
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2_MIXER REQUIRED)
find_package(SDL2_TTF REQUIRED)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

include_directories(
        ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(
        ${PROJECT_NAME}
        SDL2::SDL2
        SDL2_image
        SDL2_ttf
        SDL2_mixer
)