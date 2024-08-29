//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_MAP_H
#define ADVENTUREGAME_MAP_H
#pragma once

#include <vector>
#include <string>
#include "space.h"

/**
 * @class Map
 * @brief 代表游戏地图的类，包含地图空间和当前进度等信息。
 */
class Map {
private:
    std::vector<std::vector<Space>> space;  ///< 2D数组，表示地图中的所有空间
    int curProgress;                        ///< 当前地图的进度
    std::string curDefaultMsgDir;           ///< 当前默认消息的目录

public:
    Map();

    Space* getLocation(int x, int y);          ///< 获取指定位置的空间
    int getProgress();                            ///< 获取当前进度
    std::string getDefaultMsgDir();               ///< 获取默认消息目录
    void loadMap();                               ///< 加载地图数据
    void printMap();                              ///< 打印地图信息
    void setHasDone(int x, int y);                ///< 设置某个位置任务完成
    void setProgress(int progress);               ///< 设置当前地图的进度
    void showMap(std::ostream& os);               ///< 在输出流中显示地图
};


#endif //ADVENTUREGAME_MAP_H
