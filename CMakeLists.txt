cmake_minimum_required(VERSION 3.27)
project(adventureGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(adventureGame
        Player.cpp
        Map.cpp
        Monster.cpp
        Item.cpp
        Puzzle.cpp
        Battle.cpp
        UI.cpp
        SaveLoad.cpp
        main.cpp)
