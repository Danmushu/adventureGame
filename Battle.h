//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_BATTLE_H
#define ADVENTUREGAME_BATTLE_H

#include <HeadFile.h>

class Battle {
public:
    // 构造函数：初始化战斗
    Battle(Player &player, std::vector<Monster> &monsters);

    // 开始战斗
    void startBattle();

private:
    Player &player;
    std::vector<Monster> &monsters;
    bool battleOver;
    bool playerVictory;

    // 内部方法：处理伤害计算
    int calculateDamage(int attackerStrength, int defenderAgility);
};



#endif //ADVENTUREGAME_BATTLE_H
