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
    // 构造函数
    Item() : name(""),  attack(0), defense(0), agility(0), recovery(0), damage(0), mp(0), activateTime(0) {}
    Item(std::string name) : name(name),  attack(0), defense(0), agility(0), recovery(0), damage(0), mp(0), activateTime(0) {}

    // 虚析构函数
    virtual ~Item() {}
    // 获取物品名称
    std::string getName() const { return name; }
    // 获取攻击力加成
    int getAtk() const { return attack; }
    // 获取防御力加成
    int getDef() const { return defense; }
    // 获取敏捷度加成
    int getAgi() const { return agility; }
    // 获取恢复力加成
    int getRec() const { return recovery; }
    // 获取伤害值
    int getDmg() const { return damage; }
    // 获取物品描述
    std::string getDes() const { return description; }
    // 获取生效时间
    int getActTime() const { return activateTime; }
    // 获取魔法值消耗或加成
    int getMp() const { return mp; }
    // 设置物品名称
    void setName(std::string name) { this->name = name; }
    // 设置攻击力加成
    void setAtk(int atk) { this->attack = atk; }
    // 设置防御力加成
    void setDef(int def) { this->defense = def; }
    // 设置敏捷度加成
    void setAgi(int agi) { this->agility = agi; }
    // 设置恢复力加成
    void setRec(int rec) { this->recovery = rec; }
    // 设置伤害值
    void setDmg(int dmg) { this->damage = dmg; }
    // 设置物品描述
    void setDes(std::string description) { this->description = description; }
    // 设置生效时间
    void setActTime(int time) { this->activateTime = time; }
    // 设置魔法值消耗或加成
    void setMp(int mp) { this->mp = mp; }
};

/**
 * @class Template
 * @brief 派生类的基本内容
 */
// 派生类 Skill 的定义
class Template : public Item {
private:
    int type;

public:
    Template() : Item(), type() {}
    Template(int type) : Item(), type(type) {}

    ~Template() override = default;

    int getType() const { return type; }
    void setType(int type) { this->type = type; }
};

typedef Template Skill; ///< 技能类型 1.攻击法术 2.防御法术 3.治疗法术 4.遁走法术
typedef Template Weapon; ///< 武器类型 1.剑 2.刀 3.甲 4.靴
typedef Template Medicine; ///< 药物类型 1.狂暴 2.恢复 3.升级
typedef Template Special; ///< 特殊 通关密钥


#endif //ADVENTUREGAME_ITEM_H
