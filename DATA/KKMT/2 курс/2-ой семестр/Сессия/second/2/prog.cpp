 
/** 2. Разработать АТД "Вектор". Даны два упорядоченных по возрастанию вектора целых чисел. Слить их в один, не меняя порядка.
*/
#include <vector>
#include <iostream>

using namespace std;
int main()
{
    vector <int> ivec1,ivec2;
    vector <int> ivec;
    ivec1 = {1, 3,5};
    ivec2 = {2, 4,6};
    for (size_t i = 0; i<ivec1.size() || i<ivec2.size(); i++)
    {
        if (ivec1.size() != i)
            ivec.push_back(ivec1[i]);
        if (ivec1.size() != i)
            ivec.push_back(ivec2[i]);
    }
    for (size_t i = 0; i<ivec.size(); i++)
        cout << ivec[i] << " ";
    return 0;
}
