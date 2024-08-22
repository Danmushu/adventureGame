# adventureGame
OUC cpp project
# file structure
```javascript
/MUDGame
│
├── src
│   ├── main.cpp          // 主程序入口
│   ├── Player.h          // 玩家类头文件
│   ├── Player.cpp        // 玩家类实现
│   ├── Map.h             // 地图类头文件
│   ├── Map.cpp           // 地图类实现
│   ├── Monster.h         // 怪物类头文件
│   ├── Monster.cpp       // 怪物类实现
│   ├── Item.h            // 物品类头文件
│   ├── Item.cpp          // 物品类实现
│   ├── Puzzle.h          // 解密类头文件
│   ├── Puzzle.cpp        // 解密类实现
│   ├── Battle.h          // 战斗类头文件
│   ├── Battle.cpp        // 战斗类实现
│   ├── UI.h              // 界面绘制类头文件
│   ├── UI.cpp            // 界面绘制类实现
│   ├── SaveLoad.h        // 存档加载类头文件
│   ├── SaveLoad.cpp      // 存档加载类实现
│
├── assets                // 资源文件夹
│   ├── game_save.txt     // 游戏存档文件
│
└── README.md             // 项目说明文件
```
# Some statment

            item                                         creature                                   window  
        |               |                             |             |                              |        |    
    weapon              drug                        player          monster                        map      puzzle
  |     |           |       |       |                              |        |                   |           
sword   shield      health  attack  special                        boss     demon          level(1-3)  