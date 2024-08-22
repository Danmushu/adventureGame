//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_ITEM_H
#define ADVENTUREGAME_ITEM_H

#include <HeadFile.h>

class Item {
public:
    // 初始化物品属性
    void initializeItem(int itemId);

    // 使用物品
    void use(Player &player);

private:
    string name;
    ItemType type; // 攻击类、回复类、效果类
    int value;     // 伤害、回复量、属性提升量
};

#endif //ADVENTUREGAME_ITEM_H
