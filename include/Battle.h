//
// Created by Danmu on 2024/9/5.
//

#ifndef ADVENTUREGAME_BATTLE_H
#define ADVENTUREGAME_BATTLE_H
#pragma once

/**
 * @class Battle
 * @brief ��ʾ��Ϸ�е�ս���߼���
 * */

#include "Monster.h"
#include "Player.h"
#include "interface.h"

class Battle {
private:
    Player& player;         ///< ��Ҷ���
    Monster& monster;       ///< �������
    bool isGameOver;        ///< ��Ϸ�Ƿ����

public:
    Battle(Player& player, Monster& monster) : player(player), monster(monster), isGameOver(false) {}

    // ��ʼս��
    void startBattle() {
        std::cout << "ս����ʼ��" << std::endl;
        // ��ʼ��ս����������������ֵ��
//        player.resetStats();
//        monster.resetStats();
        handleTurn();
        finalizeBattle();
    }

    // ����ս���غ�
    void handleTurn() {
        while (player.isDead() && monster.isDead()) {
            handlePlayerTurn();
            handleMonsterTurn();
        }
    }

    // ����������� turn=1->player atk else monster atk
    void handleAtk(bool turn){

    }

    // ������һغ�
    void handlePlayerTurn() {
        Menu motion[]{
            "������",
            "��������",
            "��Ʒ����"
        };
        switch (switcher(motion, 3)) {
            case 0:
                player.attack(monster);
                std::cout << "Player attacks the monster." << std::endl;
                break;
            case 1:
                player.printSkillList();
                std::cout << "Player defends." << std::endl;
                break;
            case 2:
                player.useItem();
                std::cout << "Player uses an item." << std::endl;
                break;
        }
    }

    // �������غ�
    void handleMonsterTurn() {
        std::cout << "Monster's turn." << std::endl;
        int choice = monster.getChoice();
        switch (choice) {
            case 1:
                monster.attack(player);
                std::cout << "Monster attacks the player." << std::endl;
                break;
            case 2:
                monster.defend();
                std::cout << "Monster defends." << std::endl;
                break;
            default:
                std::cout << "Monster does nothing." << std::endl;
                break;
        }
    }

    // �ж�ս���Ƿ����
    bool isBattleOver() {
        if (player.isDead()) {
            isGameOver = true;
            return true;
        } else if (monster.isDead()) {
            isGameOver = true;
            return true;
        }
        return false;
    }

    // ս�����������β����
    void finalizeBattle() {
        if (monster.isDead()) {
            cout << "ս��ʤ����" << endl;
        } else if (player.isDead()) {
            cout << "ս��ʧ�ܣ�����Ҫ������" << endl;
        }
    }
};
#endif //ADVENTUREGAME_BATTLE_H
