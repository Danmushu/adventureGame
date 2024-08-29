//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_MONSTER_H
#define ADVENTUREGAME_MONSTER_H
#pragma once

#include "../creature/creature.h"

class Monster : public Creature {
private:
    bool isBoss;
    std::string description;

public:
    Monster();
    Monster(std::string name, bool isBoss);
    virtual ~Monster() {}

    bool getBoss() const;
    void setBoss(bool isBoss);

    void readMonsterData(int monsterNumber);
};

// Monster 类的构造函数和成员函数实现
Monster::Monster() : Creature(), isBoss(false), description("") {}

Monster::Monster(std::string name, bool isBoss) : Creature(name), isBoss(isBoss), description("") {}

bool Monster::getBoss() const { return isBoss; }
void Monster::setBoss(bool isBoss) { this->isBoss = isBoss; }

void Monster::readMonsterData(int monsterNumber) {
    //todo
    // 读取怪物数据的逻辑
}

#endif //ADVENTUREGAME_MONSTER_H
