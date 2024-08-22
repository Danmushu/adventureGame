//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_UI_H
#define ADVENTUREGAME_UI_H

#include <HeadFile.h>

class UI {
public:
    // 显示玩家的属性状态栏
    void displayPlayerAttributes(const Player &player);

    // 显示左侧的房间地图和出口方向
    void displayRoomMap(const Map &map, const Player &player);

    // 显示游戏日志
    void displayEventLog(const std::vector<std::string> &logs);

    // 显示战斗面板，包括怪物的属性
    void displayBattlePanel(const Player &player, const std::vector<Monster> &monsters);

    // 渲染整个界面
    void renderUI(const Player &player, const Map &map, const std::vector<std::string> &logs, const std::vector<Monster> &monsters);
};



#endif //ADVENTUREGAME_UI_H
