//
// Created by Danmu on 2024/9/2.
//

#ifndef ADVENTUREGAME_DATA_H
#define ADVENTUREGAME_DATA_H
#include<Creature.h>
#include<Player.h>
#include<string>
#include<Monster.h>
#include<Map.h>
using namespace std;

namespace DataControl{

//检查文件存在
    bool dataExist(const string &name) {
        string fileName = name + ".dat";
        std::ifstream dataFile(fileName);
        bool isOpen = dataFile.is_open();
        dataFile.close();
        return isOpen;
    }

//保存Creature类数据，作为基类数据保存
    void saveCreatureData(const Creature& creature, const std::string& filename) {
        std::ofstream file(filename, std::ios::trunc);
        if (file.is_open()) {
            file << creature.getName() << " " << creature.getStr() << " "
                 << creature.getMaxHp() << " " << creature.getCurHp() << " "
                 << creature.getLevel() << " " << creature.getAgi() << " "
                 << creature.getDef() << "\n";
            for (const auto& skill : creature.getSkillList()) {
                file << "Skill " << skill.first << " " << skill.second.getDmg() << "\n";
            }
            for (const auto& item : creature.getItemList()) {
                file << "Item " << item.first << "\n";
            }
            file.close();
        } else {
            std::cerr << "无法读取文件" << std::endl;
        }
    }                                                           //后面直接调用它

//加载生物类数据，作为基类 加载数据
    void loadCreatureData(const Creature& creature, const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        if (file.is_open()) {
            std::string name;
            int strength, maxHP, curHP, level, agility, defense;
            file >> name ;
            file >> strength;
            file >> maxHP
            file >> curHP
            file >> level
            file >> agility
            file >> defense;
            creature.setName(name);
            creature.setStr(strength);
            creature.setMaxHp(maxHP);
            creature.setCurHp(curHP);
            creature.setLevel(level);
            creature.setAgi(agility);
            creature.setDef(defense);

            std::string type;
            while (file >> type) {
                if (type == "Skill") {
                    std::string skillName;
                    int damage;
                    file >> skillName >> damage;
                    creature.addSkill(skillName, {skillName, damage});
                } else if (type == "Item") {
                    std::string itemName;
                    file >> itemName;
                    creature.addItem({name, ""});
                }
            }
            file.close();
        } else {
            std::cerr << "数据无法读取" << std::endl;
        }
    }

//保存玩家数据
    void savePlayerData(Player& player) {
      saveCreatureData(player,player.getName()+".dat");
      std::ofstream file(player.getName()+".dat", std::ios::trunc);
      file << player.getPos().line << ' ' << player.getPos().column << endl;
    }                                                          //调用基类保存函数,这里可以加一些Player特有的逻辑

//加载玩家数据
    void loadPlayerData(Creature& player) {
      loadCreatureData(player,player.getName()+".dat");
      std::ifstream file(player.getName() + ".dat");
      int line,column;
      file >> line >> column;
    }                                                           //调用基类加载函数，这里可以加一些Player 类特有的逻辑

//存怪物数据
    void saveMonsterData(Monster& monster) {
      saveCreatureData(monster,monster.getName()+".dat");         //和上面一样，但这个函数可能用不到
    }

//加载怪物数据
    void loadMonsterData(Monster& monster) {
      loadCreatureData(monster,monster.getName()+".dat");           //调用基类加载函数，肯能要添一些Monster特有的逻辑
    }

//初始化玩家数据
    void InitPlayerData(Player& player) {
        if (dataExist(player.getName())) {                                                               // 如果文件存在则读取
            cout << "数据已存在，是否读取？" << endl;
            Menu menu[2]{
                "是","否"
            };
            switch (switcher(menu, 2)) {
                case 0:
                    return;
                case 1:
                  savePlayerData(player);
                  player.getMap().showMap(player.getName()+".dat");
            }
        } else {
            savePlayerData(player);
            player.getMap().showMap(player.getName()+".dat");
        }

//加载游戏
    void loadGame();

//加载所有信息
    template <typename T>
    void loadData(T& creature){
            if constexpr (std::is_same_v<T, Player>) {
                LoadPlayerData(creature);
            } else if constexpr (std::is_same_v<T, Monster>) {
                LoadMonsterData(creature);
            } else {
                static_assert(std::is_base_of_v<Creature, T>, "没有相应数据");
                LoadCreatureData(creature, filename);
            }
        printMsg("Additional information or instructions after loading.", true);
    }
                                       //使用了  if constexpr 和 std::is_same_v 来检查模板参数 T 是否与 Player 或 Monster 相同。
                                       // 如果是，就调用相应的加载函数。如果都不是，使用 static_assert 来确保 T 是 Creature 的派生类，并调用基类的加载函数。

//控制输出信息
    void printMsg(string msgDir, bool singleLine = false, bool noCD = false) {
    if (!singleLine) {  // 如果不是单行输出
        cout << "按下 ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 设置文本颜色为红色
        cout << "[Tab键] ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置文本颜色为白色
        cout << "跳过本段..." << endl << endl;
    }
    ifstream msgFile(player.getName()+".dat");  // 打开消息文件
    string msg;
    int x, y;
    if (singleLine) {  // 如果是单行输出
        PosControl::getPos(x, y);  // 获取当前光标位置
    }
    int x1 = x, y1 = y;
    while (getline(msgFile, msg)) {  // 逐行读取文件
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置文本颜色为白色
        if (singleLine) {
            PosControl::setPos(x, y);  // 设置光标位置
            for (int i = x; i <= x1; i++) {  // 清除当前行内容
                cout << "\33[2K" << endl;
            }
            PosControl::setPos(x, y);  // 重新设置光标位置
        }
        bool flagTab = false;
        for (char c: msg) {  // 遍历消息中的每个字符
            if (c == '(') // 如果遇到'('，将文本颜色设置为灰色
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            else if (c == ')') {  // 如果遇到')'，恢复文本颜色为白色
                cout << c;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                continue;
            }
            cout << c;  // 输出字符
            if (!flagTab) Sleep(5);  // 延迟输出，模拟打字效果
            if (!noCD && kbhit()) {  // 检测按键，允许跳过输出
                char c;
                c = getch();
                if (c == '\t') {
                    flagTab = true;  // 如果按下Tab键，跳过本段
                }
            }
        }
        if (singleLine) {
            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            system("pause");
        }
        Sleep(100);  // 延迟
        PosControl::getPos(x1, y1);  // 获取光标位置
        // cout << "x1:" << x1 << ", y1:" << y1; //
        cout << endl;
    }
    msgFile.close();  // 关闭文件
}


//加载新的游戏
    void newGame(){
        system("cls");
        InitPlayerData(player);
        system("cls");
        loadGame();
    }

//加载游戏的函数实现
        void loadGame() {
          loadDataloadData(creature);
          Map::showMap(player.getName()+".dat");
          savePlayerData(player);
          goodbye();
          system("pause");
        }
}
#endif //ADVENTUREGAME_DATA_H
