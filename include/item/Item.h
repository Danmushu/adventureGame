//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_ITEM_H
#define ADVENTUREGAME_ITEM_H
#pragma once

#include <string>

/**
 * @class Item
 * @brief 代表游戏中的物品的基类。包含物品的基本属性和操作方法。
 */
class Item {
protected:
    std::string name;          ///< 物品名称
    std::string description;   ///< 物品描述
    int attack;                ///< 攻击力加成
    int defense;               ///< 防御力加成
    int agility;               ///< 敏捷度加成
    int recovery;              ///< 恢复力加成
    int damage;                ///< 伤害值
    int mp;                    ///< 魔法值消耗或加成
    int activateTime;          ///< 生效时间

public:
    Item();
    Item(std::string name);
    virtual ~Item() {}

    // 获取物品属性的方法
    std::string getName() const;
    int getAtk() const;
    int getDef() const;
    int getAgi() const;
    int getRec() const;
    int getDmg() const;
    std::string getDes() const;
    int getActTime() const;
    int getMp() const;

    // 设置物品属性的方法
    void setName(std::string name);
    void setAtk(int atk);
    void setDef(int def);
    void setAgi(int agi);
    void setRec(int rec);
    void setDmg(int dmg);
    void setDes(std::string description);
    void setActTime(int time);
    void setMp(int mp);
};

// Item 类的实现
Item::Item() : name(""), description(""), attack(0), defense(0), agility(0), recovery(0), damage(0), mp(0), activateTime(0) {}

Item::Item(std::string name) : name(name), description(""), attack(0), defense(0), agility(0), recovery(0), damage(0), mp(0), activateTime(0) {}

std::string Item::getName() const { return name; }
int Item::getAtk() const { return attack; }
int Item::getDef() const { return defense; }
int Item::getAgi() const { return agility; }
int Item::getRec() const { return recovery; }
int Item::getDmg() const { return damage; }
std::string Item::getDes() const { return description; }
int Item::getActTime() const { return activateTime; }
int Item::getMp() const { return mp; }

void Item::setName(std::string name) { this->name = name; }
void Item::setAtk(int atk) { this->attack = atk; }
void Item::setDef(int def) { this->defense = def; }
void Item::setAgi(int agi) { this->agility = agi; }
void Item::setRec(int rec) { this->recovery = rec; }
void Item::setDmg(int dmg) { this->damage = dmg; }
void Item::setDes(std::string description) { this->description = description; }
void Item::setActTime(int time) { this->activateTime = time; }
void Item::setMp(int mp) { this->mp = mp; }

#endif //ADVENTUREGAME_ITEM_H
