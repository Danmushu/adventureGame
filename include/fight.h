//
// Created by Danmu on 2024/9/1.
//

#ifndef ADVENTUREGAME_FIGHT_H
#define ADVENTUREGAME_FIGHT_H

#include <iostream>
#include "Player.h"
#include "Monster.h"

// 战斗系统类
class Battle {
private:
    Player player;
    Monster monster;
    bool isGameOver;

public:
    Battle() : isGameOver(false) {}

    void startBattle() {
        std::cout << "Battle starts!" << std::endl;
        // 初始化战斗，例如设置生命值等
    }

    void handleTurn() {
        // todo
        if (isBattleOver()) {
            std::cout << "Battle is over." << std::endl;
            return;
        }

        // 决定是玩家还是怪物的回合
        // 这里简化处理，交替进行
        handlePlayerTurn();
        handleMonsterTurn();
    }

    void handlePlayerTurn() {
        // todo
//        std::cout << "Player's turn." << std::endl;
//        player.attack();
//        // 可以添加更多的玩家行动选项
    }

    void handleMonsterTurn() {
        // todo
//        std::cout << "Monster's turn." << std::endl;
//        monster.attack();
//        // 可以添加更多的怪物行动选项
    }

    bool isBattleOver() {
        // todo
        // 检查战斗是否结束的条件，例如玩家或怪物的生命值
        // 这里简化为返回一个固定值
        return isGameOver;
    }
};

#endif //ADVENTUREGAME_FIGHT_H
