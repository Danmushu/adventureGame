//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_PLAYER_H
#define ADVENTUREGAME_PLAYER_H
#pragma once

#include "Creature.h"
#include "include/map/map.h"
#include <string>

class Player : public Creature {
private:
    int exp;
    int requiredExp;
    int mp;
    Map map;

public:
    // 默认构造函数
    Player() : Creature(), exp(0), requiredExp(100), mp(100), map() {}
    // 带参数的构造函数
    Player(std::string name) : Creature(name), exp(0), requiredExp(100), mp(100), map() {}
    // 析构函数
    virtual ~Player() {}
    // 获取地图
    Map getMap() const { return map; }
    // 获取最后位置（这里可能是一个错误，通常不会和getMap()返回相同的值）
    Map getLastPos() const { return map; }
    // 获取当前位置的引用
    Map& getPos() { return map; }
    // 获取经验值
    int getExp() const { return exp; }
    // 获取魔法值
    int getMp() const { return mp; }
    // 打印技能列表
    void printSkillList() const {
        // todo
        // 输出玩家技能列表
    }
    // 打印物品列表
    void printItemList() const {
        // todo
        // 输出玩家物品列表
    }
    // 打印玩家信息
    void printInfo() const {
        // todo
        // 输出玩家信息
    }
    // 设置魔法值
    void setMp(int mp) { this->mp = mp; }
    // 设置经验值
    void setExp(int exp) { this->exp = exp; }
    // 使用物品
    void useItem(std::string name) {
        // todo
        // 使用物品逻辑
    }
    // 丢弃物品
    void dropItem(std::string name) {
        // todo
        // 丢弃物品逻辑
    }
};

#endif //ADVENTUREGAME_PLAYER_H
