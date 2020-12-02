/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void printMas(size_t number_str, const int COLS, int mas[]){
    //size_t start_str = number_str * COLS;
    for (size_t i = 0; i != COLS; ++i)
        cout << mas[i] << " ";
    cout << endl;
    mas[0] = 123;
}

void printMtrx (const int COLS, const int ROWS, int mtrx[]){
    for (int i = 0; i != ROWS; ++i){
        for (int j = 0; j != COLS; ++j)
            cout << mtrx[i*COLS + j] << " ";
        cout << endl;
    }
    size_t number_str = 1;
    printMas(number_str, COLS, &mtrx[number_str * COLS]);
}

int main()
{
    const int ROWS = 4;
    const int COLS = 3;
    
    int mtrx[ROWS][COLS] = {0};
    
    //Fill the mtrx
    unsigned int count = 0;
    for (int i = 0; i != ROWS; ++i)
        for (int j = 0; j != COLS; ++j)
            mtrx[i][j] = ++count;
    
    printMtrx(COLS, ROWS, &mtrx[0][0]);
    
    for (int i = 0; i != ROWS; ++i){
        for (int j = 0; j != COLS; ++j)
            cout << mtrx[i][j] << " ";
        cout << endl;
    }
    

    return 0;
}

