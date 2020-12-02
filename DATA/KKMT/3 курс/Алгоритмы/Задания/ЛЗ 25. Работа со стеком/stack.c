#include <stdio.h>
#define MAXVAL 100

int sp = 0;
int val[MAXVAL];
int pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0;
    }
}

void push(int f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full\n");
}

int main() {
    int top;
    push(1);
    top = pop();
    printf("%d ", top);
    push(top);
    push(2);
    top = pop();
    printf("%d ", top);
    push(top);
    return 0;
}
