#include <iostream>

// Определение пользовательских типов данных для представления даты
typedef unsigned char day;    // День месяца
typedef unsigned char month;  // Месяц
typedef unsigned short year;  // Год

using namespace std;

// Определение структуры для хранения даты
struct Date
{
	day dd;
	month mm;
	year yyyy;
};

// Перегрузка оператора ">" для сравнения двух дат
bool operator > (Date a, Date b)
{
	// Сравнение дат в порядке убывания года, месяца и дня месяца
	return ((a.yyyy > b.yyyy) || ((a.yyyy == b.yyyy) && (a.mm > b.mm)) || ((a.yyyy == b.yyyy) && (a.mm == b.mm) && (a.dd > b.dd)));
}

// Перегрузка оператора "<" для сравнения двух дат
bool operator < (Date a, Date b)
{
	// Сравнение дат в порядке возрастания года, месяца и дня месяца
	return ((a.yyyy < b.yyyy) || ((a.yyyy == b.yyyy) && (a.mm < b.mm)) || ((a.yyyy == b.yyyy) && (a.mm == b.mm) && (a.dd < b.dd)));
}

// Перегрузка оператора "==" для сравнения двух дат на равенство
bool operator ==(Date a, Date b)
{
	// Проверка на равенство дней, месяцев и годов
	return (a.dd == b.dd && a.mm == b.mm && a.yyyy == b.yyyy);
}

int main()
{
	// Инициализация трех объектов типа Date с различными датами
	Date date1 = { 7, 1, 1980 };
	Date date2 = { 7, 2, 1993 };
	Date date3 = { 7, 1, 1980 };

	// Сравнение дат date1 и date2 и вывод результата
	if (date1 < date2)  cout << "true" <<  endl;
	else  cout << "false" <<  endl;

	// Сравнение дат date1 и date2 и вывод результата
	if (date1 > date2)  cout << "true" <<  endl;
	else  cout << "false" <<  endl;

	// Сравнение дат date1 и date2 на равенство и вывод результата
	if (date1 == date2)  cout << "true" <<  endl;
	else  cout << "false" <<  endl;

	// Сравнение дат date1 и date3 на равенство и вывод результата
	if (date1 == date3)  cout << "true" <<  endl;
	else  cout << "false" <<  endl;

	return 0;
}
