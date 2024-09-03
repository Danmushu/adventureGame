//
// Created by Danmu on 2024/8/30.
//

#ifndef ADVENTUREGAME_INTERFACE_H
#define ADVENTUREGAME_INTERFACE_H

#include <ctime>   // ��������ʱ����صĿ�
//#include "Monster.h"   // ���ڹ�����ع��ܣ���ʱδʹ��
#include <vector>   // ����������������̬���飩�Ŀ�
#include <iostream> // ��������������Ŀ�
#include <string>   // ���������ַ����Ŀ�
#include <fstream>  // �����ļ���������Ŀ�
#include <windows.h> // ����Windows API�����Ŀ�
#include <conio.h>  // ��������̨��������Ŀ⣬���ڼ�ⰴ��
#include <random>   // ������������ɵĿ�
//#include "utils\\rand.h" // �Զ���������������ͷ�ļ�����ʱδʹ��

using namespace std; // ʹ�ñ�׼�����ռ䣬�Լ򻯴�����д

// ����˵��ṹ�壬���ڴ洢�˵�������
struct Menu {
    string name;  // �˵�������
};

// ������Ϸ���˵���ѡ��
Menu menu[3]{
        "����Ϸ",  // ����Ϸѡ��
        "������Ϸ",  // ������Ϸѡ��
        "�˳���Ϸ"  // �˳���Ϸѡ��
};

// ���������ռ�PosControl�����ڿ��ƿ���̨���ڵ�λ�ú͹��Ĳ���
namespace PosControl {

    // ��ȡ��Ļ�Ŀ�Ⱥ͸߶�
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);

    // ���崰�ڵĿ�Ⱥ͸߶�
    struct Size {
        int width;  // ���ڿ��
        int height; // ���ڸ߶�
    } size = {1020, 1020};  // ��ʼ�����ڴ�С

    // �����ھ�����ʾ
    void centerWindow() {
        HWND hwnd = GetForegroundWindow();  // ��ȡ��ǰ���ھ��
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, size.width, size.height, 1);  // ���ô��ڴ�С
        MoveWindow(hwnd, (screen_width - size.width) / 2, (screen_height - size.height) / 2, size.width, size.height,
                   1);  // �������ƶ�����Ļ����
    }

    // ������ƶ���ָ���Ŀ���̨����λ��
    void setPos(int x, int y) {
        COORD coord{static_cast<SHORT>(y), static_cast<SHORT>(x)};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);  //�ص�����������λ�ý����������
    }

    // ��ȡ��ǰ��������λ��
    void getPos(int &x, int &y) {
        CONSOLE_SCREEN_BUFFER_INFO b;           // ��������̨��Ļ����������Ϣ
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &b);    // ��ȡ��׼������
        y = b.dwCursorPosition.X;  // ��ȡ����X����
        x = b.dwCursorPosition.Y;  // ��ȡ����Y����
    }

    // ���ؿ���̨���
    void HideCursor() {
        CONSOLE_CURSOR_INFO cursor;
        cursor.bVisible = FALSE;  // ���������Ϊ���ɼ�
        cursor.dwSize = sizeof(cursor);
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ��׼������
        SetConsoleCursorInfo(handle, &cursor);  // ���ÿ���̨�����Ϣ
    }
}

// ����ָ����Χ�ڵ��������
int randInt(int min, int max) {
    std::random_device rd;  // ��ȡӲ�������������
    std::mt19937 gen(rd());  // ʹ��Mersenne Twister�㷨���������
    std::uniform_int_distribution<> dis(min, max);  // ������ȷֲ�
    return dis(gen);  // �������ɵ������
}

// �ڿ���̨�����ָ���ļ��е���Ϣ
void printMsg(string msgDir, bool singleLine = false, bool noCD = false) {
    if (!singleLine) {  // ������ǵ������
        cout << "���� ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // �����ı���ɫΪ��ɫ
        cout << "[Tab��] ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �����ı���ɫΪ��ɫ
        cout << "��������..." << endl << endl;
    }
    ifstream msgFile(msgDir);  // ����Ϣ�ļ�
    string msg;
    int x, y;
    if (singleLine) {  // ����ǵ������
        PosControl::getPos(x, y);  // ��ȡ��ǰ���λ��
    }
    int x1 = x, y1 = y;
    while (getline(msgFile, msg)) {  // ���ж�ȡ�ļ�
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �����ı���ɫΪ��ɫ
        if (singleLine) {
            PosControl::setPos(x, y);  // ���ù��λ��
            for (int i = x; i <= x1; i++) {  // �����ǰ������
                cout << "\33[2K" << endl;
            }
            PosControl::setPos(x, y);  // �������ù��λ��
        }
        bool flagTab = false;
        for (char c: msg) {  // ������Ϣ�е�ÿ���ַ�
            if (c == '(') // �������'('�����ı���ɫ����Ϊ��ɫ
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            else if (c == ')') {  // �������')'���ָ��ı���ɫΪ��ɫ
                cout << c;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                continue;
            }
            cout << c;  // ����ַ�
            if (!flagTab) Sleep(5);  // �ӳ������ģ�����Ч��
            if (!noCD && kbhit()) {  // ��ⰴ���������������
                char c;
                c = getch();
                if (c == '\t') {
                    flagTab = true;  // �������Tab������������
                }
            }
        }
        if (singleLine) {
            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            system("pause");
        }
        Sleep(100);  // �ӳ�
        PosControl::getPos(x1, y1);  // ��ȡ���λ��
        // cout << "x1:" << x1 << ", y1:" << y1; //
        cout << endl;
    }
    msgFile.close();  // �ر��ļ�
}

// ��ʾ��Ϸ��ӭҳ��
void welcomePage() {

    // �����ھ�����ʾ�������ع��
    PosControl::centerWindow();  // ʹ�ô��ڹ�����������̨���ھ�����ʾ
    PosControl::HideCursor();  // ���ؿ���̨��꣬������û�����

    // �����ʼ�ָ��ߣ�������ʾ�û���������̨�����С
    cout << "==================================================================================================="
         << endl;

    // ��ʾ�û���ε��������С
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �����ı���ɫΪ��ɫ
    cout << endl << "    ��ʹ�� ";  // �����ʾ��Ϣ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // �����ı���ɫΪ��ɫ
    cout << "[Ctrl] ";  // ��ʾ�û���סCtrl��
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �ָ��ı���ɫΪ��ɫ
    cout << "+ ";  // ����Ӻ�
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // �����ı���ɫΪ��ɫ
    cout << "���� ";  // ��ʾ�û�����������
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �ָ��ı���ɫΪ��ɫ
    cout << "��������̨�����С��ȷ�����Ϸָ�����ʾ��ͬһ�С�"
         << endl;

    // ��ʾ�û�����Enter������
    cout << endl << "���� ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // �����ı���ɫΪ��ɫ
    cout << "[Enter��] ";  // ��ʾ�û�����Enter��
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �ָ��ı���ɫΪ��ɫ
    cout << "����..." << endl;

    // �ȴ��û�����Enter���Լ���
    while (true) {  // ����ѭ����ֱ���û�����Enter��
        if (kbhit()) {  // ����Ƿ��а�������
            char c;
            c = getch();  // ��ȡ���µļ�
            if (c == '\r' || c == '\n') {  // �������Enter����ASCII����\r��\n��
                PosControl::setPos(0, 0);  // ������ƶ�������̨��(0, 0)λ�ã�׼�������Ļ����
                //system("cls");
                // �������̨��������пհ��У�ʹ����̨������������
                cout << string(104, ' ') << endl;
                cout << string(104, ' ') << endl;
                cout << string(104, ' ') << endl;
                cout << string(104, ' ') << endl;
                cout << string(104, ' ') << endl;
                PosControl::setPos(0, 0);  // �ٴν�����ƶ���(0, 0)λ�ã�׼����ʾ�µ�����
                break;  // �˳�ѭ��������ִ�н������Ĵ���
            }
        }
    }

    // �����ӭҳ����ı����ݣ����ļ� "../assets/scene/startPage.txt" �ж�ȡ����ʾ
    printMsg("../assets/scene/startPage.txt");  // ���ú��������ʼҳ�����Ϣ�������û�ͨ��Tab������

    // ��ʾ���ؽ�����
    cout << endl << endl;
    for (int i = 0; i < 104; i++) {  // ����������ĳ���Ϊ103���ַ�
        Sleep(5);  // �ӳ�5���룬ģ����ع���
        cout << "=";  // ����������ķ���
    }
    cout << endl << endl;

    // ��ʾ��ϷLogo
    int x, y;  // ����������浱ǰ���λ��
    PosControl::getPos(x, y);  // ��ȡ��ǰ���λ�ã��洢��x��y��
    // cout << "x:" << x << ", y:" << y << endl; //
    int spaceLength = std::max((PosControl::size.width / 10 - 88) / 2 + 2, 0);  // ����Logoǰ��Ҫ�Ŀո���������ʹ�������ʾ
    string space(spaceLength, ' ');  // ����һ������spaceLength���ո���ַ���
    while (true) {  // ����ѭ������ʾLogo��ֱ���û�����Enter��
        PosControl::setPos(x, y);  // ���ù��λ�õ���ʼλ��
        ifstream logoFile("../assets/.logo");  // �򿪴洢Logo���ݵ��ļ�
        string logo;
        while (getline(logoFile, logo)) {  // ���ж�ȡLogo�ļ�����
            int color = randInt(1, 15);  // ���������ɫ��1��15֮���������
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  // ����Logo�ı���ɫ
            Sleep(50);  // �ӳ�50���룬������ʾЧ��
            cout << space << logo << endl;  // ���Logo���ݣ�������ʾ
        }
        logoFile.close();  // �ر�Logo�ļ�

        // ��ʾ�û�����Enter������
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �ָ��ı���ɫΪ��ɫ
        cout << endl << "���� ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // �����ı���ɫΪ��ɫ
        cout << "[Enter��] ";  // ��ʾ�û�����Enter��
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �ָ��ı���ɫΪ��ɫ
        cout << "����..." << endl;

        // ����û����µİ������������Enter�����˳�ѭ��
        if (kbhit()) {  // ����Ƿ��а�������
            char c;
            c = getch();  // ��ȡ���µļ�
            if (c == '\r' || c == '\n') {  // �������Enter����ASCII����\r��\n��
                PosControl::setPos(x + 9, 0);  // �����λ������13�У�����������ݸ���
                break;  // �˳�ѭ��������ִ�н������Ĵ���
            }
        }
    }
}


// �˵�ѡ���л������������û�ѡ��Ĳ˵�������
int switcher(Menu menu[], int length) {
    int x, y;  // ���ڴ洢���λ�õı���
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // ���ÿ���̨�ı�����Ϊ����ɫ
    cout << "ʹ��";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // ���ÿ���̨�ı�����Ϊ����ɫ
    cout << " [W] [S] ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �ٴ�����Ϊ����ɫ
    cout << "��";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // ����Ϊ����ɫ
    cout << " [��] [��] ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // ����Ϊ����ɫ
    cout << "ѡ�񣬰�";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);  // ����Ϊ����ɫ
    cout << " [Enter��] ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // ����Ϊ����ɫ
    cout << "ȷ��" << endl << endl;
    // ��ȡ��ǰ���λ��
    PosControl::getPos(x, y);
    //cout << "switcher1->" <<"x:" << x << ", y:" << y << "<-switcher1" << endl;
    // ���ù��λ�õ���һ�п�ʼ
    PosControl::setPos(x, 0);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �����ı�����Ϊ����ɫ

    for (int i = 0; i < length; i++) {  // ��ʾ�˵���
        cout << "    > " << menu[i].name << endl;
    }
    cout << endl;
    cout << "======================================================================================================="
         << endl;

    char c;  // ���ڴ洢�û�������ַ�
    int choice = 0;  // ��ǰѡ��Ĳ˵�������
    int prevChoice = 0;  // ��һ��ѡ��Ĳ˵�������

    while (true) {  // �˵��л�ѭ��
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �����ı�����Ϊ����ɫ
        PosControl::setPos(x + prevChoice, y);  // �ƶ���굽��һ��ѡ���λ��
        cout << "    > " << menu[prevChoice].name;  // ��ʾ��һ���˵���

        PosControl::setPos(x + choice, y);  // �ƶ���굽��ǰѡ���λ��
        // ���ø�����ʾ���Ƶװ���
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
                                                                 FOREGROUND_GREEN | FOREGROUND_BLUE |
                                                                 BACKGROUND_RED | BACKGROUND_GREEN);
        cout << "    > " << menu[choice].name;  // ��ʾ��ǰѡ��Ĳ˵���
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  // �ָ��ı�����Ϊ����ɫ
        c = getch();  // ��ȡ�û�����
        switch (c) {
            case 'w':
            case 'W':
            case 72: // 72���ϼ�ͷ��ASCII��
                prevChoice = choice;
                choice = (choice + length - 1) % length;  // �л�����һ���˵���
                break;
            case 's':
            case 'S':
            case 80: // 80���¼�ͷ��ASCII��
                prevChoice = choice;
                choice = (choice + 1) % length;  // �л�����һ���˵���
                break;
            case '\r':
            case '\n':  // �������Enter�������ص�ǰѡ�������
                return choice;
            default:
                prevChoice = choice;
                break;
        }
    }
}

// ��ʾ��Ϸ����ҳ��
void goodbye() {
    system("cls");  // �������̨����
    ifstream creditsLogoFile("../assets/.endLogo");  // �򿪽���Logo�ļ�
    string logo;
    while (getline(creditsLogoFile, logo)) {  // ���ж�ȡ�ļ�
        cout << logo << endl;
        Sleep(randInt(20, 50));  // �ӳ����
    }
    creditsLogoFile.close();
    ifstream creditsFile("../assets/.endPage");  // �򿪽�����Ϣ�ļ�
    string credits;
    while (getline(creditsFile, credits)) {  // ���ж�ȡ�ļ�
        cout << credits << endl;
        Sleep(randInt(20, 50));  // �ӳ����
    }
    creditsFile.close();
}
#endif //ADVENTUREGAME_INTERFACE_H
