/**Matrix8. Дана матрица размера M × N и целое число K (1 ≤ K ≤ N). Вывести элементы K-го столбца данной матрицы.*/
//Решение. Герасимов Д.А., 13.05.2020

#include <iostream>
using namespace std;
int main(){
	const size_t MAXN = 100;
	size_t m, n, k;
	cout << "Input M and N: ";
	cin >> m >> n;
	cout << "Input mtrx MxN:" << endl;
	int mtrx[MAXN][MAXN];

	for (size_t i = 0; i < m; ++i)
		for (size_t j = 0; j < n; ++j)
			cin >> mtrx[i][j];
	cout << "Input k: ";
	cin >> k;

	cout << endl << "Output:" << endl;
	for (size_t i = 0; i < m; ++i)
		cout << mtrx[i][k-1] << ' ';
	cout << endl;

	return 0;
}
