cmake_minimum_required(VERSION 3.23)
project(flappy_bird C)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCE_FILES src/*.h src/*.c)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

set(SDL2_HEADER "/Library/Frameworks/SDL2.framework/Headers")
set(SDL2_IMAGE_HEADER "/Library/Frameworks/SDL2_image.framework/Headers")
set(SDL2_TTF_HEADER "/Library/Frameworks/SDL2_ttf.framework/Headers")
set(SDL2_MIXER_HEADER "/Library/Frameworks/SDL2_mixer.framework/Headers")

set(SDL2_BINARY "/Library/Frameworks/SDL2.framework/Versions/A/SDL2")
set(SDL2_IMAGE_BINARY "/Library/Frameworks/SDL2_image.framework/Versions/A/SDL2_image")
set(SDL2_TTF_BINARY "/Library/Frameworks/SDL2_ttf.framework/Versions/A/SDL2_ttf")
set(SDL2_MIXER_BINARY "/Library/Frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

include_directories(
        ${SDL2_HEADER}
        ${SDL2_IMAGE_HEADER}
        ${SDL2_TTF_HEADER}
        ${SDL2_MIXER_HEADER}
)

target_link_libraries(
        ${PROJECT_NAME}
        ${SDL2_BINARY}
        ${SDL2_IMAGE_BINARY}
        ${SDL2_TTF_BINARY}
        ${SDL2_MIXER_BINARY}
        m
)