#include <stdio.h>

void triangle(int);

int main(int args, char **argv) {
    int n;
    sscanf(argv[1], "%d", &n);
    triangle(n);
    printf("\n");
    return 0;
}
void triangle(int n) {
    int s = 2*n;
    for (int i = 1; i <= n; i++) {
        for (int i = 0; i < n; i++) {
            printf("_");
        }
        for (int j = 0; j < 2*i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}




