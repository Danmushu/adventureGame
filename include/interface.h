//
// Created by Danmu on 2024/8/30.
//

#ifndef ADVENTUREGAME_INTERFACE_H
#define ADVENTUREGAME_INTERFACE_H

#include <ctime>   // 包含处理时间相关的库
//#include "Monster.h"   // 用于怪物相关功能，暂时未使用
#include <vector>   // 包含处理向量（动态数组）的库
#include <iostream> // 包含输入输出流的库
#include <string>   // 包含处理字符串的库
#include <fstream>  // 包含文件输入输出的库
#include <windows.h> // 包含Windows API函数的库
#include <conio.h>  // 包含控制台输入输出的库，用于检测按键
#include <random>   // 包含随机数生成的库
//#include "utils\\rand.h" // 自定义的随机数生成器头文件，暂时未使用

using namespace std; // 使用标准命名空间，以简化代码书写

// 定义菜单结构体，用于存储菜单项名称
struct Menu {
    string name;  // 菜单项名称
};

// 定义游戏主菜单的选项
Menu menu[3]{
        "新游戏",  // 新游戏选项
        "加载游戏",  // 加载游戏选项
        "退出游戏"  // 退出游戏选项
};

// 定义命名空间PosControl，用于控制控制台窗口的位置和光标的操作
namespace PosControl {

    // 获取屏幕的宽度和高度
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);

    // 定义窗口的宽度和高度
    struct Size {
        int width;  // 窗口宽度
        int height; // 窗口高度
    } size = {1020, 1020};  // 初始化窗口大小

    // 将窗口居中显示
    void centerWindow() {
        HWND hwnd = GetForegroundWindow();  // 获取当前窗口句柄
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, size.width, size.height, 1);  // 设置窗口大小
        MoveWindow(hwnd, (screen_width - size.width) / 2, (screen_height - size.height) / 2, size.width, size.height,
                   1);  // 将窗口移动到屏幕中央
    }

    // 将光标移动到指定的控制台坐标位置
    void setPos(int x, int y) {
        COORD coord{static_cast<SHORT>(y), static_cast<SHORT>(x)};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  //回到给定的坐标位置进行重新输出
    }

    // 获取当前光标的坐标位置
    void getPos(int &x, int &y) {
        CONSOLE_SCREEN_BUFFER_INFO b;           // 包含控制台屏幕缓冲区的信息
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &b);    // 获取标准输出句柄
        y = b.dwCursorPosition.X;  // 获取光标的X坐标
        x = b.dwCursorPosition.Y;  // 获取光标的Y坐标
    }

    // 隐藏控制台光标
    void HideCursor() {
        CONSOLE_CURSOR_INFO cursor;
        cursor.bVisible = FALSE;  // 将光标设置为不可见
        cursor.dwSize = sizeof(cursor);
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取标准输出句柄
        SetConsoleCursorInfo(handle, &cursor);  // 设置控制台光标信息
    }
}

// 生成指定范围内的随机整数
int randInt(int min, int max) {
    std::random_device rd;  // 获取硬件随机数生成器
    std::mt19937 gen(rd());  // 使用Mersenne Twister算法生成随机数
    std::uniform_int_distribution<> dis(min, max);  // 定义均匀分布
    return dis(gen);  // 返回生成的随机数
}

// 在控制台中输出指定文件中的消息
void printMsg(string msgDir, bool singleLine = false, bool noCD = false) {
    if (!singleLine) {  // 如果不是单行输出
        cout << "按下 ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 设置文本颜色为红色
        cout << "[Tab键] ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置文本颜色为白色
        cout << "跳过本段..." << endl << endl;
    }
    ifstream msgFile(msgDir);  // 打开消息文件
    string msg;
    int x, y;
    if (singleLine) {  // 如果是单行输出
        PosControl::getPos(x, y);  // 获取当前光标位置
    }
    int x1 = x, y1 = y;
    while (getline(msgFile, msg)) {  // 逐行读取文件
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置文本颜色为白色
        if (singleLine) {
            PosControl::setPos(x, y);  // 设置光标位置
            for (int i = x; i <= x1; i++) {  // 清除当前行内容
                cout << "\33[2K" << endl;
            }
            PosControl::setPos(x, y);  // 重新设置光标位置
        }
        bool flagTab = false;
        for (char c: msg) {  // 遍历消息中的每个字符
            if (c == '(') // 如果遇到'('，将文本颜色设置为灰色
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            else if (c == ')') {  // 如果遇到')'，恢复文本颜色为白色
                cout << c;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                continue;
            }
            cout << c;  // 输出字符
            if (!flagTab) Sleep(5);  // 延迟输出，模拟打字效果
            if (!noCD && kbhit()) {  // 检测按键，允许跳过输出
                char c;
                c = getch();
                if (c == '\t') {
                    flagTab = true;  // 如果按下Tab键，跳过本段
                }
            }
        }
        if (singleLine) {
            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            system("pause");
        }
        Sleep(100);  // 延迟
        PosControl::getPos(x1, y1);  // 获取光标位置
        // cout << "x1:" << x1 << ", y1:" << y1; //
        cout << endl;
    }
    msgFile.close();  // 关闭文件
}

// 显示游戏欢迎页面
void welcomePage() {

    // 将窗口居中显示，并隐藏光标
    PosControl::centerWindow();  // 使用窗口管理函数将控制台窗口居中显示
    PosControl::HideCursor();  // 隐藏控制台光标，以提高用户体验

    // 输出初始分割线，用于提示用户调整控制台字体大小
    cout << "==================================================================================================="
         << endl;

    // 提示用户如何调整字体大小
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置文本颜色为白色
    cout << endl << "    请使用 ";  // 输出提示信息
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 设置文本颜色为红色
    cout << "[Ctrl] ";  // 提示用户按住Ctrl键
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 恢复文本颜色为白色
    cout << "+ ";  // 输出加号
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 设置文本颜色为红色
    cout << "滚轮 ";  // 提示用户滚动鼠标滚轮
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 恢复文本颜色为白色
    cout << "调整控制台字体大小，确保以上分割线显示在同一行。"
         << endl;

    // 提示用户按下Enter键继续
    cout << endl << "按下 ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 设置文本颜色为红色
    cout << "[Enter键] ";  // 提示用户按下Enter键
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 恢复文本颜色为白色
    cout << "继续..." << endl;

    // 等待用户按下Enter键以继续
    while (true) {  // 无限循环，直到用户按下Enter键
        if (kbhit()) {  // 检测是否有按键按下
            char c;
            c = getch();  // 获取按下的键
            if (c == '\r' || c == '\n') {  // 如果按下Enter键（ASCII码是\r或\n）
                PosControl::setPos(0, 0);  // 将光标移动到控制台的(0, 0)位置，准备清除屏幕内容
                //system("cls");
                // 清除控制台输出的五行空白行，使控制台看起来像被清屏
                cout << string(104, ' ') << endl;
                cout << string(104, ' ') << endl;
                cout << string(104, ' ') << endl;
                cout << string(104, ' ') << endl;
                cout << string(104, ' ') << endl;
                PosControl::setPos(0, 0);  // 再次将光标移动到(0, 0)位置，准备显示新的内容
                break;  // 退出循环，继续执行接下来的代码
            }
        }
    }

    // 输出欢迎页面的文本内容，从文件 "../assets/scene/startPage.txt" 中读取并显示
    printMsg("../assets/scene/startPage.txt");  // 调用函数输出开始页面的消息，允许用户通过Tab键跳过

    // 显示加载进度条
    cout << endl << endl;
    for (int i = 0; i < 104; i++) {  // 输出进度条的长度为103个字符
        Sleep(5);  // 延迟5毫秒，模拟加载过程
        cout << "=";  // 输出进度条的符号
    }
    cout << endl << endl;

    // 显示游戏Logo
    int x, y;  // 定义变量保存当前光标位置
    PosControl::getPos(x, y);  // 获取当前光标位置，存储在x和y中
    // cout << "x:" << x << ", y:" << y << endl; //
    int spaceLength = std::max((PosControl::size.width / 10 - 88) / 2 + 2, 0);  // 计算Logo前需要的空格数量，以使其居中显示
    string space(spaceLength, ' ');  // 创建一个包含spaceLength个空格的字符串
    while (true) {  // 无限循环，显示Logo，直到用户按下Enter键
        PosControl::setPos(x, y);  // 设置光标位置到初始位置
        ifstream logoFile("../assets/.logo");  // 打开存储Logo内容的文件
        string logo;
        while (getline(logoFile, logo)) {  // 逐行读取Logo文件内容
            int color = randInt(1, 15);  // 生成随机颜色（1到15之间的整数）
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  // 设置Logo文本颜色
            Sleep(50);  // 延迟50毫秒，增加显示效果
            cout << space << logo << endl;  // 输出Logo内容，居中显示
        }
        logoFile.close();  // 关闭Logo文件

        // 提示用户按下Enter键继续
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 恢复文本颜色为白色
        cout << endl << "按下 ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 设置文本颜色为红色
        cout << "[Enter键] ";  // 提示用户按下Enter键
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 恢复文本颜色为白色
        cout << "继续..." << endl;

        // 检测用户按下的按键，如果按下Enter键则退出循环
        if (kbhit()) {  // 检测是否有按键按下
            char c;
            c = getch();  // 获取按下的键
            if (c == '\r' || c == '\n') {  // 如果按下Enter键（ASCII码是\r或\n）
                PosControl::setPos(x + 9, 0);  // 将光标位置下移13行，避免后续内容覆盖
                break;  // 退出循环，继续执行接下来的代码
            }
        }
    }
}


// 菜单选项切换函数，返回用户选择的菜单项索引
int switcher(Menu menu[], int length) {
    int x, y;  // 用于存储光标位置的变量
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置控制台文本属性为亮白色
    cout << "使用";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 设置控制台文本属性为亮绿色
    cout << " [W] [S] ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 再次设置为亮白色
    cout << "或";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 设置为亮绿色
    cout << " [↑] [↓] ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置为亮白色
    cout << "选择，按";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // 设置为亮绿色
    cout << " [Enter键] ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置为亮白色
    cout << "确认" << endl << endl;
    // 获取当前光标位置
    PosControl::getPos(x, y);
    //cout << "switcher1->" <<"x:" << x << ", y:" << y << "<-switcher1" << endl;
    // 设置光标位置到第一行开始
    PosControl::setPos(x, 0);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置文本属性为亮白色

    for (int i = 0; i < length; i++) {  // 显示菜单项
        cout << "    > " << menu[i].name << endl;
    }
    cout << endl;
    cout << "======================================================================================================="
         << endl;

    char c;  // 用于存储用户输入的字符
    int choice = 0;  // 当前选择的菜单项索引
    int prevChoice = 0;  // 上一个选择的菜单项索引

    while (true) {  // 菜单切换循环
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 设置文本属性为亮白色
        PosControl::setPos(x + prevChoice, y);  // 移动光标到上一个选择的位置
        cout << "    > " << menu[prevChoice].name;  // 显示上一个菜单项

        PosControl::setPos(x + choice, y);  // 移动光标到当前选择的位置
        // 设置高亮显示，黄底白字
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                 FOREGROUND_GREEN | FOREGROUND_BLUE |
                                                                 BACKGROUND_RED | BACKGROUND_GREEN);
        cout << "    > " << menu[choice].name;  // 显示当前选择的菜单项
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // 恢复文本属性为亮白色
        c = getch();  // 获取用户按键
        switch (c) {
            case 'w':
            case 'W':
            case 72: // 72是上箭头的ASCII码
                prevChoice = choice;
                choice = (choice + length - 1) % length;  // 切换到上一个菜单项
                break;
            case 's':
            case 'S':
            case 80: // 80是下箭头的ASCII码
                prevChoice = choice;
                choice = (choice + 1) % length;  // 切换到下一个菜单项
                break;
            case '\r':
            case '\n':  // 如果按下Enter键，返回当前选择的索引
                return choice;
            default:
                prevChoice = choice;
                break;
        }
    }
}

// 显示游戏结束页面
void goodbye() {
    system("cls");  // 清除控制台内容
    ifstream creditsLogoFile("../assets/.endLogo");  // 打开结束Logo文件
    string logo;
    while (getline(creditsLogoFile, logo)) {  // 逐行读取文件
        cout << logo << endl;
        Sleep(randInt(20, 50));  // 延迟输出
    }
    creditsLogoFile.close();
    ifstream creditsFile("../assets/.endPage");  // 打开结束消息文件
    string credits;
    while (getline(creditsFile, credits)) {  // 逐行读取文件
        cout << credits << endl;
        Sleep(randInt(20, 50));  // 延迟输出
    }
    creditsFile.close();
}
#endif //ADVENTUREGAME_INTERFACE_H
