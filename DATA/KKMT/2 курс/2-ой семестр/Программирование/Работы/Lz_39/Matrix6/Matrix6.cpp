/**
Matrix6. Даны целые положительные числа M, N, число D и набор из N чисел. Сформировать матрицу размера M × N, у которой первая строка совпадает с исходным набором чисел, а элементы каждой следующей строки равны соответствующему элементу предыдущей строки, умноженному на D (в результате каждый столбец матрицы будет содержать элементы геометрической прогрессии).
 */

#include <iostream>

using namespace std;

int main(){

	cout << "Input M and N: ";
	size_t m, n;
	cin >> m >> n;
	int matrix[m][n];
	
	cout << "First string: ";
	int k;
	for (size_t i = 0; i != n; ++i){
		cin >> k;
		matrix[0][i] = k;
	}

	cout << "Input D: ";
	int d;
	cin >> d;
	cout << "Your matrix MxN:" << endl;
	for (size_t i = 0; i != n; ++i)
		cout << matrix[0][i] << ' ';
	cout << endl;
	for (size_t i = 1; i != m; ++i){
		for (size_t j = 0; j != n; ++j){
			matrix[i][j] = matrix[i-1][j] * d;
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
