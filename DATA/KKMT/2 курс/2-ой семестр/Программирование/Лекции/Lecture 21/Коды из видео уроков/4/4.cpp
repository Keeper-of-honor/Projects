/**
Ввод:
    Имя
Вывод:
    "Hi, <имя>"
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hi, " << name << endl;
    
    return 0;
}

