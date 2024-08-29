//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_MONSTERVIEW_H
#define ADVENTUREGAME_MONSTERVIEW_H
#pragma once

/**
 * @class MonsterView
 * @brief 负责显示怪物的状态、物品、技能等信息。
 */
class MonsterView {
public:
    void showMonsterStatus();   ///< 显示怪物的状态
    void showInventory();       ///< 显示怪物的物品清单
    void showSkill();           ///< 显示怪物的技能列表
    void showAttackResult();    ///< 显示攻击的结果
    void showDeath();           ///< 显示怪物死亡画面
};

#endif //ADVENTUREGAME_MONSTERVIEW_H
