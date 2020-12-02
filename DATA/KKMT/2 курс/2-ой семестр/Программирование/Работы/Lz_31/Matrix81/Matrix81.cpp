/**Matrix81. Дана квадратная матрица A порядка M. Найти среднее арифметическое элементов ее побочной диагонали, т. е. диагонали, содержащей следующие элементы:
	A1,M,    A2,M−1,    A3,M−2,    …,    AM,1.
*/
//Решение. Герасимов Д.А., 13.05.2020

#include <iostream>
using namespace std;
int main(){
	const size_t MAXN = 100;
	size_t m;
	cout << "Input M: ";
	cin >> m;
	int mtrx[MAXN][MAXN];
	cout << "Input mtrx MxM:" << endl;
	for (size_t i = 0; i < m; ++i)		//-----------
		for (size_t j = 0; j < m; ++j)	//Input mtrx
			cin >> mtrx[i][j];	//-----------

	
	double sum = 0.;
	for (size_t i = 0, j = m; i != m; ++i){
		sum += mtrx[i][--j];
		//cout << mtrx[i][j] << ' ';
	}


	cout << endl << "Output:" << endl;
	cout << "Arithmetical mean = " << sum / m << endl; 

	return 0;
}
