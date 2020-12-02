#include <iostream>

using namespace std;

int main(){
    /**Размер типов данных*/
    cout << sizeof(int) << ' ' << sizeof(1) << ' ' << sizeof(1L) << ' ' << sizeof(0.1) << ' ' << sizeof(char) << ' ' << sizeof('a') << endl;

  	bool boolean = 25; // переменная типа bool с именем boolean
    if ( boolean ) // условие оператора if
        cout << "true = "  << boolean << endl; // выполнится в случае истинности условия
    else
        cout << "false = " << boolean << endl; // выполнится в случае, если условие ложно

    int a = 1, b = 0;
    cout << "a: " << ++a << endl;
    cout << "b: " << b++ << endl;
    cout << "b: " << b++ << endl;
    /**
        i++ Это увеличение переменной i на 1 после проведенного действия
        ++i Это увеличение переменной i на 1 перед проведенным действием
        i-- Это уменьшение переменной i на 1 после проведенного действия
        --i Это уменьшение переменной i на 1 перед проведенным действием
            в основном используется в циклах
    */
    float c;
    c = 1 / 2;
    cout << "c: " << c << endl;

    float cd;
	a = 1;
	b = 2;
    cd = a / b;
    cout << "c: " << cd << endl;

    return 0;

}

