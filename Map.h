//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_MAP_H
#define ADVENTUREGAME_MAP_H

#include <HeadFile.h>

class Map {
public:
    // 初始化地图
    void initializeMap(int level);

    // 显示当前地图
    void displayMap();

    // 更新地图状态
    void updateMap(Player &player);

    // 检查玩家是否到达出口
    bool checkExit();

private:
    char mapGrid[MAP_WIDTH][MAP_HEIGHT];
    std::vector<Monster> monsters;
    Puzzle puzzle;
};

#endif //ADVENTUREGAME_MAP_H
