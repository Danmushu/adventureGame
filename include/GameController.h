//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_GAMECONTROLLER_H
#define ADVENTUREGAME_GAMECONTROLLER_H
#pragma once
#include "Player.h"
#include "Space.h"
#include "interface.h"
#include "data.h"

using namespace DataControl;

/**
 * @class GameController
 * @brief 游戏的主要控制器，负责管理游戏的整体流程。
 */
class GameController {
private:
    Player& player;
    shared_ptr<Space> curSpace;

public:
    // 构造函数
    GameController(Player& player) : player(player), curSpace(nullptr) {
        // todo
        // 初始化代码
    }

    // 析构函数
    ~GameController() {
        // 清理代码
        delete curSpace;
    }

//    // 开始页面 todo
//    void openningPage() {
//        // todo
//        // 读取游戏开始数据
//        ifstream dataFile("../assets/scene/startPage.txt");
//        string startPage;
//        int spaceLength = std::max((PosControl::size.width / 10 - 88) / 2 + 2, 0);
//        string space(spaceLength, ' ');;
//        while (getline(dataFile, startPage)) {
//            int color = randInt(1, 15);
//            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//            Sleep(50);
//            cout << space << startPage << endl;
//        }
//        dataFile.close();
//
//    }

    // 检查指定名称的数据文件是否存在
    bool dataExist(const string &name) {
        string fileName = name + ".dat";  // 构造数据文件的名称
        std::ifstream dataFile(fileName);  // 尝试打开文件
        bool isOpen = dataFile.is_open();  // 检查文件是否成功打开
        dataFile.close();  // 关闭文件
        return isOpen;  // 返回文件是否存在
    }

    // 保存玩家数据到文件 todo
    void saveData(Player &player) {
        // 创建数据文件，如果文件已存在则覆盖
        std::ofstream dataFile(player.getName() + ".dat", std::ios::trunc);
        // 保存玩家的主要属性
        dataFile << player.getLevel() << endl;
        dataFile << player.getMaxHp() << " " << player.getCurHp() << endl;
        dataFile << player.getRequiredMp() << " " << player.getMp() << endl;
        dataFile << player.getStr() << " " << player.getDef() << " " << player.getAgi() << endl;
        // 保存玩家技能
        dataFile << player.getSkillList().size() << endl; //获得技能数量
        for(auto &i:player.getSkillList()){ dataFile << i.first << endl; }
        // 保存玩家物品栏
        dataFile << player.getItemList().size() << endl; //获得物品数量
        for(auto &i:player.getItemList()) {dataFile << i.first << endl; }
        // todo
        // 保存玩家的位置
        dataFile << curSpace->getName() << endl;// 正处于的位置
        for(auto &i:player.getMap().getAcc())
            dataFile << i.first.getName() << " " << i.second << endl;
    }
    // todo
    void init(Player player){
        // todo 初始化逻辑还需要补充
        if (dataExist(player.getName())) {  // 如果数据文件存在
            cout << "数据已存在，是否读取？" << endl;
            Menu menu[2]{"是", "否"};  // 创建菜单
            switch (switcher(menu, 2)) {  // 显示菜单并获取用户选择
                case 0:  // 如果选择“是”，则退出函数，加载数据
                    return;
                case 1:  // 如果选择“否”，则保存当前数据
                    saveData(player);
                    player.setLevel(1);
            }
        } else {  // 如果数据文件不存在
            saveData(player);  // 保存初始数据
            player.setLevel(1);
        }
    }

    void loadGame(Player &player);

    // 加载玩家数据 todo
    void loadData(Player &player) {
        if (dataExist(player.getName())) {  // 如果数据文件存在
            std::ifstream dataFile(player.getName() + ".dat");  // 打开文件
            // 加载玩家的主要属性
            int level, maxHp, curHp, maxMp, Mp, str, def, agi;
            dataFile >> level >> maxHp >> curHp;
            dataFile >> maxMp >> Mp;
            dataFile >> str >> def >> agi;
            player.setMainFeature(level, maxHp, curHp, maxMp, Mp, str, def, agi);
            // 加载玩家技能
            int numOfSkill;
            dataFile >> numOfSkill;
            while(numOfSkill--){
                // 读取技能的逻辑 todo
            }
            // 加载玩家物品栏 todo
            int numOfItem;
            dataFile >> numOfItem;
            while(numOfItem--){
               // 读取物品的逻辑 todo
               // todo 打开item.txt

               // 进行比对和读取数据

            }
            // 加载玩家位置 todo
            string name;
            dataFile >> name;
            curSpace->setName(name);
            // todo 补充读取地图的逻辑

        } else {  // 如果数据文件不存在
            system("cls");
            cout << "数据不存在，创建新存档" << endl;
            saveData(player);  // 保存初始数据
            system("pause");
        }
    }

    // 新游戏 todo
    void newGame() {
        system("cls");  // 清屏
        init(player);  // 初始化玩家数据
        system("cls");  // 再次清屏
        loadGame(player);  // 加载游戏
    }

    // 加载游戏
    void loadGame(Player& player) {
        // todo
        loadData(player);  // 加载玩家数据
        Map::printMap();  // 打印地图
        onMap(player);  // 处理地图上的行为
        saveData(player);  // 保存玩家数据
        goodbye();  // 显示游戏结束页面
        system("pause");  // 暂停，等待用户操作
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

    // 捡物品
    void pickUp(string name){
        Item item = curSpace->pickUp(name);
        // 如果item = {}
        if (!item.getName().empty()){ cout << "没捡起来，因为该物品不存在"; }
        else{
            cout << "成功捡起了" << item.getName() << endl;
            player.addItem(item);
        }
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
