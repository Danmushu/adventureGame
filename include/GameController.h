//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_GAMECONTROLLER_H
#define ADVENTUREGAME_GAMECONTROLLER_H
#pragma once
#include "player/PlayerController.h"
#include "monster/MonsterController.h"
#include "battle/FightController.h"

/**
 * @class GameController
 * @brief 游戏的主要控制器，负责管理游戏的整体流程。
 */
class GameController {
private:
    PlayerController& playerController;   ///< 玩家控制器的引用
    MonsterController& monsterController; ///< 怪物控制器的引用
    FightController& fightController;     ///< 战斗控制器的引用

public:
    GameController(PlayerController& pCtrl, MonsterController& mCtrl, FightController& fCtrl)
            : playerController(pCtrl), monsterController(mCtrl), fightController(fCtrl) {}

    void newGame();               ///< 开始新游戏
    void loadGame();              ///< 加载游戏
    void runGame();               ///< 运行游戏主循环
    void handleInput();           ///< 处理用户输入
    void saveGame();              ///< 保存游戏
    void goodBye();               ///< 退出游戏
};

#endif //ADVENTUREGAME_GAMECONTROLLER_H
