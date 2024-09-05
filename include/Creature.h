//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_CREATURE_H
#define ADVENTUREGAME_CREATURE_H

#pragma once

#include <string>
#include <unordered_map>
#include "include/Item.h"

/**
 * @class Creature
 * @brief Creature 类表示游戏中的一个生物体，可以是玩家角色或敌对怪物。
 */
class Creature {
protected:
    std::string name;  ///< 生物的名称
    int level;         ///< 生物的等级，影响其属性和技能效果
    int maxHP;         ///< 生物的最大生命值
    int curHP;         ///< 生物的当前生命值
    int strength;      ///< 生物的力量，影响攻击力
    int defense;       ///< 生物的防御力，减少受到的伤害
    int agility;       ///< 生物的敏捷性，影响躲避和攻击速度
    std::unordered_map<std::string, Skill> skills; ///< 生物拥有的技能列表，键为技能名称
    std::unordered_map<std::string, Item> inventory; ///< 生物携带的物品清单，键为物品名称

public:
    Creature() : name(""), strength(10), maxHP(100), curHP(100), level(1), agility(10), defense(10) {}
    Creature(std::string name) : name(name), strength(10), maxHP(100), curHP(100), level(1), agility(10), defense(10) {}
    virtual ~Creature() = default;
    // 获取生物体的名称
    std::string getName() const { return name; }
    // 获取生物体的力量属性值
    int getStr() const { return strength; }
    // 获取生物体的最大生命值
    int getMaxHp() const { return maxHP; }
    // 获取生物体的当前生命值
    int getCurHp() const { return curHP; }
    // 获取生物体的等级
    int getLevel() const { return level; }
    // 获取生物体的敏捷属性值
    int getAgi() const { return agility; }
    // 获取生物体的防御属性值
    int getDef() const { return defense; }
    // 根据技能名称获取生物体的技能
    Skill getSkill(const std::string& skillName) const {
        if (skills.find(skillName) != skills.end()) {
            return skills.at(skillName);
        }
        return {};  // 返回一个默认技能对象
    }
    // 返回技能列表
    unordered_map<string, Skill> getSkillList() { return skills; }
    // 根据技能名称获取该技能的伤害值
    int getSkillDamage(std::string skillName) const {
        if (skills.find(skillName) != skills.end()) {
            return skills.at(skillName).getDmg();
        }
        return 0;
    }
    // 根据物品名称获取生物体的物品
    Item getItem(std::string itemName) const {
        if (inventory.find(itemName) != inventory.end()) {
            return inventory.at(itemName);
        }
        return {""};  // 返回一个默认物品对象
    }
    // 返回物品列表
    unordered_map<string, Item> getItemList() { return inventory; }
    // 设置生物体的名称
    void setName(std::string name) { this->name = name; }
    // 设置生物体的力量属性值
    void setStr(int str) { this->strength = str; }
    // 设置生物体的最大生命值
    void setMaxHp(int hp) { this->maxHP = hp; }
    // 设置生物体的当前生命值
    void setCurHp(int hp) { this->curHP = hp; }
    // 设置生物体的等级
    void setLevel(int lvl) { this->level = lvl; }
    // 设置生物体的敏捷属性值
    void setAgi(int agi) { this->agility = agi; }
    // 设置生物体的防御属性值
    void setDef(int def) { this->defense = def; }
    // 为生物体添加一个技能
    void addSkill(std::string skillName, Skill skill) { skills[skillName] = skill; }
    // 为生物体添加一个物品
    void addItem(Item item) { inventory[item.getName()] = item; }

    //是否死亡
    bool isDead(){ return curHP<=0;}
    // 虚函数：重置生物的基本属性
    virtual void resetStats() {
        setCurHp(getMaxHp());
    }
};
};



#endif //ADVENTUREGAME_CREATURE_H
