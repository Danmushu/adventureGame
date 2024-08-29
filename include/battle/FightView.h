//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_FIGHTVIEW_H
#define ADVENTUREGAME_FIGHTVIEW_H
#pragma once

/**
 * @class FightView
 * @brief 负责显示战斗中的各种信息，如战斗状态、回合情况等。
 */
class FightView {
public:
    void showBattleStatus();    ///< 显示战斗的总体状态
    void showPlayerTurn();      ///< 显示玩家回合的信息
    void showMonsterTurn();     ///< 显示怪物回合的信息
    void showBattleResult();    ///< 显示战斗结果
};

#endif //ADVENTUREGAME_FIGHTVIEW_H
