cmake_minimum_required(VERSION 3.5)

project(BadChess)
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall /std:c++14")
endif(WIN32)

if(LINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedanmtic -std=c++14")
endif(LINUX)

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedanmtic -std=c++14")
endif(APPLE)


set(source_dir "${PROJECT_SOURCE_DIR}/src")
file(GLOB game_files "${source_dir}/game/*.cpp")
file(GLOB utility_files "${source_dir}/utility/*.cpp")
file(GLOB entry "${PROJECT_SOURCE_DIR}/main.cpp")

add_executable(BadChess ${game_files} ${utility_files} ${entry})
