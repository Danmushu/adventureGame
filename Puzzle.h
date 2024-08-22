//
// Created by Danmu on 2024/8/22.
//

#ifndef ADVENTUREGAME_PUZZLE_H
#define ADVENTUREGAME_PUZZLE_H

#include <common.h>

class Puzzle {
public:
    // 初始化解密游戏
    Puzzle(int level);

    // 开始解密
    bool startPuzzle();

private:
    int level;
    string solution;
    string hint;

    // 初始化解密游戏细节
    void initializePuzzle(int level);
};
;


#endif //ADVENTUREGAME_PUZZLE_H
