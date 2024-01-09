cmake_minimum_required(VERSION 3.10)
project(HacknSlash)

add_executable(HacknSlash main.cpp)



target_sources(HacknSlash PRIVATE ${PROJECT_SOURCE_DIR}/src/Game.cpp)
target_sources(HacknSlash PRIVATE ${PROJECT_SOURCE_DIR}/src/Input.cpp)
target_sources(HacknSlash PRIVATE ${PROJECT_SOURCE_DIR}/src/TextureManager.cpp)
target_sources(HacknSlash PRIVATE ${PROJECT_SOURCE_DIR}/src/GameObject.cpp)
target_sources(HacknSlash PRIVATE ${PROJECT_SOURCE_DIR}/src/Map.cpp)
target_sources(HacknSlash PRIVATE ${PROJECT_SOURCE_DIR}/src/Vector2D.cpp)
target_sources(HacknSlash PRIVATE ${PROJECT_SOURCE_DIR}/src/Collision.cpp)
target_sources(HacknSlash PRIVATE ${PROJECT_SOURCE_DIR}/inc/ECS/ECS.cpp)

#include sdl2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(HacknSlash ${SDL2_LIBRARIES})
target_link_libraries(HacknSlash ${SDL2_IMAGE_LIBRARIES})

# SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++-14")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
