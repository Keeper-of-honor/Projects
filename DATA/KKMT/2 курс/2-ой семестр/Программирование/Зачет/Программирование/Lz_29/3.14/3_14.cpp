/**Упражнение 3.14. Прочитайте некоторый текст, сохраняя каждое введенное слово как отдельный элемент вектора. 
Преобразуйте символы каждого слова в прописные. 
Отобразите преобразованные элементы вектора, выводя по восемь слов в строке.
*/
// Выполнил: Герасимов Д.А., П1-18

#include <iostream>
#include <string>
#include <vector>
using std::vector;

int main() {
    std::string s1, s2;
    s2 = '0';
    vector <std::string> svec;
   	std::cout << "Input string. End input, enter 0: ";
    	std::cin >> s1;
    while (s1 != s2){
	for(std::string::size_type i = 0; i != s1.size();i++)
		if(islower(s1[i]))
			s1[i] = toupper(s1[i]);

	svec.push_back(s1);
	std::cin >> s1;
    }
	std::cout << std::endl;
    for(vector<int>::size_type ix = 0; ix != svec.size(); ix++){
        if (ix % 8 == 0)
            std::cout << std::endl;
	std::cout << svec[ix] << " ";
    }
    std::cout << std::endl;
    return 0;
}
