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
    int x, y; //���ڴ洢���λ��
    string name; //�������
    //��ȡ���λ��
    PosControl::getPos(x, y);
    // ���ù��λ�õ���ǰ�е���ʼλ�� todo
    PosControl::setPos(x, 0);
    //�����ǰ������
    cout << "\33[2K";
    // �����������
    cout <<  "�������������: ";
    cin >> name;
    // ��֤�������������Ƿ�Ϸ�
    while (name.length() > 15 || name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") != string::npos) {
        // ������ֲ��Ϸ����������ù�겢��ʾ�����������
        PosControl::setPos(x, 0);
        // �����ǰ������
        cout << "\33[2K" << endl;
        // ��������Ƿ�����Ƿ��ַ������ֳ����Ƿ񳬹�15���ַ�
        if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_") != string::npos) {
            // ��������Ƿ��ַ�����ʾ�����������Ϸ�����
            cout << "�����к��зǷ��ַ������������룺";
        } else {
            // ������ֹ�������ʾ������������һ�������
            cout << "���ֹ��������������룺";
        }
        cin >> name;  // ���»�ȡ������������
    }

    // ���������ʾ��
    PosControl::setPos(x, 0);

    // ʹ�������������ִ���һ�� Player ����
    Player player(name);
    // ��ʼ���溯��
    GameController game(player);

    // ����Ҵ��к�����ʾ������
    cout << "    ��ã���Ϊ ";
    // ��������ɫ����Ϊ��ɫ
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    cout << name;
    // �ָ�������ɫΪĬ��ֵ����ɫ��
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << " ��̽����" << endl;

    // ������п��У��Ӿ��������������
    string spaceLine(100, ' ');
    cout << spaceLine << endl << spaceLine << endl
         << spaceLine << endl << spaceLine << endl;

    // todo
    /********* ��Ϸ������ʼ *********/
    // ���� switcher ������ʾ���˵������������ѡ��ִ����Ӧ�Ĳ���
    switch (switcher(menu, 3)) {
        case 0:
            // ������ѡ���ˡ�����Ϸ��������������Ϸ
                game.newGame();
        break;
        case 1:
            // ������ѡ���ˡ�������Ϸ�����������Ϸ����
                game.loadGame();
        break;
        case 2:
            // ������ѡ���ˡ��˳���Ϸ��������ʾ�˳�ҳ�棬���˳�����
                goodbye();
                system("pause");  // ��ͣ�ȴ��û�����
        return 0;  // �˳�����
        default: ;
    }



    return 0;
}
