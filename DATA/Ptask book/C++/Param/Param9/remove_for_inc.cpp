/**
 Param9. Описать процедуру RemoveForInc(A, N), удаляющую из вещественного массива A размера N «лишние» элементы так, чтобы оставшиеся элементы оказались упорядоченными по возрастанию: первый элемент не удаляется, второй элемент удаляется, если он меньше первого, третий — если он меньше предыдущего элемента, оставленного в массиве, и т. д. Например, массив 5.5, 2.5, 4.6, 7.2, 5.8, 9.4 должен быть преобразован к виду 5.5, 7.2, 9.4. Массив A и число N являются входными и выходными параметрами. С помощью этой процедуры преобразовать массивы A, B, C размера NA, NB, NC соответственно и вывести размер и содержимое полученных массивов.
*/

/// Выполнил Герасимов Д.А., П1-18, 20.05.20

#include <iostream>
#include <vector>

using namespace std;

void RemoveForInc(vector <double> *vec, size_t vec_size){
	///Объявляем локальный вектор loc_vec и кладем туда элементы вектора *vec
	vector <double> loc_vec;
	loc_vec.reserve(loc_vec.size() + vec->size());
	loc_vec.insert(loc_vec.begin(), vec->begin(), vec->end());
	
	///Magic
	size_t j = 0;
	size_t loc_size = vec_size;
	for (size_t i = 1; i != loc_size; ++i)
		if (loc_vec[i] <= loc_vec[j]){
			vec->erase(vec->begin() + i);
			loc_vec.erase(loc_vec.begin() + i);
			--i;
			--loc_size;
		}
		else
			++j;
		
}
