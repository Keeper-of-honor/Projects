/**
Из файла input.txt сканировать имя и вывести в output.txt
Вывод:
    "Hi, <имя>"
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string name;
    
    ifstream input("input.txt");
    input >> name;
    
    ofstream output("output.txt");
    output << "Hi, " << name << endl;
    
    return 0;
}

