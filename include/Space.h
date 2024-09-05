//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_SPACE_H
#define ADVENTUREGAME_SPACE_H
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "Item.h"
#include "Monster.h"
#include "fight.h"
#include "interface.h"

class Player;
/**
 * @class Space
 * @brief 代表地图上的单个空间，包含物品、怪物及其相互关系。
 */
class Space {
private:
    string name;                               ///< 空间的名称
    string description;                        ///< 空间的描述
    unordered_map<string, Item> items;         ///< 空间中包含的物品列表
    vector<Monster> monsters;                  ///< 空间中包含的怪物列表
    bool accessibility;                             ///< 是否可以通过此空间
    unordered_map<Space*, std::vector<Item>> towards; ///< 通往其他空间的条件物品
    //fight
public:
    // 构造函数
    Space(string name="Unnamed Space"): name(name), description("A space with nothing special."), accessibility(false) {}
    // 析构函数
    ~Space() {
        // 但可以显式清除 unordered_map 和 vector 的内容，尽管它们在析构时会自动清理
        items.clear();
        monsters.clear();
        towards.clear();
    }
    // todo 描述空间
    void describe() const {
        // todo
    }
    // 设置空间中的物品列表
    void setItems(const std::unordered_map<std::string, Item>& newItems) { items = newItems; }

    // 设置空间中的怪物列表
    void setMonsters(const std::vector<Monster>& newMonsters) { monsters = newMonsters; }

    // 设置通往其他空间的条件物品
    void setTowards(const std::unordered_map<Space*, std::vector<Item>>& newTowards) { towards = newTowards; }
    // 获取空间名称
    std::string getName() const { return name; }
    // 设置空间名字
    void setName(string name) { this->name = name; }
    // 获取空间中的物品列表
    unordered_map<string, Item> getItems() const { return items; }
    // 重载==运算符
    bool operator==(const Space& other) const { return name == other.name; }
    // 友元声明，以便std::hash可以访问私有成员
    friend struct std::hash<Space>;
    // 检查是否可以通过此空间
    inline bool getPass() const { return accessibility;}

    // 获取空间的详细信息 todo
    inline bool getInfo() const {
        describe();
        return true;
    }

    // 在空间内进行战斗 -> 调用fight.h中的函数 todo
    inline void fight() {
        if (monsters.empty()) {
            std::cout << "No monsters to fight in this space." << std::endl;
            return;
        }
        // 战斗逻辑
    }

    // 设置空间是否可以通过
    void setPass(bool pass) { accessibility = pass; }

    // 拾取空间中的物品
    Item pickUp(const std::string& name) {
       // todo
       auto it = items.find(name);
       if (it != items.end()) return it->second;
       else{
           cout << "这个物品不存在在这个空间" << endl;
           return {};
       }
    }

    // 展示空间中的怪兽状态，返回一个
    void showMonster(){
        for(int i=0; i<monsters.size(); i++){
            cout<< i+1 << ". ";
            monsters[i].printInfo();
        }
    }
};
// 在std命名空间中对std::hash进行特化
// std::hash 是标准库中提供的一个模板类，用于计算对象的哈希值。
// unordered_map 依赖于哈希值来存储和查找键值对，因此需要对键类型进行哈希化。
// 为了让自定义的 Space 类型可以作为 unordered_map 的键，我们需要为其提供哈希函数。
// 这就是通过对 std::hash<Space> 进行模板特化来实现的。
namespace std {
    // 特化 std::hash 模板以支持 Space 类型
    template<>
    struct hash<Space> {
        // 定义运算符()，这个运算符会返回一个 size_t 类型的哈希值
        // 这个函数会在需要哈希 Space 对象时被自动调用
        std::size_t operator()(const Space& s) const {
            // 使用 std::hash<std::string> 来哈希 Space 对象的 name 成员
            // 通过哈希 Space 对象的唯一名称来产生哈希值
            // 这样可以保证每个 Space 对象都可以得到一个唯一的哈希值（假设名称唯一）
            return std::hash<std::string>()(s.name);
        }
    };
}
#endif //ADVENTUREGAME_SPACE_H
