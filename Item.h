//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_ITEM_H
#define ADVENTUREGAME_ITEM_H

#include <common.h>
class Player;

class Item {
public:
    // 初始化物品属性
    void initializeItem(int itemId);

private:
    string name; //物品名
    int type; // 攻击类(1)、回复类(2)、效果类(3)
    int value;     // 伤害、回复量、属性提升量
};

#endif //ADVENTUREGAME_ITEM_H
