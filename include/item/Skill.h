//
// Created by Danmu on 2024/8/29.
//

#ifndef ADVENTUREGAME_SKILL_H
#define ADVENTUREGAME_SKILL_H
#pragma once

#include <string>

/**
 * @class Skill
 * @brief 代表游戏中的技能。技能可以为玩家或怪物提供特殊能力。
 */
class Skill {
protected:
    //todo
    std::string type; ///< 技能类型

public:
    Skill();
    Skill(std::string type);
    virtual ~Skill() {}

    // 获取和设置技能类型的方法
    std::string getType() const;
    void setType(std::string type);
};

// Skill 类的实现
Skill::Skill() : type("") {}

Skill::Skill(std::string type) : type(type) {}

std::string Skill::getType() const { return type; }

void Skill::setType(std::string type) { this->type = type; }

#endif //ADVENTUREGAME_SKILL_H
