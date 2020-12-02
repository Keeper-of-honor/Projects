/**Matrix2. Даны целые положительные числа M и N. Сформировать целочисленную матрицу размера M × N, у которой все элементы J-го столбца имеют значение 5·J (J = 1, …, N).*/
//Решение. Герасимов Д.А., 13.05.2020

#include <iostream>
using namespace std;
int main(){
	const size_t MAXN = 100;
	size_t m, n;
	cout << "Input m and n: ";
	cin >> m >> n;
	int mtrx[MAXN][MAXN];
	for (size_t i = 0; i < m; ++i){
		for (size_t j = 0; j < n; ++j){
			int elem = 5 * j;
			mtrx[i][j] = elem;
		}
	}

	for (size_t i = 0; i < m; ++i){
		for (size_t j = 0; j < n; ++j)
			cout << mtrx[i][j] << ' ';
		cout << endl;
	}

	return 0;
}
