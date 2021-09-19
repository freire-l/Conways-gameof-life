cmake_minimum_required(VERSION 3.7)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_definitions(-std=c++17 )

#set(CXX_FLAGS "-Wall" )
project(SDL2Test)

set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS}  -std=c++17 -pthread")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(Game_of_life src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/grid.cpp src/cell.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Game_of_life ${SDL2_LIBRARIES} Threads::Threads)
