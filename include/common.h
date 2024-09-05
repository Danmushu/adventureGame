//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_COMMON_H
#define ADVENTUREGAME_COMMON_H

/*** 定义宏 ***/
//地图的大小
#define MAP_WIDTH 300
#define MAP_HEIGHT 500

/*** 字体设置 ***/

/*** 系统头文件 ***/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <synchapi.h>
#include <fstream>
#include <ctime>
#include <Windows.h>  // 包含 Windows API 函数
#include <conio.h> // 提供控制台输入输出的非标准函数（如 getch）
#include <random>  // 提供随机数生成
using namespace std;


/*** 游戏头文件 ***/
#include "interface.h"
#include "Item.h"
#include "Space.h"
#include "Map.h"
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include "Battle.h"
#include "GameController.h"



/*** 游戏初始数据 ***/
/* Monster */
const unordered_set<Monster>
/* Skill */

/* Weapon */

/* Medicine */

/* Special */

#endif //ADVENTUREGAME_COMMON_H
