//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_PLAYER_H
#define ADVENTUREGAME_PLAYER_H

class Player {
public:
    // 初始化玩家属性
    void initializeAttributes();

    // 玩家升级
    void levelUp();

    // 管理玩家物品
    void useItem(int itemId);
    void addItem(Item item);

    // 显示玩家状态
    void displayStatus();

private:
    int strength;
    int agility;
    int health;
    int experience;
    int level;
    std::vector<Item> inventory; // 物品列表
};



#endif //ADVENTUREGAME_PLAYER_H
