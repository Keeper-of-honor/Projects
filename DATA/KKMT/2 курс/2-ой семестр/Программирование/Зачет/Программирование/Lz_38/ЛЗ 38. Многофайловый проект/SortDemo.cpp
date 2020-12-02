// Демонстрация сотрировки с компаратором
// Гусятинер Л.Б., 9.05.2020
// uses
//   https://qna.habr.com/q/187265
//   Александр Таратин @Taraflex

/* Перегрузить оператор сравнения
    или передавать в shellSort функцию-сравнятор
    bool comparer(const myStruct &a,const myStruct &b) {
        return a.somefield > b.somefield
} */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct St {
    int id;
    string name;
};

bool comparer(const St &a,const St &b) {
    return a.name < b.name;
}

int main() {
    vector <St> v(5);
    v[0].id = 1; v[0].name = "Vasya";
    v[1].id = 2; v[1].name = "Petya";
    v[2].id = 3; v[2].name = "Nina";
    v[3].id = 4; v[3].name = "Fedya";
    v[4].id = 5; v[4].name = "Kolya";

    cout << "before" << endl;
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i].id << " " << v[i].name << endl;

    sort(v.begin(), v.end(), comparer);

    cout << "\nafter" << endl;
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i].id << " " << v[i].name << endl;
    return 0;

}
