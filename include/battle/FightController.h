//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_FIGHTCONTROLLER_H
#define ADVENTUREGAME_FIGHTCONTROLLER_H
#pragma once
#include "../player/PlayerController.h"
#include "../monster/MonsterController.h"
#include "FightView.h"

/**
 * @class FightController
 * @brief 负责控制战斗的流程，处理玩家和怪物的回合和攻击。
 */
class FightController {
private:
    PlayerController& playerController;         ///< 玩家模型的引用
    MonsterController& monsterController;       ///< 怪物模型的引用
    FightView& battleView;       ///< 战斗视图的引用

public:
    FightController(PlayerController& playerController, MonsterController& monsterController, FightView& view)
            : playerController(playerController), monsterController(monsterController), battleView(view) {}

    void startBattle();          ///< 开始战斗
    void handleTurn();           ///< 处理战斗的回合
    void handlePlayerTurn();     ///< 处理玩家的回合逻辑
    void handleMonsterTurn();    ///< 处理怪物的回合逻辑
    bool isBattleOver();         ///< 判断战斗是否结束
};

#endif //ADVENTUREGAME_FIGHTCONTROLLER_H
