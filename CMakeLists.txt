cmake_minimum_required(VERSION 3.5)

project(BadChess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -std=c++14")
set(source_dir "${PROJECT_SOURCE_DIR}/src")
file(GLOB game_files "${source_dir}/game/*.cpp")
file(GLOB utility_files "${source_dir}/utility/*.cpp")
file(GLOB entry "${PROJECT_SOURCE_DIR}/main.cpp")

add_executable(BadChess ${game_files} ${utility_files} ${entry})