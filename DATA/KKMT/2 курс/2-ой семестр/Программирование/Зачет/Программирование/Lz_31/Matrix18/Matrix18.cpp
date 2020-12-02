/**Matrix18. Дана матрица размера M × N и целое число K (1 ≤ K ≤ N). Найти сумму и произведение элементов K-го столбца данной матрицы.*/
//Решение. Герасимов Д.А., 13.05.2020

#include <iostream>
using namespace std;


int main(){
	const size_t MAXN = 100;
	size_t m, n, k;
	cout << "Input M and N: ";
	cin >> m >> n;
	cout << "Input mtrix MxN:" << endl;
	int mtrix[MAXN][MAXN];

	for(size_t i = 0; i != m; i++)		//-----------
		for(size_t j = 0; j != n; j++)	//Input mtrx
			cin >> mtrix[i][j];	//-----------
	cout  << "Input K: ";
	cin >> k;
	
	cout << endl << "Output: " << endl;
	int sum = 0, compos = 1;
	for(size_t i = 0; i < m; i++){		
		sum +=  mtrix[i][k - 1];	//Sum
		compos *= mtrix[i][k - 1];	//Composition
	}
	cout << "Sum = " << compos << endl
		<< "Composition = " << compos << endl;

    return 0;
}
