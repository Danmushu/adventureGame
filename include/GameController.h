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
 * @brief ��Ϸ����Ҫ�����������������Ϸ���������̡�
 */
class GameController {
private:
    Player& player;
    shared_ptr<Space> curSpace;

public:
    // ���캯��
    GameController(Player& player) : player(player), curSpace(nullptr) {
        // todo
        // ��ʼ������
    }

    // ��������
    ~GameController() {
        // �������
        curSpace.reset();
    }


    // ���ָ�����Ƶ������ļ��Ƿ����
    bool dataExist(const string &name) {
        string fileName = name + ".dat";  // ���������ļ�������
        string path = "../save/" + fileName;
        std::ifstream dataFile(path);  // ���Դ��ļ�
        bool isOpen = dataFile.is_open();  // ����ļ��Ƿ�ɹ���
        dataFile.close();  // �ر��ļ�
        return isOpen;  // �����ļ��Ƿ����
    }

    // ����������ݵ��ļ� todo
    void saveData() {
        // ���������ļ�������ļ��Ѵ����򸲸�
        std::ofstream dataFile("../save/" + player.getName() + ".dat", std::ios::trunc);
        // ������ҵ���Ҫ����
        dataFile << player.getLevel() << endl;
        dataFile << player.getMaxHp() << " " << player.getCurHp() << endl;
        dataFile << player.getRequiredMp() << " " << player.getMp() << endl;
        dataFile << player.getStr() << " " << player.getDef() << " " << player.getAgi() << endl;
        // ������Ҽ���
        dataFile << player.getSkillList().size() << endl; //��ü�������
        for(auto &i:player.getSkillList()){ dataFile << i.first << endl; }
        // ���������Ʒ��
        dataFile << player.getItemList().size() << endl; //�����Ʒ����
        for(auto &i:player.getItemList()) {dataFile << i.first << endl; }
        // todo
        // ������ҵ�λ��
        dataFile << curSpace->getName() << endl;// �����ڵ�λ��
        // ��������Щ�ռ�
        for(auto &i:player.getMap().getAcc())
            dataFile << i.first.getName() << " " << i.second << endl;
    }

    // todo ��ʼ���߼�����Ҫ����
    void init(){
        // todo
        if (dataExist(player.getName())) {  // ��������ļ�����
            cout << "�����Ѵ��ڣ��Ƿ��ȡ��" << endl;
            Menu isOrNo[2]{"��", "��"};  // �����˵�
            switch (switcher(isOrNo, 2)) {  // ��ʾ�˵�����ȡ�û�ѡ��
                case 0:  // ���ѡ���ǡ������˳���������������
                    return;
                case 1:  // ���ѡ�񡰷񡱣��򱣴浱ǰ����
                    saveData();
                    player.setLevel(1);
                    curSpace = player.getMap().getLocation();
            }
        } else {  // ��������ļ�������
            saveData();  // �����ʼ����
            player.setLevel(1);
            curSpace = player.getMap().getLocation();
        }
    }

    // ����������� todo
    void loadData() {
        string path = "../save/";
        if (dataExist(player.getName())) {  // ��������ļ�����
            std::ifstream dataFile(path + player.getName() + ".dat");  // ���ļ�
            // ������ҵ���Ҫ����
            int level, maxHp, curHp, maxMp, Mp, str, def, agi;
            dataFile >> level >> maxHp >> curHp;
            dataFile >> maxMp >> Mp;
            dataFile >> str >> def >> agi;
            player.setMainFeature(level, maxHp, curHp, maxMp, Mp, str, def, agi);
            // ������Ҽ���
            int numOfSkill;
            dataFile >> numOfSkill;
            while(numOfSkill--){
                // ��ȡ���ܵ��߼� todo
            }
            // ���������Ʒ�� todo
            int numOfItem;
            dataFile >> numOfItem;
            while(numOfItem--){
               // ��ȡ��Ʒ���߼� todo
               // todo ��item.txt

               }
            // �������λ�� todo
            string name;
            dataFile >> name;
            curSpace->setName(name);
            // todo �����ȡ��ͼ���߼�

        } else {  // ��������ļ�������
            system("cls");
            cout << "���ݲ����ڣ������´浵" << endl;
            saveData();  // �����ʼ����
            system("pause");
        }
    }

    // ����Ϸ todo
    void newGame() {
        system("cls");  // ����
        init();  // ��ʼ���������
        system("cls");  // �ٴ�����
        loadGame();  // ������Ϸ
    }

    // ������Ϸ
    void loadGame() {
        // todo
        loadData();  // �����������
        Map::printMap();  // ��ӡ��ͼ
        //onMap(player);  // todo �����ͼ�ϵ���Ϊ
        runGame();
        saveData();  // �����������
        goodbye();  // ��ʾ��Ϸ����ҳ��
        system("pause");  // ��ͣ���ȴ��û�����
    }

    // ������Ϸ
    void runGame() {
        // todo
        // ��Ϸѭ���Ĵ���
        curSpace->describe();
        Menu motion[]{
            "1.����", //�۲����״̬
            "2.��֮", //��������
            "3.��֮", //������һ����ͼ
            "4.����", //�ظ����ĺ���
            "5.��Ʒ"  //ʹ����Ʒ
        };
        while(true){
            player.printInfo();
            switch (switcher(motion, 5)) {
                case 0:
                    // todo �������״̬
                    curSpace->showMonster();
                    break;
                case 1:
                    // todo ����ѡ���Ĺ���,fight�߼�
                    fight();
                    break;
                case 2:
                    // todo ������ӵĵط�����ѡ��ȥ��
                    move();
                    break;
                case 3:
                    // todo �ظ�������
                    player.recovery();
                    break;
                case 4:
                    // todo ʹ����Ʒ���߼�
                    break;
            }
        }
    }

    // ��������
    void handleInput() {
        // todo
        // �����û�����Ĵ���
    }

    // �ƶ�
    void move() {
        // todo
        // �ƶ���ҵĴ���
    }

    // ����Ʒ
    void pickUp(string name){
        Item item = curSpace->pickUp(name);
        // ���item = {}
        if (!item.getName().empty()){ cout << "û����������Ϊ����Ʒ������"; }
        else{
            cout << "�ɹ�������" << item.getName() << endl;
            player.addItem(item);
        }
    }
    // ս��
    void fight() {
        // todo
        // ս���߼��Ĵ���
    }

    // ������Ϸ
    void saveGame() {
        // todo
        // ������Ϸ״̬�Ĵ���
    }

    // ��ʾ��Ϸ����ҳ��
    void goodbye() {
        system("cls");  // �������̨����
        ifstream creditsLogoFile("../assets/.endLogo");  // �򿪽���Logo�ļ�
        string logo;
        while (getline(creditsLogoFile, logo)) {  // ���ж�ȡ�ļ�
            cout << logo << endl;
            Sleep(randInt(20, 50));  // �ӳ����
        }
        creditsLogoFile.close();
        ifstream creditsFile("../assets/.endPage");  // �򿪽�����Ϣ�ļ�
        string credits;
        while (getline(creditsFile, credits)) {  // ���ж�ȡ�ļ�
            cout << credits << endl;
            Sleep(randInt(20, 50));  // �ӳ����
        }
        creditsFile.close();
    }

    // todo �����switcher���
    bool main_showGameOverMenu(GameController& game) {
        std::cout << "Game Over!" << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "0. Restart Game" << std::endl;
        std::cout << "1. Exit Game" << std::endl;

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            // ����Ƿ�����
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            return false; // Ĭ���˳���Ϸ
        } else {
            switch (switcher(gameOverMenu, 2)) {
                case 0:
                    // ������ѡ���ˡ�����Ϸ��������������Ϸ
                    game.newGame();
                    game.runGame();
                    return true;
                    break;
                case 1:
                    // ������ѡ���ˡ��˳���Ϸ��������ʾ�˳�ҳ�棬���˳�����
                    goodbye();
                    system("pause");  // ��ͣ�ȴ��û�����
                    return false;
                default:;
            }
        }
    }

    // todo ������Ϸ ��κϲ�
    void runGame() {

        // ��Ϸ��ѭ��
        bool isRunning = true;

        while (isRunning) {
            // ��ʾ��ǰ�ռ���Ϣ
            currentSpace->describe();

            // ��ʾ��ҿ�ѡ�Ĳ���
            std::cout << "Choose an action:" << std::endl;
            std::cout << "1. Move to another space" << std::endl;
            std::cout << "2. Exit game" << std::endl;

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    // �ƶ�����һ���ռ�
                    move();
                    break;
                case 2:
                    // �˳���Ϸ
                    isRunning = false;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;

                    break;
            }

            // �������Ƿ�ʧ��
            if (player.isDead()) {
                // ��ʾ��Ϸ�����˵�
                if (main_showGameOverMenu(*this)) {
                    // ���¿�ʼ��Ϸ
                    newGame();
                } else {
                    // �˳���Ϸ
                    isRunning = false;
                }
            }
        }
    }
};
#endif //ADVENTUREGAME_GAMECONTROLLER_H
