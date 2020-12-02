/*1. Разработать АТД "Вектор". Дан вектор V1 целых чисел. Перенести нечетные числа в V2, четные - в V3. Отсортировать оба вектора, слить в V1. Пример <7,1,2,3,6,2> -> <1,3,7,2,2,6>
*/
#include <iostream>
#include <vector>

using namespace std;

void sort(vector <int> &vec, size_t size_vec);

int main(){
	vector <int> v1;	//v1 - числа
	vector <int> v2, v3;	// v2 - нечетные числа; v3 - четные числа;
	cout << "Количество элементов:\n";
	size_t size_v1;
	cin >> size_v1;
	cout << "Введите числа:\n";
	int elem;
	for (size_t i = 0; i != size_v1; ++i){
		cin >> elem;
		v1.push_back(elem);
		//Нечетное
		if (elem % 2)
			v2.push_back(elem);
		//Четное
		else
			v3.push_back(elem);
	}
	//Сортировка
	size_t size_v2 = v2.size();
	sort(v2, size_v2);

	size_t size_v3 = v3.size();
	sort(v3, size_v3);

	///Вывод
	cout << '<';
	for (size_t i = 0; i != size_v1 - 1; ++i){
		cout << v1[i] << ',';
	}
	cout << v1[size_v1 - 1] << '>';

	cout << " -> ";

	cout << '<';
	for (size_t i = 0; i != size_v2; ++i){
		v1[i] = v2[i];
		cout << v1[i] << ',';
	}
	for (size_t i = size_v2; i != size_v1 - 1; ++i){
		v1[i] = v3[i - size_v2];
		cout << v1[i] << ',';
	}
	v1[size_v1 - 1] = v3[size_v3 - 1];
	cout << v1[size_v1 - 1] << '>';

	cout << endl;

	return 0;
}

//Сортировка
void sort(vector <int> &vec, size_t size_vec){
	int temp;
	for (size_t i = 0; i != size_vec; ++i)
		for (size_t j = 1; j != size_vec; ++j)
			if (vec[j - 1] > vec[j]){
				temp = vec[j - 1];
				vec[j - 1] = vec[j];
				vec[j] = temp;
			}
}
