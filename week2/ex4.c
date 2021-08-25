#include <stdio.h>
void swap(int*, int*);

int main() {
    int a, b;
    printf("Input:\na = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    swap(&a, &b);
    printf("After swap:\na = %d\nb = %d\n", a, b);
    return 0;
}
void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
