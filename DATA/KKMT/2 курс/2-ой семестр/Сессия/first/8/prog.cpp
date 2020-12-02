#include <iostream>


int main()
{
    const unsigned int DIM1 = 3;
    const unsigned int DIM2 = 5;

    int ary[DIM1][DIM2];

    for (int i = 0; i < DIM1; i++)
        for (int j = 0; j < DIM1; j++)
            ary[i][j] = (i + 1) * 10 + (j + 1);

    for (int i = 0; i < DIM1; i++){
        for (int j = 0; j < DIM1; j++)
            std::cout << ary[i][j] << ' ';
        std::cout << std::endl;
    }

    char month[12][10] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    return 0;
}
