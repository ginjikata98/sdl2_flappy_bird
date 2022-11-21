cmake_minimum_required(VERSION 3.23)
project(flappy_bird C)

set(CMAKE_C_STANDARD 99)

FILE(GLOB SOURCE_FILES src/*.h src/*.c)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2_MIXER REQUIRED)
find_package(SDL2_TTF REQUIRED)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

include_directories(
        /Library/Frameworks/SDL2.framework/Headers
        /Library/Frameworks/SDL2_image.framework/Headers
        /Library/Frameworks/SDL2_ttf.framework/Headers
        /Library/Frameworks/SDL2_mixer.framework/Headers
)

target_link_libraries(
        ${PROJECT_NAME}
        /Library/Frameworks/SDL2.framework/Versions/A/SDL2
        /Library/Frameworks/SDL2_image.framework/Versions/A/SDL2_image
        /Library/Frameworks/SDL2_ttf.framework/Versions/A/SDL2_ttf
        /Library/Frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer
)