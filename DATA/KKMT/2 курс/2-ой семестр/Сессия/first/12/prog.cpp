#include <iostream>

int main(){
    int y=0;
    for(int i=0; i<100; ++i){
        for(int j=0; j<100; ++i){
            if (i==20){
                y = 1;
                break;
            }
            if (j == 10) continue;
        }
        if(y == 1) break;
    }
    return 0;
}
