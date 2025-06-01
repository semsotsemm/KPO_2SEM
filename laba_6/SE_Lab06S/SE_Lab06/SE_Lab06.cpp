#include <tchar.h>

//#define TEST_CREATE_01
//#define TEST_CREATE_02
//#define TEST_ADDENTRY_03
//#define TEST_ADDENTRY_04
//#define TEST_GETENTRY_05
//#define TEST_GETENTRY_06
//#define TEST_UPDENTRY_07
//#define TEST_UPDENTRY_08
//#define TEST_DICTIONARY

#include <locale>
#include <iostream>
#include "../SE_Lab06L/Dictionary.h"
#include <cstring>
#include <string>

#if defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + \
    defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_GETENTRY_06) + \
    defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) + defined(TEST_DICTIONARY) > 1
#error "Нельзя устанавливать более одного тестового макроса!"
#endif

using namespace std;
using namespace Dictionary;

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");

    try {
#ifdef TEST_CREATE_01
        {
            try {
                Instance testInst = Create("ИмяКотороеСлишкомДлинное", 5);
                cout << "TEST_CREATE_01 failed: исключение не выброшено." << endl;
            }
            catch (const char* e) {
                if (strcmp(e, THROW01) == 0)
                    cout << "TEST_CREATE_01 ошибка: " << THROW01 << endl;
                else
                    cout << "TEST_CREATE_01 failed: неожиданная ошибка: " << e << endl;
            }
        }
#endif

#ifdef TEST_CREATE_02
        {
            try {
                Instance testInst = Create("Преподаватели", DICTMAXSIZE + 1);
                cout << "TEST_CREATE_02 failed: исключение не выброшено." << endl;
            }
            catch (const char* e) {
                if (strcmp(e, THROW02) == 0)
                    cout << "TEST_CREATE_02 ошибка: " << THROW02 << endl;
                else
                    cout << "TEST_CREATE_02 failed: неожиданная ошибка: " << e << endl;
            }
        }
#endif

#ifdef TEST_ADDENTRY_03
        {
            Instance testInst = Create("Тест", 1);
            Entry entry1 = { 1, "Первый" };
            AddEntry(testInst, entry1);
            Entry entry2 = { 2, "Второй" };
            try {
                AddEntry(testInst, entry2);
                cout << "TEST_ADDENTRY_03 failed: исключение не выброшено." << endl;
            }
            catch (const char* e) {
                if (strcmp(e, THROW03) == 0)
                    cout << "TEST_ADDENTRY_03 ошибка: " << THROW03 << endl;
                else
                    cout << "TEST_ADDENTRY_03 failed: неожиданная ошибка: " << e << endl;
            }
            Delete(testInst);
        }
#endif

#ifdef TEST_ADDENTRY_04
        {
            Instance testInst = Create("Тест", 5);
            Entry entry1 = { 1, "Первый" };
            Entry entry2 = { 1, "Дубликат" };
            AddEntry(testInst, entry1);
            try {
                AddEntry(testInst, entry2);
                cout << "TEST_ADDENTRY_04 failed: исключение не выброшено." << endl;
            }
            catch (const char* e) {
                if (strcmp(e, THROW04) == 0)
                    cout << "TEST_ADDENTRY_04 ошибка: " << THROW04 << endl;
                else
                    cout << "TEST_ADDENTRY_04 failed: неожиданная ошибка: " << e << endl;
            }
            Delete(testInst);
        }
#endif

#ifdef TEST_GETENTRY_05
        {
            Instance testInst = Create("Тест", 5);
            Entry entry1 = { 1, "Первый" };
            AddEntry(testInst, entry1);
            try {
                Entry res = GetEntry(testInst, 999);
                cout << "TEST_GETENTRY_05 failed: исключение не выброшено." << endl;
            }
            catch (const char* e) {
                if (strcmp(e, THROW05) == 0)
                    cout << "TEST_GETENTRY_05 ошибка: " << THROW05 << endl;
                else
                    cout << "TEST_GETENTRY_05 failed: неожиданная ошибка: " << e << endl;
            }
            Delete(testInst);
        }
#endif

#ifdef TEST_GETENTRY_06
        {
            Instance testInst = Create("Тест", 5);
            Entry entry1 = { 1, "Первый" };
            AddEntry(testInst, entry1);
            try {
                DelEntry(testInst, 999);
                cout << "TEST_GETENTRY_06 failed: исключение не выброшено." << endl;
            }
            catch (const char* e) {
                if (strcmp(e, THROW06) == 0)
                    cout << "TEST_GETENTRY_06 ошибка: " << THROW06 << endl;
                else
                    cout << "TEST_GETENTRY_06 failed: неожиданная ошибка: " << e << endl;
            }
            Delete(testInst);
        }
#endif

#ifdef TEST_UPDENTRY_07
        {
            Instance testInst = Create("Тест", 5);
            Entry entry1 = { 1, "Первый" };
            AddEntry(testInst, entry1);
            Entry updateEntry = { 3, "Обновленный" };
            try {
                UpdEntry(testInst, 999, updateEntry);
                cout << "TEST_UPDENTRY_07 failed: исключение не выброшено." << endl;
            }
            catch (const char* e) {
                if (strcmp(e, THROW07) == 0)
                    cout << "TEST_UPDENTRY_07 ошибка: " << THROW07 << endl;
                else
                    cout << "TEST_UPDENTRY_07 failed: неожиданная ошибка: " << e << endl;
            }
            Delete(testInst);
        }
#endif
#ifdef TEST_UPDENTRY_08
        {
            Instance testInst = Create("Тест", 5);
            Entry entry1 = { 1, "Первый" };
            Entry entry2 = { 2, "Второй" };
            AddEntry(testInst, entry1);
            AddEntry(testInst, entry2);
            Entry updateEntry = { 2, "Измененный" };
            try {
                UpdEntry(testInst, 1, updateEntry);
                cout << "TEST_UPDENTRY_08 failed: исключение не выброшено." << endl;
            }
            catch (const char* e) {
                if (strcmp(e, THROW08) == 0)
                    cout << "TEST_UPDENTRY_08 ошибка: " << THROW08 << endl;
                else
                    cout << "TEST_UPDENTRY_08 failed: неожиданная ошибка: " << e << endl;
            }
            Delete(testInst);
        }
#endif
#ifdef TEST_DICTIONARY
        {
            Instance d1 = Create("Преподаватели", 5);
            Entry e1 = { 1, "Гладкий" };
            Entry e2 = { 2, "Великин" };
            Entry e3 = { 3, "Смелов" };
            Entry e4 = { 4, "Урбанович" };
            Entry e5 = { 5, "Пащей" };
            AddEntry(d1, e1);
            AddEntry(d1, e2);
            AddEntry(d1, e3);
            AddEntry(d1, e4);
            AddEntry(d1, e5);
            Entry ex2 = GetEntry(d1, 4);
            DelEntry(d1, 2);
            Entry newentry1 = { 6, "Гурин" };
            UpdEntry(d1, 3, newentry1);
            Print(d1);
            Instance d2 = Create("Студенты", 5);
            Entry s1 = { 1, "Иванов" };
            Entry s2 = { 2, "Петров" };
            Entry s3 = { 3, "Сидоров" };
            AddEntry(d2, s1);
            AddEntry(d2, s2);
            AddEntry(d2, s3);
            Entry newentry3 = { 3, "Николаев" };
            UpdEntry(d2, 3, newentry3);
            Print(d2);
            Delete(d1);
            Delete(d2);
            cout << "TEST_DICTIONARY passed: Все функции выполнены корректно." << endl;
        }
#endif
    }
    catch (const char* e) {
        std::cerr << "Ошибка: " << e << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Стандартное исключение: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Неизвестное исключение." << std::endl;
    }
    system("pause");
    return 0;
}
