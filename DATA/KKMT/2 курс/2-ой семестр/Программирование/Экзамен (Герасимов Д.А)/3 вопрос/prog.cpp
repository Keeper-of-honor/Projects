/*
3. Дан файл целых чисел. Создать два новых файла, первый из которых содержит
положительные числа из исходного файла (в обратном порядке), а второй —
отрицательные (также в обратном порядке). Если положительные или
отрицательные числа в исходном файле отсутствуют, то соответствующий
результирующий файл оставить пустым.
*/
//Выполнил: Герасимов Д.А. П1-18. 23.06.2020

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream in("data.txt");
	vector <int> vdigits;
	int n;
	while (in >> n)
		vdigits.push_back(n);
	in.close();

	ofstream out_p("positive.txt");
	ofstream out_np("nopositive.txt");
	size_t size_vdigits = vdigits.size();
	for (int i = size_vdigits - 1; i >= 0; --i){
		if (vdigits[i] >= 0)
			out_p << vdigits[i] << ' ';
		else
			out_np << vdigits[i] << ' ';
	}
	out_p.close();
	out_np.close();

    return 0;
}

