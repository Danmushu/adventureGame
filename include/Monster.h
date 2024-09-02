//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_MONSTER_H
#define ADVENTUREGAME_MONSTER_H
#pragma once

#include "Creature.h"
#include <string>

class Monster : public Creature {
private:
    bool isBoss;
    std::string description;

public:
    // 默认构造函数
    Monster() : Creature(), isBoss(false) {}
    // 带参数的构造函数
    Monster(std::string name, bool isBoss) : Creature(name), isBoss(isBoss) {}
    // 析构函数
    ~Monster() override = default;
    // 获取是否为Boss
    bool getBoss() const { return isBoss; }
    // 设置是否为Boss
    void setBoss(bool isBoss) { this->isBoss = isBoss; }
//    // 读取怪物数据
//    void readMonsterData(int id) {
//        // 读取怪物数据的逻辑
//        // load()从数据文件中读取对应id的数据
//    }
};

#endif //ADVENTUREGAME_MONSTER_H
