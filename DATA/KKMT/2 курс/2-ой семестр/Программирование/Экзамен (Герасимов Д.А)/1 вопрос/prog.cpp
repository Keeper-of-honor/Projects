/**
С++. Модульное программирование. Структура и пример проекта.
*/
//Выполнил: Герасимов Д.А. П1-18. 23.06.2020
#include <iostream>

using namespace std;

struct UserData{
    long unsigned int idUsers;
    std::string fio;
    std::string mail;
    long unsigned int mobile;
};

int main(){
    struct UserData Data;

	cout << "ID Фамилия Почта Номер_телефона" << endl;
    cin >> Data.idUsers >> Data.fio >> Data.mail >> Data.mobile;

	cout << Data.idUsers << ' ' << Data.fio << ' ' << Data.mail << ' ' << Data.mobile << endl;
    return 0;
}

