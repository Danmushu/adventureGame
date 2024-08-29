//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_PLAYER_H
#define ADVENTUREGAME_PLAYER_H
#pragma once

#include "../creature/creature.h"
#include "../map/map.h"

class Player : public Creature {
private:
    int exp;
    int requiredExp;
    int mp;
    Map map;

public:
    Player();
    Player(std::string name);
    virtual ~Player() {}

    Map getMap() const;
    Map getLastPos() const;
    Map& getPos();

    int getExp() const;
    int getMp() const;

    void printSkillList() const;
    void printItemList() const;
    void printInfo() const;

    void setMp(int mp);
    void useItem(std::string name);
    void dropItem(std::string name);
};

// Player 类的构造函数和成员函数实现
Player::Player() : Creature(), exp(0), requiredExp(100), mp(100) {}

Player::Player(std::string name) : Creature(name), exp(0), requiredExp(100), mp(100) {}

Map Player::getMap() const { return map; }
Map Player::getLastPos() const { return map; }
Map& Player::getPos() { return map; }

int Player::getExp() const { return exp; }
int Player::getMp() const { return mp; }

void Player::printSkillList() const {
    //todo
    // 输出玩家技能列表
}

void Player::printItemList() const {
    //todo
    // 输出玩家物品列表
}

void Player::printInfo() const {
    //todo
    // 输出玩家信息
}

void Player::setMp(int mp) { this->mp = mp; }

void Player::useItem(std::string name) {
    //todo
    // 使用物品逻辑
}

void Player::dropItem(std::string name) {
    //todo
    // 丢弃物品逻辑
}

#endif //ADVENTUREGAME_PLAYER_H
