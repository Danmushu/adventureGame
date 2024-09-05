cmake_minimum_required(VERSION 3.27)
project(adventureGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
link_libraries(libeasyx.a libgdi32.a libole32.a)

add_executable(adventureGame
        main.cpp
        include/fight.h
)


