#include <stdio.h>

void bubble_sort(int*, int);

int main() {
    int a[10] = {10, 8, 6, 7, 2, 9, 4, 3, 2, 1};
    printf("Before\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    bubble_sort(a, 10);
    printf("\nAfter \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void bubble_sort(int* a, int l) {
    for (int i = 0; i < l - 1; i++) {
        for (int j = l - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}
