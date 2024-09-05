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
    Space* currentSpace;

public:
    // 构造函数
    GameController(Player& player) : player(player), currentSpace(nullptr) {
        // 初始化代码
    }

    // 析构函数
    ~GameController() {
        // 清理代码
        delete currentSpace;
    }

    // 开始页面
    void openningPage() {
        // 读取游戏开始数据
        ifstream dataFile("../assets/scene/startPage.txt");
        string startPage;
        int spaceLength = std::max((PosControl::size.width / 10 - 88) / 2 + 2, 0);
        string space(spaceLength, ' ');

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
        // 重置玩家状态
        player.reset();

        // 设置初始空间
        currentSpace = new Space("秘境入口");
        // 初始化其他必要资源
        // 设置初始进度
        player.setProgress(0);

        // 显示欢迎信息
        cout << "Welcome to the Adventure Game!" << endl;
        cout << "Starting a new game..." << endl;
        runGame();
    }

    // 加载游戏
    void loadGame() {
        // 加载游戏的代码
    }
    bool main_showGameOverMenu(GameController& game) {
        std::cout << "Game Over!" << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "0. Restart Game" << std::endl;
        std::cout << "1. Exit Game" << std::endl;

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            // 处理非法输入
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            return false; // 默认退出游戏
        } else {
            switch (switcher(gameOverMenu, 2)) {
                case 0:
                    // 如果玩家选择了“新游戏”，则启动新游戏
                        game.newGame();
                        game.runGame();
                return true;
                break;
                case 1:
                    // 如果玩家选择了“退出游戏”，则显示退出页面，并退出程序
                        goodbye();
                        system("pause");  // 暂停等待用户按键
                return false;
                default: ;
            }
        }
    }
    // 运行游戏
    void runGame() {

        // 游戏主循环
        bool isRunning = true;

        while (isRunning) {
            // 显示当前空间信息
            currentSpace->describe();

            // 显示玩家可选的操作
            std::cout << "Choose an action:" << std::endl;
            std::cout << "1. Move to another space" << std::endl;
            std::cout << "2. Exit game" << std::endl;

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    // 移动到另一个空间
                    move();
                    break;
                case 2:
                    // 退出游戏
                    isRunning = false;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;

                    break;
            }

            // 检查玩家是否失败
            if (player.isDead()) {
                // 显示游戏结束菜单
                if (main_showGameOverMenu(*this)) {
                    // 重新开始游戏
                    newGame();
                } else {
                    // 退出游戏
                    isRunning = false;
                }
            }
        }
    }

    // 处理输入
    void handleInput() {
        // 处理用户输入的代码
    }

    // 移动
    void move() {
        // 移动玩家的代码
    }

    // 战斗
    void fight() {

    }

    // 保存游戏
    void saveGame() {
        // 保存游戏状态的代码
    }

    // 退出游戏
    static void goodBye() {
        std::cout << "Goodbye!" << std::endl;
    }


};
#endif //ADVENTUREGAME_GAMECONTROLLER_H