# 项目简介
- 你是一个探险者，在过往的冒险中，你获得了一张地图和一块玉石，在玉石的影响下，你觉醒了"气"。
- 地图中的世界叫海中大国，快去冒险吧

# 文件结构
```markdown
project_root/
├── assets/               # 游戏资源文件
│   ├── images/           # 存放图片资源
│   ├── sounds/           # 存放音频资源
│   ├── data/             # 存放其他游戏资源，如地图数据等
├── include/              # 头文件
│   ├── common.h          # 系统头文件
│   ├── creature/         # 生物基类的头文件
│   │   ├── Creature.h
│   ├── player/           # 玩家相关的头文件
│   │   ├── Player.h
│   │   ├── PlayerController.h
│   │   ├── PlayerView.h
│   ├── monster/          # 怪物相关的头文件
│   │   ├── Monster.h
│   │   ├── MonsterController.h
│   │   ├── MonsterView.h
│   ├── battle/           # 战斗相关的头文件
│   │   ├── FightController.h
│   │   ├── FightView.h
│   ├── item/             # 物品及子类的头文件
│   │   ├── Item.h
│   │   ├── Skill.h
│   │   ├── Weapon.h
│   │   ├── Medicine.h
│   │   ├── Special.h
│   ├── map/              # 地图相关的头文件
│   │   ├── Map.h
│   ├── game/             # 游戏整体控制的头文件
│   │    ├── GameController.h
│   └── tool/             # 工具库
│       ├── data.h
├── src/                  # 源文件
│   ├── creature/         # 生物基类的源文件
│   │   ├── Creature.cpp
│   ├── player/           # 玩家相关的源文件
│   │   ├── Player.cpp
│   │   ├── PlayerController.cpp
│   │   ├── PlayerView.cpp
│   ├── monster/          # 怪物相关的源文件
│   │   ├── Monster.cpp
│   │   ├── MonsterController.cpp
│   │   ├── MonsterView.cpp
│   ├── battle/           # 战斗相关的源文件
│   │   ├── FightController.cpp
│   │   ├── FightView.cpp
│   ├── item/             # 物品及子类的源文件
│   │   ├── Item.cpp
│   │   ├── Skill.cpp
│   │   ├── Weapon.cpp
│   │   ├── Medicine.cpp
│   │   ├── Special.cpp
│   ├── map/              # 地图相关的源文件
│   │   ├── Map.cpp
│   ├── main.cpp          # 主程序入口
│   ├── GameController.cpp # 游戏整体控制的实现
├── save/                 # 游戏存档文件
│   ├── savegame1.dat
│   ├── savegame2.dat
```


# UML类图


