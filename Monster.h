//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_MONSTER_H
#define ADVENTUREGAME_MONSTER_H

#include <common.h>

class Monster {
public:
    // 初始化怪物属性
    void initializeMonster(int level);

    // 怪物攻击玩家
    void attackPlayer(Player &player);

    // 受到玩家攻击
    void takeDamage(int amount);

    // 检查怪物是否死亡
    bool isDead();

private:
    int health;
    int strength;
    int agility;
};

#endif //ADVENTUREGAME_MONSTER_H
