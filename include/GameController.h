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
        curSpace.reset();
    }


    // 检查指定名称的数据文件是否存在
    bool dataExist(const string &name) {
        string fileName = name + ".dat";  // 构造数据文件的名称
        string path = "../save/" + fileName;
        std::ifstream dataFile(path);  // 尝试打开文件
        bool isOpen = dataFile.is_open();  // 检查文件是否成功打开
        dataFile.close();  // 关闭文件
        return isOpen;  // 返回文件是否存在
    }

    // 保存玩家数据到文件 todo
    void saveData() {
        // 创建数据文件，如果文件已存在则覆盖
        std::ofstream dataFile("../save/" + player.getName() + ".dat", std::ios::trunc);
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
        // 解锁了那些空间
        for(auto &i:player.getMap().getAcc())
            dataFile << i.first.getName() << " " << i.second << endl;
    }

    // todo 初始化逻辑还需要补充
    void init(){
        // todo
        if (dataExist(player.getName())) {  // 如果数据文件存在
            cout << "数据已存在，是否读取？" << endl;
            Menu isOrNo[2]{"是", "否"};  // 创建菜单
            switch (switcher(isOrNo, 2)) {  // 显示菜单并获取用户选择
                case 0:  // 如果选择“是”，则退出函数，加载数据
                    return;
                case 1:  // 如果选择“否”，则保存当前数据
                    saveData();
                    player.setLevel(1);
                    curSpace = player.getMap().getLocation();
            }
        } else {  // 如果数据文件不存在
            saveData();  // 保存初始数据
            player.setLevel(1);
            curSpace = player.getMap().getLocation();
        }
    }

    // 加载玩家数据 todo
    void loadData() {
        string path = "../save/";
        if (dataExist(player.getName())) {  // 如果数据文件存在
            std::ifstream dataFile(path + player.getName() + ".dat");  // 打开文件
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

               }
            // 加载玩家位置 todo
            string name;
            dataFile >> name;
            curSpace->setName(name);
            // todo 补充读取地图的逻辑

        } else {  // 如果数据文件不存在
            system("cls");
            cout << "数据不存在，创建新存档" << endl;
            saveData();  // 保存初始数据
            system("pause");
        }
    }

    // 新游戏 todo
    void newGame() {
        system("cls");  // 清屏
        init();  // 初始化玩家数据
        system("cls");  // 再次清屏
        loadGame();  // 加载游戏
    }

    // 加载游戏
    void loadGame() {
        // todo
        loadData();  // 加载玩家数据
        Map::printMap();  // 打印地图
        //onMap(player);  // todo 处理地图上的行为
        runGame();
        saveData();  // 保存玩家数据
        goodbye();  // 显示游戏结束页面
        system("pause");  // 暂停，等待用户操作
    }

    // 运行游戏
    void runGame() {
        // todo
        // 游戏循环的代码
        Menu motion[]{
            "1.观气", //观察怪兽状态
            "2.攻之", //进攻怪兽
            "3.行之", //进入下一个地图
            "4.养气", //回复气的含量
            "5.物品"  //使用物品
        };
        while(true){
            player.printInfo();
            switch (switcher(motion, 5)) {
                case 0:
                    // todo 输出怪兽状态
                    break;
                case 1:
                    // todo 攻击选定的怪兽,fight逻辑
                    break;
                case 2:
                    // todo 输出连接的地方，并选择去哪
                    break;
                case 3:
                    // todo 回复自身气
                    break;
                case 4:
                    // todo 使用物品的逻辑
                    break;
            }
        }
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

    // 显示游戏结束页面
    void goodbye() {
        system("cls");  // 清除控制台内容
        ifstream creditsLogoFile("../assets/.endLogo");  // 打开结束Logo文件
        string logo;
        while (getline(creditsLogoFile, logo)) {  // 逐行读取文件
            cout << logo << endl;
            Sleep(randInt(20, 50));  // 延迟输出
        }
        creditsLogoFile.close();
        ifstream creditsFile("../assets/.endPage");  // 打开结束消息文件
        string credits;
        while (getline(creditsFile, credits)) {  // 逐行读取文件
            cout << credits << endl;
            Sleep(randInt(20, 50));  // 延迟输出
        }
        creditsFile.close();
    }
};
#endif //ADVENTUREGAME_GAMECONTROLLER_H
