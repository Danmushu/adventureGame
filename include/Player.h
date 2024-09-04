//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_PLAYER_H
#define ADVENTUREGAME_PLAYER_H
#pragma once

#include "Creature.h"
#include "map.h"
#include <string>
#include <unistd.h>

class Player : public Creature {
private:
    int requiredMp;//当前境界最大气量，也是等级的边界线
    int mp;//气
    Map map;

public:
    // 默认构造函数
    Player() : Creature(), requiredMp(100), mp(100), map() {}
    // 带参数的构造函数
    Player(std::string name) : Creature(name), requiredMp(100), mp(100), map() {}
    // 析构函数
    ~Player() override = default;
    // 获取地图
    Map getMap() const { return map; }
    // 获取最后位置（这里可能是一个错误，通常不会和getMap()返回相同的值）
    Map getLastPos() const { return map; }
    // 获取当前位置的引用
    Map& getPos() { return map; }
    // 获取气值
    int getMp() const { return mp; }
    // 获取提升境界所需要的气量
    int getRequiredMp() const { return requiredMp; }
    // 打印技能列表
    void printSkillList() const {
        // 输出玩家技能列表
        int id = 1;
        // 玩家列表至少有一个技能
        for(auto &i:skills){
            cout << id << i.first <<": " << i.second.getDes() << endl;
            id++;
        }
    }
    // 打印物品列表
    void printItemList() const {
        // 输出玩家物品列表
        // may be empty
        if(inventory.empty()){
            cout << "只有一个空空如也的背包" <<  endl;
            return;
        }
        int id = 0;
        for(auto &i:inventory){
           cout << id << i.first <<": "  << i.second.getDes() << endl;
           id ++;
        }

    }
    // 打印玩家信息
    void printInfo() const {
        // 输出玩家信息
        cout << "[境]" << level << endl;
        cout << "[血]   " << curHP << "/" << maxHP << endl;
        cout << "[气]   " << mp << endl;
        cout << "[力]" << strength <<  "\t";
        cout << "[御] " << defense << "\t";
        cout << "[敏] " << agility << "\t";
        printSkillList();
        printItemList();
    }
    // 设置气
    void setMp(int mp) { this->mp = mp; }
    // 设置主要属性
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
    //设置气上限量
    void setRequiredMp(int maxMp){ this->requiredMp = maxMp; }
    // 使用物品
    void useItem(std::string name) {
        // 使用物品逻辑
        // 用迭代器查找
        auto it = inventory.find(name);
        if (it == inventory.end()) {
            cout << "包里没有这个物品！" << endl;
        }else{
            agility += it->second.getAgi();
            strength += it->second.getAtk();
            defense += it->second.getDef();
            mp += it->second.getMp();
            // 回复不能超过最大生命值
            if(curHP+it->second.getRec()<= maxHP) curHP += it->second.getRec();
            else curHP = maxHP;
        }
        // 用完丢弃
        inventory.erase(it->first);
    }
    // 丢弃物品
    void dropItem(std::string name) {
        // 丢弃物品逻辑
        // find the item
        auto it = inventory.find(name);
        if (it != inventory.end()) inventory.erase(it->first);
        else cout << "包里没有这个物品! " << endl;
    }
    // 回复气
    void recovery(){
        cout << "回复中:";
        int t = 3;
        mp = requiredMp;
        for (int i = 0; i < t; ++i) {
            sleep(t);
            cout<<"***"<<endl;
            cout<<" \b \b \b";
        }
        system("cls");
        cout << "精神焕发！" << endl;
    }
    // 使用技能->应该要写在fight中
    // todo
    void useSkill(string name) {
        auto it = skills.find(name);
        if (it != skills.end()){
            Skill skill = it->second;
            if (skill.getMp() + mp < 0){ cout << "气不足，无法释放该术" <<endl;}
            else{
                mp -= skill.getMp();
                //
            }
        }
    }
};

#endif //ADVENTUREGAME_PLAYER_H
