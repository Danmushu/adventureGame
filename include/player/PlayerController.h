//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_PLAYERCONTROLLER_H
#define ADVENTUREGAME_PLAYERCONTROLLER_H
#pragma once
#include "Player.h"
#include "PlayerView.h"

/**
 * @class PlayerController
 * @brief 负责处理玩家的输入和游戏逻辑，与PlayerView和Player模型交互。
 */
class PlayerController {
private:
    Player model;               ///< 玩家模型，存储玩家的状态和行为
    PlayerView view;            ///< 玩家视图，负责显示相关信息

public:
    void openMap();             ///< 打开地图
    void handleUseItem();       ///< 处理玩家使用物品
    void handleDropItem();      ///< 处理玩家丢弃物品
    void handleUseSkill();      ///< 处理玩家使用技能
    void handleAttack();        ///< 处理玩家的攻击行为
};

#endif //ADVENTUREGAME_PLAYERCONTROLLER_H
