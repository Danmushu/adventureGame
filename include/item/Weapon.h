//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_WEAPON_H
#define ADVENTUREGAME_WEAPON_H
#pragma once

#include "item.h"

/**
 * @class Weapon
 * @brief 代表游戏中的武器。武器是 Item 的一种特殊类型，具有攻击能力。
 */
class Weapon : public Item {
protected:
    std::string type; ///< 武器类型

public:
    Weapon();
    Weapon(std::string name, std::string type);
    virtual ~Weapon() {}

    // 获取和设置武器类型的方法
    std::string getType() const;
    void setType(std::string type);
};

// Weapon 类的实现
Weapon::Weapon() : Item(), type("weapon") {}

Weapon::Weapon(std::string name, std::string type) : Item(name), type(type) {}

std::string Weapon::getType() const { return type; }

void Weapon::setType(std::string type) { this->type = type; }

#endif //ADVENTUREGAME_WEAPON_H
