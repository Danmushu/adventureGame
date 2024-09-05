//
// Created by Danmu on 2024/9/5.
//

#ifndef ADVENTUREGAME_BATTLE_H
#define ADVENTUREGAME_BATTLE_H
#pragma once

/**
 * @class Battle
 * @brief 表示游戏中的战斗逻辑。
 * */

#include "Monster.h"
#include "Player.h"
#include "interface.h"

class Battle {
private:
    Player& player;         ///< 玩家对象
    Monster& monster;       ///< 怪物对象
    bool isGameOver;        ///< 游戏是否结束

public:
    Battle(Player& player, Monster& monster) : player(player), monster(monster), isGameOver(false) {}

    // 开始战斗
    void startBattle() {
        std::cout << "战斗开始！" << std::endl;
        // 初始化战斗，例如设置生命值等
//        player.resetStats();
//        monster.resetStats();
        handleTurn();
        finalizeBattle();
    }

    // 处理战斗回合
    void handleTurn() {
        while (player.isDead() && monster.isDead()) {
            handlePlayerTurn();
            handleMonsterTurn();
        }
    }

    // 处理进攻过程 turn=1->player atk else monster atk
    void handleAtk(bool turn){

    }

    // 处理玩家回合
    void handlePlayerTurn() {
        Menu motion[]{
            "物理攻击",
            "法术攻击",
            "物品攻击"
        };
        switch (switcher(motion, 3)) {
            case 0:
                player.attack(monster);
                std::cout << "Player attacks the monster." << std::endl;
                break;
            case 1:
                player.printSkillList();
                std::cout << "Player defends." << std::endl;
                break;
            case 2:
                player.useItem();
                std::cout << "Player uses an item." << std::endl;
                break;
        }
    }

    // 处理怪物回合
    void handleMonsterTurn() {
        std::cout << "Monster's turn." << std::endl;
        int choice = monster.getChoice();
        switch (choice) {
            case 1:
                monster.attack(player);
                std::cout << "Monster attacks the player." << std::endl;
                break;
            case 2:
                monster.defend();
                std::cout << "Monster defends." << std::endl;
                break;
            default:
                std::cout << "Monster does nothing." << std::endl;
                break;
        }
    }

    // 判断战斗是否结束
    bool isBattleOver() {
        if (player.isDead()) {
            isGameOver = true;
            return true;
        } else if (monster.isDead()) {
            isGameOver = true;
            return true;
        }
        return false;
    }

    // 战斗结束后的收尾工作
    void finalizeBattle() {
        if (monster.isDead()) {
            cout << "战斗胜利！" << endl;
        } else if (player.isDead()) {
            cout << "战斗失败！还需要多练！" << endl;
        }
    }
};
#endif //ADVENTUREGAME_BATTLE_H
