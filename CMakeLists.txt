cmake_minimum_required(VERSION 3.27)
project(adventureGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
link_libraries(libeasyx.a libgdi32.a libole32.a)

add_executable(adventureGame
        main.cpp
        include/creature/Creature.h
        include/player/Player.h
        include/monster/Monster.h
        include/item/Item.h
        include/item/Skill.h
        include/item/Weapon.h
        include/map/map.h
        include/map/Space.h
        include/player/PlayerView.h
        include/player/PlayerController.h
        include/monster/MonsterView.h
        include/monster/MonsterController.h
        include/battle/FightView.h
        include/battle/FightController.h
        include/GameController.h
        include/tool/data.h
)


