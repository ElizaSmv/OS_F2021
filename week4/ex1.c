#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int n = rand() % 100;
    int pid;
    pid = fork();
    if (pid != 0) {
        printf("Hello from parent %d - %d\n", pid, n);
    }
    else {
        printf("Hello from child %d - %d\n", pid, n);
    }
    return 0;

}
