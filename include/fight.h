//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_FIGHT_H
#define ADVENTUREGAME_FIGHT_H

#include "Creature.h"
#include "Player.h"
#include "Monster.h"

/**
 * @brief Fight 类表示游戏中的战斗逻辑。
 */
class Fight {
private:
    Player player;         ///< 玩家对象
    Monster monster;       ///< 怪物对象
    bool isGameOver;       ///< 游戏是否结束

public:
    Fight(Player& player, Monster& monster) : player(player), monster(monster), isGameOver(false) {}

    // 开始战斗
    void startBattle() {
        std::cout << "Battle starts!" << std::endl;
        // 初始化战斗，例如设置生命值等
        player.resetStats();
        monster.resetStats();
    }

    // 处理战斗回合
    void handleTurn() {
        while (!isBattleOver()) {
            handlePlayerTurn();
            if (!isBattleOver()) {
                handleMonsterTurn();
            }
        }
        if (monster.isDead()) {
            std::cout << "You defeated the monster! Continue playing." << std::endl;
        } else if (player.isDead()) {
            std::cout << "You were defeated by the monster. Game over." << std::endl;
        }
    }

    // 处理玩家回合
    void handlePlayerTurn() {
        std::cout << "Player's turn." << std::endl;
        player.attack(monster);
        // 可以添加更多的玩家行动选项
    }

    // 处理怪物回合
    void handleMonsterTurn() {
        std::cout << "Monster's turn." << std::endl;
        monster.attack(player);
        // 可以添加更多的怪物行动选项
    }

    // 判断战斗是否结束
    bool isBattleOver() {
        if (player.isDead() || monster.isDead()) {
            isGameOver = true;
            return true;
        }
        return false;
    }
};

#endif //ADVENTUREGAME_FIGHT_H