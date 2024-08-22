//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_COMMON_H
#define ADVENTUREGAME_COMMON_H

/*** 定义宏 ***/
//地图的大小
#define MAP_WIDTH 300
#define MAP_HEIGHT 500

/*** 系统头文件 ***/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*** 游戏头文件 ***/
#include <Player.h> //玩家
#include <Item.h> //物品
#include <Monster.h> //怪物
#include <Puzzle.h> //解迷
#include <Battle.h> //战斗

#include <Map.h> //地图
#include <SaveLoad.h> //数据存储

#endif //ADVENTUREGAME_COMMON_H
