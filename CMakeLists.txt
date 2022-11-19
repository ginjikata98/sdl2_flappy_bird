cmake_minimum_required(VERSION 3.23)
project(flappy_bird C)

set(CMAKE_C_STANDARD 99)

FILE(GLOB SOURCE_FILES src/*.c)

add_executable(flappy_bird ${SOURCE_FILES})
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

include_directories(
        /Library/Frameworks/SDL2.framework/Headers
        /Library/Frameworks/SDL2_image.framework/Headers
)

target_link_libraries(
        ${PROJECT_NAME}
        SDL2::SDL2
        SDL2_image::SDL2_image
)