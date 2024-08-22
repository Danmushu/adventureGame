//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_PLAYER_H
#define ADVENTUREGAME_PLAYER_H

#include <common.h>
class Item;

class Player {
public:
    // 初始化玩家属性
    void initializeAttributes();

    // 玩家升级
    void levelUp();

    // 管理玩家物品
    void useItem(int itemId);//使用
    void addItem(Item item);

    // 显示玩家状态
    void displayStatus();

private:
    int strength; //力量
    int agility; //敏捷-闪避
    int health; //血量
    int experience; // 当前节点
    int level; //级别
    vector<Item> inventory; // 物品列表
};



#endif //ADVENTUREGAME_PLAYER_H
