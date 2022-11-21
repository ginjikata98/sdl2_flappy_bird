cmake_minimum_required(VERSION 3.23)
project(flappy_bird C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

FILE(GLOB SOURCE_FILES src/*.h src/*.c)

add_executable(flappy_bird ${SOURCE_FILES})
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2_MIXER REQUIRED)
find_package(SDL2_TTF REQUIRED)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

include_directories(
        ${SDL2_INCLUDE_DIRS}
#        ${SDL2_IMAGE_INCLUDE_DIRS}
#        ${SDL2_MIXER_INCLUDE_DIRS}
#        ${SDL2_TTF_INCLUDE_DIRS}
)

message("dirs " ${SDL2_INCLUDE_DIRS})
message("dirs " ${SDL2_MIXER_INCLUDE_DIRS})
message("dirs " ${SDL2_IMAGE_INCLUDE_DIRS})
message("dirs " ${SDL2_TTF_INCLUDE_DIRS})
message("libs " ${SDL2_IMAGE_LIBRARIES})
message("libs " ${SDL2_MIXER_LIBRARIES})
message("libs " ${SDL2_LIBRARIES})
message("libs " ${SDL2_TTF_LIBRARIES})

target_link_libraries(
        ${PROJECT_NAME}
        SDL2::SDL2
        SDL2_image
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)