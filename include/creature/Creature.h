//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_CREATURE_H
#define ADVENTUREGAME_CREATURE_H

#pragma once

#include <string>
#include <unordered_map>
#include "../item/Item.h"
#include "../item/Skill.h"

class Creature {
protected:
    std::string name;
    int strength;
    int maxHP;
    int currentHP;
    int level;
    int agility;
    std::unordered_map<std::string, Skill> skills;
    std::unordered_map<std::string, Item> inventory;

public:
    Creature();
    Creature(std::string name);
    virtual ~Creature() {}

    std::string getName() const;
    int getStr() const;
    int getMaxHp() const;
    int getCurHp() const;
    int getLevel() const;
    int getAgi() const;

    Skill getSkill(std::string skillName) const;
    int getSkillDamage(std::string skillName) const;
    Item getItem(std::string itemName) const;

    void setName(std::string name);
    void setStr(int str);
    void setMaxHp(int hp);
    void setCurHp(int hp);
    void setLevel(int lvl);
    void setAgi(int agi);

    void addSkill(std::string skillName, Skill skill);
    void addItem(Item item);
};

// Creature 类的构造函数和成员函数实现
Creature::Creature() : name(""), strength(10), maxHP(100), currentHP(100), level(1), agility(10) {}

Creature::Creature(std::string name) : name(name), strength(10), maxHP(100), currentHP(100), level(1), agility(10) {}

std::string Creature::getName() const { return name; }
int Creature::getStr() const { return strength; }
int Creature::getMaxHp() const { return maxHP; }
int Creature::getCurHp() const { return currentHP; }
int Creature::getLevel() const { return level; }
int Creature::getAgi() const { return agility; }

Skill Creature::getSkill(std::string skillName) const {
    if (skills.find(skillName) != skills.end()) {
        return skills.at(skillName);
    }
    return Skill();  // 返回一个默认技能对象
}

int Creature::getSkillDamage(std::string skillName) const {
    if (skills.find(skillName) != skills.end()) {
        return skills.at(skillName).getPower();
    }
    return 0;
}

Item Creature::getItem(std::string itemName) const {
    if (inventory.find(itemName) != inventory.end()) {
        return inventory.at(itemName);
    }
    return Item("");  // 返回一个默认物品对象
}

void Creature::setName(std::string name) { this->name = name; }
void Creature::setStr(int str) { this->strength = str; }
void Creature::setMaxHp(int hp) { this->maxHP = hp; }
void Creature::setCurHp(int hp) { this->currentHP = hp; }
void Creature::setLevel(int lvl) { this->level = lvl; }
void Creature::setAgi(int agi) { this->agility = agi; }

void Creature::addSkill(std::string skillName, Skill skill) {
    skills[skillName] = skill;
}

void Creature::addItem(Item item) {
    inventory[item.getName()] = item;
}



#endif //ADVENTUREGAME_CREATURE_H
