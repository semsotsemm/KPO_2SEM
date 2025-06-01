#include <iostream>
#include <windows.h> // для работы с кодировкой
#include <cmath>  // Для sqrt
#pragma fenv_access(on)

int add(int a, int b) 
{
    return a + b;
}

using namespace std;

int main() {
    SetConsoleOutputCP(1251);// Устанавливаем кодировку консоли
    SetConsoleCP(1251);// Устанавливаем кодировку консоли

    int student_number = 1; //порядковый номер
    int X = 9 + student_number;  // X = 9 + 1 = 10
    int Y = 10 + student_number; // Y = 10 + 1 = 11
    int Z = 11 + student_number; // Z = 11 + 1 = 12
    float S = 1.0f + student_number; // S = 1.0 + 1 = 2.0

    bool flag1 = false; //Переменная типа bool (false)
    bool flag2 = true; //Переменная типа bool (true)

    char charEng = 'n'; // Вторая буква фамилии на английском
    char charRus = 'н'; // Вторая буква фамилии на русском

    wchar_t wcharEng = L'A'; // Первая буква фамилии на английском
    wchar_t wcharRus = L'А'; // Первая буква фамилии на русском

    short shortX = X; // 10 десят. = A шест. Максимальное значение short 32767 = 16^4, значит в памяти short будет хранится в 4 битах, заполним остальные биты 0 и получим 0a00  
    short shortNegX = -X;// Для получучения -10 переведем 0a00 в обратный код для этого каждый бит заполним такими символами чтобы в сумме довало 16 (0+f = a + 6 =16) получим f6ff

    short maxShort = 0x7FFF; // самое большое число short
    short minShort = 0x8000; // самое маленькое число short (из-за переполнения число получится отрицательным)

    unsigned short maxUnsignedShort = 0xFFFF; //самое большое число unsigned short
    unsigned short minUnsignedShort = 0x0000; //самое маленькое число unsigned short

    int intY = Y; // 11 десят. = B шест. Максимальное значение int 4294967296 = 16^8, значит в памяти short будет хранится в 8 битах, заполним остальные биты 0 и получим 0b00 0000  
    int intNegY = -Y;// Для получучения -11 переведем 0a00 в обратный код для этого каждый бит заполним такими символами чтобы в сумме довало 16 (0+f = b + 5 =16) получим f5ff ffff

    int maxInt = 0x7FFFFFFF;// самое большое число int
    int minInt = 0x80000000;// самое маленькое число int (из-за переполнения число получится отрицательным)

    unsigned int maxUnsignedInt = 0xFFFFFFFF; //самое большое число unsigned short
    unsigned int minUnsignedInt = 0x00000000; //самое маленькое число unsigned short

    long longZ = Z; // 12 десят. = C шест. Максимальное значение long 16^8, значит в памяти long будет хранится в 8 битах, заполним остальные биты 0 и получим 0c00 0000  
    long longNegZ = -Z;// Для получучения -12 переведем 0c00 в обратный код для этого каждый бит заполним такими символами чтобы в сумме довало 16 (0+f = c + 4 =16) получим f4ff ffff

    long int maxLong = 0x7FFFFFFF;// самое большое число long
    long int minLong = 0x80000000;// самое маленькое число long (из-за переполнения число получится отрицательным)

    unsigned long maxUnsignedLong = 0xFFFFFFFF; //самое большое число unsigned long
    unsigned long minUnsignedLong = 0x00000000; //самое маленькое число unsigned long

    float floatS = S; // 2.0 десят. = 4 шест. т.к. 2 = 2^1 мантисса 0000 значит представление в десятичной с/с будет 0 000001 0000000 или 0 000004 0000000 (0000 0040)
    float floatNegS = -S;// Для получения -S переведем S в обратный код 0000 00c0

    float inf = 1.0f / 0.0f;     // 1.#INF
    float negInf = -1.0f / 0.0f; // -1.#INF
    float nanVal = sqrt(-1.0f);  // -1.#IND (NaN)

    cout << "1.#INF: " << inf << endl;
    cout << "-1.#INF: " << negInf << endl;
    cout << "-1.#IND: " << nanVal << endl;

    char symbolChar = 'A'; //41 -> 44
    wchar_t symbolwChar = L'Б'; //11 04 -> 14 04
    short numberShort = 1234; //d2 04 ->  d5 04
    int numberInt = 56789; // d5 dd 00 00 -> d8 dd 00 00
    float numberFloat = 1.23f; // a4 70 9d 3f -> 29 5c 87 40
    double numberDouble = 4.56; //3d 0a d7 a3 70 3d 12 40 -> 3d 0a d7 a3 70 3d 1e 40

    char* pC = &symbolChar;
    wchar_t* pWc = &symbolwChar;
    short* pS = &numberShort;
    int* pI = &numberInt;
    float* pF = &numberFloat;
    double* pD = &numberDouble;

    *pC += 3;
    *pWc += 3;
    *pS += 3;
    *pI += 3;
    *pF += 3;
    *pD += 3;

    // Указатель на функцию с параметрами
    int (*addPtr)(int, int) = add;

    // Вызов функций через указатели
    int sum = addPtr(10, 20);

    return 0;// Возвращаем 0 из мейна
}
