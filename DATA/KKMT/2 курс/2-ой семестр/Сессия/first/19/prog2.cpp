#include <iostream>

struct Point{
    int x, y;
};

void f1(struct Point parm_x, struct Point parm_y);

int main(){
    struct Point arg_x, arg_y;    /* объявление arg */
    arg_x.x = 1000;
    arg_y.y = 3432;
    f1(arg_x, arg_y);
    return 0;
}

void f1(struct Point parm_x, struct Point parm_y){
    printf("%d", parm_x.x);
    printf("%d", parm_y.x);
}
