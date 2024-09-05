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

    void printInfo(){
        cout<< name << " [境界]" << level <<" [血]" << maxHP << endl;
    }
//    /*** 宋家鹏 ***/
//    void resetStats() override {
//        // 重置当前生命值
//        setCurHp(getMaxHp());
//        // 其他需要重置的属性
//        // 例如：攻击力、防御力等
//    }
//    // 攻击玩家
//    void attack(Creature& target) {
//        // 简化处理：每次攻击减少固定的生命值
//        int damage = getStr();  // 假设力量值作为攻击力
//        target.setCurHp(target.getCurHp() - damage);
//        std::cout << "Monster attacks the player for " << damage << " damage." << std::endl;
//    }
//
    // 判断怪物是否死亡
    bool isDead() const { return getCurHp() <= 0; }
};


#endif //ADVENTUREGAME_MONSTER_H
