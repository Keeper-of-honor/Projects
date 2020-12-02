/**
С клавиатуры ввести строку, состоящую из нескольких слов, разделленных одним пробелом. Для хранения строки использовать новый тип данных TEXT,
введенный с помощью typedef. Написать функцию подсчёта количества слов в строке.
*/

#include <iostream>

using namespace std;

const int MAXN = 100;
typedef char TEXT[MAXN];

int main(){
	size_t i = 0;

	TEXT str;
	cout << "Input string:" << endl;
	cin.get(str, MAXN);

	unsigned num_word = 0;
	unsigned num_gap = 0;
	for (i = 0; str[i] != '\0'; ++i){
        	if ((str[i] == ' ' || str[i] == '\t') && num_gap == 0){
			++num_word;
			++num_gap;
		}
		if (str[i] != ' ' && num_gap != 0)
			num_gap = 0;
	}
	if (str[i-1] != ' ')
		++num_word;

	cout << "Number of words per string: "<< num_word << endl;

	return 0;
}
