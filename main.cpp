//
// Created by Danmu on 2024/8/22.
//
#include "include/common.h"
#include "include/GameController.h"
#include "include/interface.h"
#include "include/Player.h"

using namespace std;

int main()
{

    //game.openningPage();
    //welcomePage();
    int x, y; //用于存储光标位置
    string name; //玩家姓名
    //获取光标位置
    PosControl::getPos(x, y);
    // 设置光标位置到当前行的起始位置 todo
    PosControl::setPos(x, 0);
    //清除当前行内容
    cout << "\33[2K";
    // 玩家输入名字
    cout <<  "请输入你的名字: ";
    cin >> name;
    // 验证玩家输入的名字是否合法
    while (name.length() > 15 || name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") != string::npos) {
        // 如果名字不合法，重新设置光标并提示玩家重新输入
        PosControl::setPos(x, 0);
        // 清除当前行内容
        cout << "\33[2K" << endl;
        // 检查名字是否包含非法字符或名字长度是否超过15个字符
        if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") != string::npos) {
            // 如果包含非法字符，提示玩家重新输入合法名字
            cout << "名字中含有非法字符，请重新输入：";
        } else {
            // 如果名字过长，提示玩家重新输入短一点的名字
            cout << "名字过长，请重新输入：";
        }
        cin >> name;  // 重新获取玩家输入的名字
    }

    // 清除输入提示行
    PosControl::setPos(x, 0);

    // 使用玩家输入的名字创建一个 Player 对象
    Player player(name);
    // 开始界面函数
    GameController game(player);

    // 向玩家打招呼并显示其名字
    cout << "    你好，名为 ";
    // 将文字颜色设置为黄色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    cout << name;
    // 恢复文字颜色为默认值（白色）
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << " 的探险者" << endl;

    // 输出两行空行，视觉上清理输出区域
    string spaceLine(100, ' ');
    cout << spaceLine << endl << spaceLine << endl
         << spaceLine << endl << spaceLine << endl;

    // todo
    /********* 游戏真正开始 *********/
    // 调用 switcher 函数显示主菜单，并根据玩家选择执行相应的操作
    switch (switcher(menu, 3)) {
        case 0:
            // 如果玩家选择了“新游戏”，则启动新游戏
                game.newGame();
        break;
        case 1:
            // 如果玩家选择了“加载游戏”，则加载游戏数据
                game.loadGame();
        break;
        case 2:
            // 如果玩家选择了“退出游戏”，则显示退出页面，并退出程序
                goodbye();
                system("pause");  // 暂停等待用户按键
        return 0;  // 退出程序
        default: ;
    }



    return 0;
}
