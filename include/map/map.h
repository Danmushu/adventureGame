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
    // 构造函数
    Map() : curProgress(0), curDefaultMsgDir("") {
        // todo
        // 构造函数，可以在这里初始化地图空间
        // 例如，初始化一个5x5的地图
//        for (int i = 0; i < 5; ++i) {
//            std::vector<Space> row;
//            for (int j = 0; j < 5; ++j) {
//                row.push_back(Space());
//            }
//            space.push_back(row);
//        }
    }

    // 获取指定位置的空间
    Space* getLocation(int x, int y) {
        if (x < 0 || y < 0 || x >= space.size() || y >= space[0].size()) {
            return nullptr; // 越界检查
        }
        return &space[x][y];
    }
    // 获取当前进度
    int getProgress() { return curProgress;}
    // 获取默认消息目录
    std::string getDefaultMsgDir() { return curDefaultMsgDir;}
    // 加载地图数据
    void loadMap() {
        // todo
        // 假设地图数据存储在一个文本文件中

    }

    // 打印地图信息
    void printMap() {
        // todo
    }

    // 设置某个位置任务完成
    void setHasDone(int x, int y) {
        // todo
    }

    // 设置当前地图的进度
    void setProgress(int progress) { curProgress = progress; }

    // 在输出流中显示地图
    void showMap(std::ostream& os) {
        // todo
    }
};


#endif //ADVENTUREGAME_MAP_H
