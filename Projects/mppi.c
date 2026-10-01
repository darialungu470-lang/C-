#include <stdio.h>

void swap(int* a, int* b) {
    int c = *a; *a = *b; *b = c;
}

int main() {

    int a = 5, b =7;
    printf(" a = %d, b = %d\n", a, b);

    //po funkcie swap
    swap(&a,&b);
    printf(" Po funkcie swap: \n");
    printf(" a = %d, b = %d\n", a, b);

    return 0;
}








