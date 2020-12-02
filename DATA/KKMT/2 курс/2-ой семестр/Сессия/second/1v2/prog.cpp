/*1. Разработать АТД "Вектор". Дан вектор V1 целых чисел. Перенести нечетные числа в V2, четные - в V3. Отсортировать оба вектора, слить в V1. Пример <7,1,2,3,6,2> -> <1,3,7,2,2,6>
*/
#include <iostream>
#include <vector>

using namespace std;

//void sort(vector <int> &vec, size_t size_vec);

int main(){	
	cout << "Количество элементов:\n";
	size_t size_v1;
	cin >> size_v1;
	//v1 - числа
	int *v1 = new int[size_v1]; // Выделение памяти для массива

	size_t size_v2 = 0;
	size_t size_v3 = 0;
	cout << "Введите числа:\n";
	int elem;
	for (size_t i = 0; i != size_v1; ++i){
		cin >> elem;
		v1[i] = elem;
		//Нечетное
		if (elem % 2)
			++size_v2;
		//Четное
		else
			++size_v3;
	}

	// v2 - нечетные числа; v3 - четные числа;
	int *v2 = new int[size_v2]; // Выделение памяти для массива
	size_t i2 = 0;	//index v2
	int *v3 = new int[size_v3]; // Выделение памяти для массива
	size_t i3 = 0;	//index v3
	for (size_t i = 0; i != size_v1; ++i){
		//Нечетное
		if (v1[i] % 2){
			v2[i2] = v1[i];
			++i2;
		}
		//Четное
		else{
			v3[i3] = v1[i];
			++i3;
		}
	}
	
/*
	//Сортировка
	sort(v2, size_v2);
	sort(v3, size_v3);
*/

	int temp;
	for (size_t i = 0; i != size_v2; ++i)
		for (size_t j = 1; j != size_v2; ++j)
			if (v2[j - 1] > v2[j]){
				temp = v2[j - 1];
				v2[j - 1] = v2[j];
				v2[j] = temp;
			}

	for (size_t i = 0; i != size_v3; ++i)
		for (size_t j = 1; j != size_v3; ++j)
			if (v3[j - 1] > v3[j]){
				temp = v3[j - 1];
				v3[j - 1] = v3[j];
				v3[j] = temp;
			}

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

	delete [] v1; // очистка памяти
	delete [] v2; // очистка памяти
	delete [] v3; // очистка памяти

	return 0;
}
/*
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
*/
