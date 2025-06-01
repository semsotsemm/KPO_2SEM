#include <iostream>
#include "getData.h"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Rus");
    int nday = 0, nday_bth = 0;
    int lyear = 0;

    cout << "Введите текущую дату (ДДММГГГГ): ";
    getData();
    lyear = year;

    for (int i = 0; i < month - 1; i++) {
        nday += Days[i];
    }
    nday += day;

    cout << "Порядковый номер дня: " << nday << "\n";
    cout << "Введите дату вашего дня рождения (ДДММГГГГ): ";

    Days[1] = 28; // Сброс дней февраля перед новой датой
    getData();

    for (int i = 0; i < month - 1; i++) {
        nday_bth += Days[i];
    }
    nday_bth += day;

    //Проверка, что человек уже родился
    if (checkYear(year, lyear, nday_bth, nday)) 
    {
        cout << "Ошибка: человек ещё не родился!" << endl;
        return 1;
    }

    //Проверка на 29 февраля 
    if (month == 2 && day == 29) {
        // Если текущий год високосный и день рождения ещё не наступил
        if (((lyear % 4 == 0 && lyear % 100 != 0) || (lyear % 400 == 0)) && nday_bth >= nday) {
            cout << "Количество дней до дня рождения: " << nday_bth - nday;
        }
        else {
            int days_left = 365 - nday;
            ++lyear;

            // Поиск следующего високосного года
            while (!((lyear % 4 == 0 && lyear % 100 != 0) || (lyear % 400 == 0))) {
                days_left += 365;
                ++lyear;
            }

            // Добавляем 59 дней (29 февраля — 59-й день високосного года)
            days_left += 59;

            // Учёт високосного года: +1 день
            if ((lyear % 4 == 0 && lyear % 100 != 0) || (lyear % 400 == 0)) {
                days_left++;
            }

            cout << "Количество дней до дня рождения: " << days_left;
        }
    }
    else if (nday_bth >= nday) {
        cout << "Количество дней до дня рождения: " << nday_bth - nday;
    }
    else {
        cout << "Количество дней до дня рождения: " << 365 - nday + nday_bth;
    }

    return 0;
}
