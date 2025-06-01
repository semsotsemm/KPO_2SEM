#include <iostream>
using namespace std;

int default_parm(int x1, int x2, int x3, int x4, int x5, int x6 = 6, int x7 = 7)
{
	return (x1 + x2 + x3 + x4 + x5 + x6 + x7) / 7;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int result1 = default_parm(1, 9, 4, 2, 8);
	int result2 = default_parm(6, 8, 10, 7, 5, 9, 12);
	cout << "Результат работы функции с 5 параметрами: " << result1 << endl;
	cout << "Результат работы функции с 7 параметрами: " << result2 << endl;
}