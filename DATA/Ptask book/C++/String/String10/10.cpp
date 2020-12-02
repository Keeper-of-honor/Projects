/**String10°. Дана строка. Вывести строку, содержащую те же символы, но расположенные в обратном порядке.*/

#include <iostream>
#include <string>

using namespace std;

int main(){
        string s1;
        string s2;

	cout << "Enter string: ";
        getline(cin, s1);

        for (int i = s1.size(), j = 0; i >= 0; --i, ++j)
            s2 += s1[i];

        cout << "Replace string: " << s2 << endl;

        return 0;
}

