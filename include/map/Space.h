//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_SPACE_H
#define ADVENTUREGAME_SPACE_H
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "include/Item.h"
#include "include/Monster.h"

/**
 * @class Space
 * @brief 代表地图上的单个空间，包含物品、怪物及其相互关系。
 */
class Space {
private:
    std::string name;                               ///< 空间的名称
    std::string description;                        ///< 空间的描述
    std::vector<Item> items;                        ///< 空间中包含的物品列表
    std::vector<Monster> monsters;                  ///< 空间中包含的怪物列表
    bool isPass;                                    ///< 是否可以通过此空间
    std::unordered_map<Space*, std::vector<Item>> towards; ///< 通往其他空间的条件物品

public:
    // 构造函数
    Space() : name("Unnamed Space"), description("A space with nothing special."), isPass(true) {}

    // 描述空间
    inline void describe() const {
        // todo
        std::cout << "Space Name: " << name << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "Items: ";
        for (const auto& item : items) {
            std::cout << item.getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Monsters: ";
        for (const auto& monster : monsters) {
            std::cout << monster.getName() << " ";
        }
        std::cout << std::endl;
        std::cout << "Can pass: " << (isPass ? "Yes" : "No") << std::endl;
    }

    // 获取空间名称
    inline std::string getName() const { return name; }

    // 获取空间中的物品列表
    inline std::vector<Item> getItems() const { return items; }

    // 检查是否可以通过此空间
    inline bool getPass() const { return isPass;}

    // 获取空间的详细信息
    inline bool getInfo() const {
        // todo
        describe();
        return true;
    }

    // 在空间内进行战斗
    inline void fight() {
        if (monsters.empty()) {
            std::cout << "No monsters to fight in this space." << std::endl;
            return;
        }
        // todo
        // 战斗逻辑
    }

    // 设置空间是否可以通过
    inline void setPass(bool pass) { isPass = pass; }

    // 拾取空间中的物品
    inline void pickUp(const std::string& name) {
        // todo
//        auto it = std::find_if(items.begin(), items.end(), [&name](const Item& item) {
//            return item.getName() == name;
//        });
//        if (it != items.end()) {
//            items.erase(it);
//            std::cout << "You picked up " << name << "." << std::endl;
//        } else {
//            std::cout << "Item not found." << std::endl;
//        }
    }
};

#endif //ADVENTUREGAME_SPACE_H
