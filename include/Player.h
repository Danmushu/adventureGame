//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_PLAYER_H
#define ADVENTUREGAME_PLAYER_H
#pragma once

#include "Creature.h"
#include "Map.h"
#include <string>
#include <unistd.h>

class Player : public Creature {
private:
    int requiredMp;//��ǰ�������������Ҳ�ǵȼ��ı߽���
    int mp;//��
    Map map;

public:
    // Ĭ�Ϲ��캯��
    Player() : Creature(), requiredMp(100), mp(100), map() {
        Skill fire("������", 0, 0, 0, 0, 10, 5);
        addSkill("������", fire);
    }
    // �������Ĺ��캯��
    Player(std::string name) : Creature(name), requiredMp(100), mp(100), map() {}
    // ��������
    ~Player() override = default;
    // ��ȡ��ͼ
    Map getMap() const { return map; }
    // ��ȡ���λ�ã����������һ������ͨ�������getMap()������ͬ��ֵ��
    Map getLastPos() const { return map; }
    // ��ȡ��ǰλ�õ�����
    Map& getPos() { return map; }
    // ��ȡ��ֵ
    int getMp() const { return mp; }
    // ��ȡ������������Ҫ������
    int getRequiredMp() const { return requiredMp; }
    // ��ӡ�����б�
    void printSkillList() const {
        // �����Ҽ����б�
        int id = 1;
        // ����б�������һ������
        for(auto &i:skills){
            cout << id << i.first <<": " << i.second.getDes() << endl;
            id++;
        }
    }
    // ��ӡ��Ʒ�б�
    void printItemList() const {
        // ��������Ʒ�б�
        // may be empty
        if(inventory.empty()){
            cout << "ֻ��һ���տ���Ҳ�ı���" <<  endl;
            return;
        }
        int id = 0;
        for(auto &i:inventory){
           cout << id << i.first <<": "  << i.second.getDes() << endl;
           id ++;
        }

    }
    // ��ӡ�����Ϣ
    void printInfo() const {
        // ��������Ϣ
        cout << "[��]" << level << endl;
        cout << "[Ѫ]   " << curHP << "/" << maxHP << endl;
        cout << "[��]   " << mp << endl;
        cout << "[��]" << strength <<  "\t";
        cout << "[��] " << defense << "\t";
        cout << "[��] " << agility << "\t";
        printSkillList();
        printItemList();
    }
    // ������
    void setMp(int mp) { this->mp = mp; }
    // ������Ҫ����
    void setMainFeature(int level, int maxHp, int curHp, int maxMp, int Mp, int str, int def, int agi)
    {
        setLevel(level);
        setMaxHp(maxHp);
        setCurHp(curHp);
        setRequiredMp(maxMp);
        setStr(str);
        setDef(def);
        setAgi(agi);
    }
    //������������
    void setRequiredMp(int maxMp){ this->requiredMp = maxMp; }
    // ʹ����Ʒ
    void useItem(std::string name) {
        // ʹ����Ʒ�߼�
        // �õ���������
        auto it = inventory.find(name);
        if (it == inventory.end()) {
            cout << "����û�������Ʒ��" << endl;
        }else{
            agility += it->second.getAgi();
            strength += it->second.getAtk();
            defense += it->second.getDef();
            mp += it->second.getMp();
            // �ظ����ܳ����������ֵ
            if(curHP+it->second.getRec()<= maxHP) curHP += it->second.getRec();
            else curHP = maxHP;
        }
        // ���궪��
        inventory.erase(it->first);
    }
    // ������Ʒ
    void dropItem(std::string name) {
        // ������Ʒ�߼�
        // find the item
        auto it = inventory.find(name);
        if (it != inventory.end()) inventory.erase(it->first);
        else cout << "����û�������Ʒ! " << endl;
    }
    // �ظ���
    void recovery(){
        cout << "�ظ���:";
        int t = 3;
        mp = requiredMp;
        for (int i = 0; i < t; ++i) {
            sleep(t);
            cout<<"***"<<endl;
            cout<<" \b \b \b";
        }
        system("cls");
        cout << "���������" << endl;
    }
    // ʹ�ü���->Ӧ��Ҫд��fight��
    // todo
    void useSkill(string name) {
        auto it = skills.find(name);
        if (it != skills.end()){
            Skill skill = it->second;
            if (skill.getMp() + mp < 0){ cout << "�����㣬�޷��ͷŸ���" <<endl;}
            else{
                mp -= skill.getMp();
                //
            }
        }
    }


    /*** �μ��� ***/
    // ��������
    void attack(Creature& target) {
        // �򻯴���ÿ�ι������ٹ̶�������ֵ
        int strength = getStr();  // ��������ֵ��Ϊ������
        target.setCurHp(target.getCurHp() - strength);
        cout << "������� " << strength << " ��������" << endl;
    }

    void reset() {
        // ���û�������
        level = 1;  // �����ʼ�ȼ�Ϊ 1
        curHP = maxHP = 100;  // �����ʼѪ��Ϊ 100
        strength = 10;  // �����ʼ����Ϊ 10
        defense = 10;  // �����ʼ����Ϊ 10
        agility = 10;  // �����ʼ����Ϊ 10

        // ������ֵ
        mp = requiredMp = 100;  // �����ʼ��ֵΪ 100

        // ��ռ����б�
        skills.clear();

        // �����Ʒ�б�
        inventory.clear();

        // ���õ�ͼλ��
        map.reset();
    }
    // ���û�������
    void resetStats() override {
        curHP = maxHP;  // ���õ�ǰ����ֵ
        mp = requiredMp;  // ������ֵ
    }
    void setProgress(int progress) {
        map.setProgress(progress);  // ���� Map ��� setProgress ����
    }
};
};

#endif //ADVENTUREGAME_PLAYER_H
