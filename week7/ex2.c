#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Size of array: ");
    scanf("%d", &N);
    printf("\n");
    if (N <= 0) {
        printf("Wrong size of array\n");
        EXIT_FAILURE;
    }
    int* arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        arr[i] = i;
        printf("prt[%d] = %d \n", i, arr[i]);
    }
    free(arr);
    return 0;
}
