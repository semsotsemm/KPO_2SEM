#include <iostream>
#include "getData.h"

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void getDateFromDayNumber(int dayOfYear, int year) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    int month = 0;
    int remainingDays = dayOfYear;
    while (remainingDays > daysInMonth[month]) {
        remainingDays -= daysInMonth[month];
        month++;
    }
    const char* monthNames[] = { "января", "февраля", "марта", "апреля", "мая", "июня", "июля", "августа", "сентября", "октября", "ноября", "декабря" };
    cout << remainingDays << " " << monthNames[month] << " " << year;

    if (dayOfYear == 1) {
        cout << " — Новый год";
    }
    else if (dayOfYear == 7) {
        cout << " — Рождество Христово";
    }
    else if (dayOfYear == 54) {
        cout << " — День защитника Отечества";
    }
    else if (dayOfYear == 67 && !isLeapYear(year)) {
        cout << " — Международный женский день";
    }
    else if (dayOfYear == 68 && isLeapYear(year)) {
        cout << " — Международный женский день";
    }
    else if (dayOfYear == 121) {
        cout << " — День труда";
    }
    else if (dayOfYear == 256 && !isLeapYear(year)) {
        cout << " — День программиста";
    }
    else if (dayOfYear == 255 && isLeapYear(year)) {
        cout << " — День программиста";
    }
    cout << endl;
}

int main() {
    setlocale(LC_CTYPE, "Rus");
    int day, month, year;
    int birthDay, birthMonth, birthYear;

    cout << "Введите текущую дату (ДДММГГГГ): ";
    getData();
    day = ::day;
    month = ::month;
    year = ::year;
    int currentYear = year;

    cout << "Введите дату вашего рождения (ДДММГГГГ): ";
    getData();
    birthDay = ::day;
    birthMonth = ::month;
    birthYear = ::year;

    int daysInYear = isLeapYear(year) ? 366 : 365;
    int dayOfYear = 0;
    int birthDayOfYear = 0;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeapYear(year)) daysInMonth[1] = 29;

    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }
    dayOfYear += day;

    for (int i = 0; i < birthMonth - 1; i++) {
        birthDayOfYear += daysInMonth[i];
    }
    birthDayOfYear += birthDay;

    if (birthYear > currentYear || (birthYear == currentYear && birthDayOfYear > dayOfYear)) {
        cout << "Ошибка: человек ещё не родился!" << endl;
        return 1;
    }

    int daysUntilBirthday = (birthDayOfYear >= dayOfYear) ? (birthDayOfYear - dayOfYear) : (daysInYear - dayOfYear + birthDayOfYear);
    cout << "Количество дней до дня рождения: " << daysUntilBirthday << endl;

    cout << "Введите порядковый номер дня в году: ";
    int inputDay;
    cin >> inputDay;

    if (inputDay < 1 || inputDay > daysInYear) {
        cout << "Ошибка: некорректный порядковый номер дня!" << endl;
        return 1;
    }

    getDateFromDayNumber(inputDay, currentYear);

    return 0;
}