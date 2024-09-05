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

//����ļ�����
    bool dataExist(const string &name) {
        string fileName = name + ".dat";
        std::ifstream dataFile(fileName);
        bool isOpen = dataFile.is_open();
        dataFile.close();
        return isOpen;
    }

//����Creature�����ݣ���Ϊ�������ݱ���
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
            std::cerr << "�޷���ȡ�ļ�" << std::endl;
        }
    }                                                           //����ֱ�ӵ�����

//�������������ݣ���Ϊ���� ��������
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
            std::cerr << "�����޷���ȡ" << std::endl;
        }
    }

//�����������
    void savePlayerData(Player& player) {
      saveCreatureData(player,player.getName()+".dat");
      std::ofstream file(player.getName()+".dat", std::ios::trunc);
      file << player.getPos().line << ' ' << player.getPos().column << endl;
    }                                                          //���û��ౣ�溯��,������Լ�һЩPlayer���е��߼�

//�����������
    void loadPlayerData(Creature& player) {
      loadCreatureData(player,player.getName()+".dat");
      std::ifstream file(player.getName() + ".dat");
      int line,column;
      file >> line >> column;
    }                                                           //���û�����غ�����������Լ�һЩPlayer �����е��߼�

//���������
    void saveMonsterData(Monster& monster) {
      saveCreatureData(monster,monster.getName()+".dat");         //������һ������������������ò���
    }

//���ع�������
    void loadMonsterData(Monster& monster) {
      loadCreatureData(monster,monster.getName()+".dat");           //���û�����غ���������Ҫ��һЩMonster���е��߼�
    }

//��ʼ���������
    void InitPlayerData(Player& player) {
        if (dataExist(player.getName())) {                                                               // ����ļ��������ȡ
            cout << "�����Ѵ��ڣ��Ƿ��ȡ��" << endl;
            Menu menu[2]{
                "��","��"
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

//������Ϸ
    void loadGame();

//����������Ϣ
    template <typename T>
    void loadData(T& creature){
            if constexpr (std::is_same_v<T, Player>) {
                LoadPlayerData(creature);
            } else if constexpr (std::is_same_v<T, Monster>) {
                LoadMonsterData(creature);
            } else {
                static_assert(std::is_base_of_v<Creature, T>, "û����Ӧ����");
                LoadCreatureData(creature, filename);
            }
        printMsg("Additional information or instructions after loading.", true);
    }
                                       //ʹ����  if constexpr �� std::is_same_v �����ģ����� T �Ƿ��� Player �� Monster ��ͬ��
                                       // ����ǣ��͵�����Ӧ�ļ��غ�������������ǣ�ʹ�� static_assert ��ȷ�� T �� Creature �������࣬�����û���ļ��غ�����

//���������Ϣ
    void printMsg(string msgDir, bool singleLine = false, bool noCD = false) {
    if (!singleLine) {  // ������ǵ������
        cout << "���� ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // �����ı���ɫΪ��ɫ
        cout << "[Tab��] ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �����ı���ɫΪ��ɫ
        cout << "��������..." << endl << endl;
    }
    ifstream msgFile(player.getName()+".dat");  // ����Ϣ�ļ�
    string msg;
    int x, y;
    if (singleLine) {  // ����ǵ������
        PosControl::getPos(x, y);  // ��ȡ��ǰ���λ��
    }
    int x1 = x, y1 = y;
    while (getline(msgFile, msg)) {  // ���ж�ȡ�ļ�
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �����ı���ɫΪ��ɫ
        if (singleLine) {
            PosControl::setPos(x, y);  // ���ù��λ��
            for (int i = x; i <= x1; i++) {  // �����ǰ������
                cout << "\33[2K" << endl;
            }
            PosControl::setPos(x, y);  // �������ù��λ��
        }
        bool flagTab = false;
        for (char c: msg) {  // ������Ϣ�е�ÿ���ַ�
            if (c == '(') // �������'('�����ı���ɫ����Ϊ��ɫ
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            else if (c == ')') {  // �������')'���ָ��ı���ɫΪ��ɫ
                cout << c;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                continue;
            }
            cout << c;  // ����ַ�
            if (!flagTab) Sleep(5);  // �ӳ������ģ�����Ч��
            if (!noCD && kbhit()) {  // ��ⰴ���������������
                char c;
                c = getch();
                if (c == '\t') {
                    flagTab = true;  // �������Tab������������
                }
            }
        }
        if (singleLine) {
            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            system("pause");
        }
        Sleep(100);  // �ӳ�
        PosControl::getPos(x1, y1);  // ��ȡ���λ��
        // cout << "x1:" << x1 << ", y1:" << y1; //
        cout << endl;
    }
    msgFile.close();  // �ر��ļ�
}


//�����µ���Ϸ
    void newGame(){
        system("cls");
        InitPlayerData(player);
        system("cls");
        loadGame();
    }

//������Ϸ�ĺ���ʵ��
        void loadGame() {
          loadDataloadData(creature);
          Map::showMap(player.getName()+".dat");
          savePlayerData(player);
          goodbye();
          system("pause");
        }
}
#endif //ADVENTUREGAME_DATA_H
