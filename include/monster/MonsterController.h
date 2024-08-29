//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_MONSTERCONTROLLER_H
#define ADVENTUREGAME_MONSTERCONTROLLER_H
#pragma once
#include "Monster.h"
#include "MonsterView.h"

/**
 * @class MonsterController
 * @brief 负责处理怪物的逻辑和行为，与MonsterView和Monster模型交互。
 */
class MonsterController {
private:
    Monster model;              ///< 怪物模型，存储怪物的状态和行为
    MonsterView view;           ///< 怪物视图，负责显示相关信息

public:
    void handleUseItem();       ///< 处理怪物使用物品
    void handleDropItem();      ///< 处理怪物丢弃物品
    void handleUseSkill();      ///< 处理怪物使用技能
    void handleAttack();        ///< 处理怪物的攻击行为
};

#endif //ADVENTUREGAME_MONSTERCONTROLLER_H
