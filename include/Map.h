//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_MAP_H
#define ADVENTUREGAME_MAP_H
#pragma once

#include <vector>
#include <string>
#include <memory>
#include "Space.h"
#include "interface.h"

/**
 * @class Map
 * @brief 代表游戏地图的类，包含地图空间和当前进度等信息。
 */

class Map {
private:
    unordered_map<Space, bool> accessibility;  ///< 2D数组，表示地图中的所有空间
    unordered_map<Space, Space> relation;
    int curProgress;                        ///< 当前地图的进度
    shared_ptr<Space> curSpace;
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

        for(auto &i:relation){
            auto it = accessibility.find(i.first);
            if (it != accessibility.end()) continue;
            else accessibility[i.first] = false;
        }
        curSpace.reset(&entrance);
        curProgress = 0;
    }

    unordered_map<Space, bool> getAcc(){ return accessibility; }
    // 获取指定位置的空间 { return curSpace; }
    //    // 获取当前进度
    shared_ptr<Space> getLocation() { return curSpace; }
    int getProgress() { return curProgress;}
    // 获取默认消息目录
//    std::string getDefaultMsgDir() { return curDefaultMsgDir;}
    // 加载地图数据
    void loadMap() {
        // todo
        // 假设地图数据存储在一个文本文件中

    }

    // 打印地图信息
    static void printMap() {
        // todo
        system("cls");  // 清除控制台内容
        PosControl::setPos(0, 0);  // 将光标设置到控制台的左上角
        std::ifstream mapFile("./Assets/.map");  // 打开存储地图图像的文件
        char map;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置文本颜色为白色
        while (mapFile.get(map)) {  // 逐字符读取并打印地图
            cout << map;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // 恢复文本颜色为默认颜色
        mapFile.close();  // 关闭地图文件

//        // 用灰色标记道路路径
//        PosControl::setPos(0, 0);  // 将光标设置到控制台的左上角
//        std::ifstream pathFile("./Assets/.map_path");  // 打开存储道路路径的文件
//        char path;
//        while (pathFile.get(path)) {  // 逐字符读取并打印路径
//            if (path != ' ') {  // 如果不是空格
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);  // 设置文本颜色为灰色
//                cout << path;
//                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // 恢复文本颜色为默认颜色
//            } else if (path == '\n') {  // 如果是换行符，换行
//                cout << endl;
//            } else {
//                cout << "\033[1C";  // 如果是空格，光标右移一格
//            }
//        }
//        pathFile.close();  // 关闭路径文件
//
//        // 在地图上标记特定位置的名称，并设置文本颜色为黄色
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);  // 设置文本颜色为黄色
//        cout << "\033[34;50H校门";  // 在特定位置显示校门
//        cout << "\033[26;50H迎新大厅";  // 在特定位置显示迎新大厅
//        cout << "\033[18;50H庆功宴会厅";  // 在特定位置显示庆功宴会厅
//        cout << "\033[8;52H圣坛";  // 在特定位置显示圣坛
//        cout << "\033[19;13H战前准备营地";  // 在特定位置显示战前准备营地
//        cout << "\033[18;84H秘密会议室";  // 在特定位置显示秘密会议室
//        cout << "\033[6;84H神秘的魔法墓地";  // 在特定位置显示神秘的魔法墓地
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // 恢复文本颜色为默认颜色
//
//        PosControl::setPos(0, 0);  // 将光标设置到控制台的左上角
    }

    // 设置curSpace指向的位置任务完成
    void setHasDone() { curSpace->setPass(true); }

    // 设置当前地图的进度
    void setProgress(int progress) { curProgress = progress; }

    // 在输出流中显示地图
    void showMap(std::ostream& os) {
        // todo
    }
    void setPosition(Space* space) {
        // 设置当前空间
        curSpace.reset(space);
    }
    void reset() {
        // 重置当前空间
        static Space entrance("秘境入口");
        setPosition(&entrance);

        // 重置当前进度
        curProgress = 0;

        // 重新初始化关系映射
        relation.clear();
        relation[entrance] = Space("秘境1层");
        relation[Space("秘境1层")] = Space("秘境2层");
        relation[Space("秘境2层")] = Space("未知空间");
        relation[Space("秘境2层")] = Space("秘境3层");
        relation[Space("未知空间")] = Space("秘境3层");
        relation[Space("秘境3层")] = Space("秘境4层");
        relation[Space("秘境4层")] = Space("秘境5层");
        relation[Space("秘境4层")] = Space("捷径空间");
        relation[Space("秘境5层")] = Space("秘境核心");
    }
};
};


#endif //ADVENTUREGAME_MAP_H
