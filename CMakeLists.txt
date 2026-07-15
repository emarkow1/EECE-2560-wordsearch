cmake_minimum_required(VERSION 3.10.0)
project(wordsearch VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(wordsearch 
    src/dictionary.cpp
    src/grid.cpp
    )

target_include_directories(wordsearch PRIVATE src)