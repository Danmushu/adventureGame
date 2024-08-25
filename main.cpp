//
// Created by Danmu on 2024/8/22.
//
#include <iostream>
#include <common.h>

using namespace std;

int main(){
    //颜色编码 color code
    int colorCode =32;

    //游戏名称 Game Name
    string gameName = "";//todo

    //打印初始游戏界面 print the openning menu of the game
    cout<<"\n";
    cout << "\t\t\t\t\t" << "\033[1;" << colorCode << "m";  // 设置文本颜色为绿色

    // 逐行打印大号的游戏名字
    cout << endl << "    ******   *********    *****   *********  ***  *****   ******     ******  " << endl;
    cout << "  **    **     **    **   **   **     **     ***   **   **  **    **   **    **" << endl;
    cout << " **            **    **  **     **    **     ** ** **   **  **         **      " << endl;
    cout << " **            **    **  **     **    **     **  ****   **  **         **      " << endl;
    cout << " **            **    **  **     **    **     **   ***   **  **   ****  **       " << endl;
    cout << "  **    **     **    **   **   **     **     **    **   **   **    **   **    **" << endl;
    cout << "    ******   *********    *****       **     **    **   **    ******     ******  " << endl;

    cout << "\033[0m";  // 重置文本颜色
    cout << "\n\n";

    system("pause");
    system("cls");

    //故事背景
    string background = "";//todo

    for (int i = 0; i < background.size(); i++) {
        cout << background[i];
        Sleep(10);
    }
    cout << endl;

    system("pause");
    system("cls");

    Game game;
}