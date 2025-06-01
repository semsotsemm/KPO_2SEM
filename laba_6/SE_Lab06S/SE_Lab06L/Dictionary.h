#pragma once
#include <cstring>
#include <stdexcept>
#include <iostream>

// �����������
#define DICTNAMEMAXSIZE 20    // ������������ ������ ����� �������
#define DICTMAXSIZE 100       // ������������ ������� �������
#define ENTRYNAMEMAXSIZE 30   // ������������ ����� ����� �������� �������

// ������� ����������
#define THROW01 "Create: �������� ������ ����� �������"          // ���� ����� ����� >= DICTNAMEMAXSIZE
#define THROW02 "Create: ��������� ������������ ������� �������"    // ���� size > DICTMAXSIZE
#define THROW03 "AddEntry: ������������ �������"                   // ���� ���������� ��������� >= maxsize
#define THROW04 "AddEntry: ������������ ��������������"           // ���� ��� ���� ������� � ����� id
#define THROW05 "GetEntry: �� ������ �������"                      // ���� ������� �� ������
#define THROW06 "DelEntry: �� ������ �������"                      // ���� ��������� ������� �� ������
#define THROW07 "UpdEntry: �� ������ �������"                      // ���� ������� ��� ���������� �� ������
#define THROW08 "UpdEntry: ������������ ��������������"           // ���� ��� ���������� id �����������

namespace Dictionary {

    // ��������� �������� �������
    struct Entry {
        int id;                            // ���������� �������������
        char name[ENTRYNAMEMAXSIZE];       // ��������� ������������� ����������
    };

    // ��������� �������
    struct Instance {
        char name[DICTNAMEMAXSIZE];        // ��� �������
        int maxsize;                       // ������������ ���������� ���������
        int size;                          // ������� ���������� ���������
        Entry* dictionary;                 // ������������ ������ ���������
    };

    // ���������� �������:
    Instance Create(const char name[DICTNAMEMAXSIZE], int size);
    void AddEntry(Instance& inst, Entry ed);
    void DelEntry(Instance& inst, int id);
    void UpdEntry(Instance& inst, int id, Entry new_ed);
    Entry GetEntry(Instance& inst, int id);
    void Print(const Instance& d);
    void Delete(Instance& d);
}
