#include <iostream>

using namespace std;

typedef unsigned int number;
typedef string depositType;
typedef unsigned int balance;
typedef string date;
typedef string fio;
typedef bool sms;
typedef bool banking;

struct bank {
    depositType userType;
    number userNumber;
    balance userBalance;
    date openingDate;
    fio owner;
    sms smsNotification;
    banking internetBankingApp;

};

bool operator > (bank firstUser, bank secondUser) {
    return (firstUser.userBalance > secondUser.userBalance);  // Возвращает true, если баланс 1 пользователя больше баланса второго пользователя
}

bool operator == (bank firstUser, bank secondUser)
{
    bool check = true;
    for (int i = 0; i < min(firstUser.userType.length(), secondUser.userType.length()); i++)
    {
        if (firstUser.userType[i] != secondUser.userType[i])
        {
            check = false;
        }
    }
    return check;
}

int main() {
    setlocale(LC_ALL, "Russian");
    bank firstUser = { "депозит с капитализацией", 17151442, 14400, "23.01.2020", "Иванов Иван Игорьевич", "true", "false"};
    bank secondUser = { "сберегательный вклад", 12727432, 98220, "24.02.2011", "Черник Никита Юрьевич","false", "false"};
    firstUser > secondUser ? cout << "Баланс первого человека больше баланса второго человека\n" : cout << "Баланс второго человека больше баланса первого человека\n";
    firstUser == secondUser ? cout << "У первого пользователся такой-же тип вклада как и у второго\b" : cout << "У пользователей 1 и 2 разные типы вкладов\n";
    return 0;
}
