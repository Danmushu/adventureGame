//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_SPACE_H
#define ADVENTUREGAME_SPACE_H
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "../item/item.h"
#include "../monster/monster.h"

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
    Space();

    void describe();                                ///< 描述空间
    std::string getName();                          ///< 获取空间名称
    std::vector<Item> getItems();                   ///< 获取空间中的物品列表
    bool getPass();                                 ///< 检查是否可以通过此空间
    bool getInfo();                                 ///< 获取空间的详细信息
    void fight();                                   ///< 在空间内进行战斗
    void setPass(bool pass);                        ///< 设置空间是否可以通过
    void pickUp(std::string name);                  ///< 拾取空间中的物品
};

#endif //ADVENTUREGAME_SPACE_H
