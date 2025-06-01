#include <iostream>
#include "getData.h"

using namespace std;

int Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int day, month, year;

void getData() {
    setlocale(LC_CTYPE, "rus");
    bool result = false;

    while (!result) {
        int data;
        cin >> data;

        day = data / 1000000;
        month = (data / 10000) % 100;
        year = data % 10000;

        Days[1] = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;

        if (cin.fail() || day <= 0 || month <= 0 || year <= 0 || month > 12 || day > Days[month - 1]) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "������������ ����, ���������� ��� ���\n";
        }
        else {
            cout << (Days[1] == 29 ? "��� ����������\n" : "��� �� ����������\n");
            result = true;
        }
    }
}

void printDate() 
{
    switch (month)
    {
    case 1:
        cout << "������";
        break;
    case 2:
        cout << "�������";
        break;
    case 3:
        cout << "�����";
        break;
    case 4:
        cout << "������";
        break;
    case 5:
        cout << "���";
        break;
    case 6:
        cout << "����";
        break;
    case 7:
        cout << "����";
        break;
    case 8:
        cout << "�������";
        break;
    case 9:
        cout << "��������";
        break;
    case 10:
        cout << "�������";
        break;
    case 11:
        cout << "������";
        break;
    case 12:
        cout << "�������";
        break;
    default:
        break;
    }
    cout << " " << year << endl;
}