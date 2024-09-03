//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_GAMECONTROLLER_H
#define ADVENTUREGAME_GAMECONTROLLER_H
#pragma once
#include "Player.h"
#include "Space.h"
#include "interface.h"

/**
 * @class GameController
 * @brief 游戏的主要控制器，负责管理游戏的整体流程。
 */
class GameController {
private:
    Player& player;
    Space* currentSpace;//真的需要吗

public:
    // 构造函数
    GameController(Player& player) : player(player), currentSpace(nullptr) {
        // todo
        // 初始化代码
    }

    // 析构函数
    ~GameController() {
        // 清理代码
        delete currentSpace;
    }

    // 开始页面
    void openningPage() {
        // todo
        // 读取游戏开始数据
        ifstream dataFile("../assets/scene/startPage.txt");
        string startPage;
        int spaceLength = std::max((PosControl::size.width / 10 - 88) / 2 + 2, 0);
        string space(spaceLength, ' ');;
        while (getline(dataFile, startPage)) {
            int color = randInt(1, 15);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            Sleep(50);
            cout << space << startPage << endl;
        }
        dataFile.close();

    }

    // 新游戏
    void newGame() {
        // todo
        // 初始化新游戏的代码
    }

    // 加载游戏
    void loadGame() {
        // todo
        // 加载游戏的代码
    }

    // 运行游戏
    void runGame() {
        // todo
        // 游戏循环的代码
    }

    // 处理输入
    void handleInput() {
        // todo
        // 处理用户输入的代码
    }

    // 移动
    void move() {
        // todo
        // 移动玩家的代码
    }

    // 战斗
    void fight() {
        // todo
        // 战斗逻辑的代码
    }

    // 保存游戏
    void saveGame() {
        // todo
        // 保存游戏状态的代码
    }

    // 退出游戏
    void goodBye() {
        // todo
        std::cout << "Goodbye!" << std::endl;
    }
};
#endif //ADVENTUREGAME_GAMECONTROLLER_H
