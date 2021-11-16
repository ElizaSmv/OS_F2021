#include <stdio.h>

int main() {
    const int PROC = 5;
    const int RES = 3;

    int E[RES], A[RES], C[PROC][RES], R[PROC][RES];
    FILE *file;
    file = fopen("input.txt", "r");
    for(int i = 0; i < RES; i++) {
        fscanf(file, "%d", &E[i]);
    }
    for(int i = 0; i < RES; i++) {
        fscanf(file, "%d", &A[i]);
    }
    for(int i = 0; i < PROC; i++) {
        for(int k = 0; k < RES; k++) {
            fscanf(file, "%d", &C[i][k]);
        }
    }
    for(int i = 0; i < PROC; i++) {
        for(int k = 0; k < RES; k++) {
            fscanf(file, "%d", &R[i][k]);
        }
    }








    return 0;
};
