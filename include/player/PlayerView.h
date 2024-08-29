//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_PLAYERVIEW_H
#define ADVENTUREGAME_PLAYERVIEW_H
#pragma once

/**
 * @class PlayerView
 * @brief 负责显示玩家的状态、地图、物品、技能等信息。
 */
class PlayerView {
public:
    void showPlayStatus();      ///< 显示玩家的状态
    void showMap();             ///< 显示地图
    void showInventory();       ///< 显示玩家的物品清单
    void showSkill();           ///< 显示玩家的技能列表
    void showAttackResult();    ///< 显示攻击的结果
    void showDeath();           ///< 显示玩家死亡画面
};

#endif //ADVENTUREGAME_PLAYERVIEW_H
