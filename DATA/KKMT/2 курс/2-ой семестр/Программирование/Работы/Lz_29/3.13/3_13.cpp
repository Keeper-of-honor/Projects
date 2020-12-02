/** Упражнение 3.13. Прочитайте в вектор набор целых чисел. Вычислите и отобразите сумму каждой пары смежных элементов в векторе.
Если количество элементов нечетно, сообщите пользователю об этом и отобразите значение последнего элемента без суммирования.
Измените программу так, чтобы она отобразила сумму первого и последнего элементов, затем сумму второго и предпоследнего и т.д. */
//Выполнил: Герасимов Д.А., П1-18
#include <iostream>
#include <vector>
using std::vector;


int main() {
  int n, x;
  vector <int> ivec;
	std::cout << "Input amount of elements: ";
	std::cin >> n;
	std::cout << "Input digitals: ";

    for(int i = 0; i < n; ++i){
	std::cin >> x;
	ivec.push_back(x);
    }
    std::cout << std::endl;

    if (ivec.size() % 2 == 1)
	    std::cout << "The number of elements is odd. Last element is equal: "  << ivec[ivec.size() - 1];
    else{
	std::cout << "Sum of adjacent elements: ";
	for(vector<int>::size_type iz = 0; iz != ivec.size(); iz += 2)
		std::cout << ivec[iz] + ivec[iz + 1] << " ";
    }
    std::cout << std::endl;
    std::cout << "Other amount: ";

    for(vector<int>::size_type ix = 0; ix != ivec.size() / 2; ++ix)
    	std::cout << ivec[ix] + ivec[ivec.size() - ix - 1] << ' ';

    std::cout << std::endl;
    return 0;
}
