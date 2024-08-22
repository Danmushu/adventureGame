//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_SAVELOAD_H
#define ADVENTUREGAME_SAVELOAD_H

#include <common.h>

class Map;

class SaveLoad {
public:
    // 保存游戏进度
    void saveGame(Player &player, Map &map);

    // 加载游戏进度
    void loadGame(Player &player, Map &map);

private:
    string saveFile = "game_save.txt";
};



#endif //ADVENTUREGAME_SAVELOAD_H
