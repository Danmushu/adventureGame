//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_MAP_H
#define ADVENTUREGAME_MAP_H
#pragma once

#include <vector>
#include <string>
#include "Space.h"

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
//    std::vector<std::vector<Space>> space;  ///< 2D数组，表示地图中的所有空间
    unordered_map<Space, Space> relation;
    int curProgress;                        ///< 当前地图的进度
//    std::string curDefaultMsgDir;           ///< 当前默认消息的目录

public:
    // todo
    // 构造函数
    Map() {
       // todo
        // 初始化空间
        Space entrance("秘境入口");
        Space mystery1("秘境1层");
        Space mystery2("秘境2层");
        Space unknown("未知空间");
        Space mystery3("秘境3层");
        Space mystery4("秘境4层");
        Space interLayer("捷径空间");
        Space mystery5("秘境5层");
        Space core("秘境核心");

// 设定各个空间的关系（定义路径关系）
        relation[entrance] = mystery1;   // entrance -> mystery1  (秘境入口 -> 遗迹1层)
        relation[mystery1] = mystery2;   // mystery1 -> mystery2  (遗迹1层 -> 遗迹2层)
        relation[mystery2] = unknown;    // mystery2 -> unknown   (遗迹2层 -> 未知空间)
        relation[mystery2] = mystery3;   // mystery2 -> mystery3 (2->3)
        relation[unknown] = mystery3;    // unknown  -> mystery3  (未知空间 -> 遗迹3层)
        relation[mystery3] = mystery4;   // mystery3 -> mystery4  (遗迹3层 -> 遗迹4层)
        relation[mystery4] = mystery5;   // mystery4 -> mystery5  (遗迹4层 -> 遗迹5层)
        relation[mystery4] = interLayer; // mystery4 -> interLayer (遗迹4层 -> 中间层)
        relation[mystery5] = core;       // mystery5 -> core      (遗迹5层 -> 秘境核心)


    }

    // 获取指定位置的空间
    Space* getLocation(int x, int y) {

    }
    // 获取当前进度
    int getProgress() { return curProgress;}
    // 获取默认消息目录
//    std::string getDefaultMsgDir() { return curDefaultMsgDir;}
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
