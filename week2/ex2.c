#include <stdio.h>
#include <string.h>
#define SIZE 100
void reverse(char*);

int main() {
    char in[SIZE];
    printf("Input:\n");
    scanf("%s", in);
    printf("Output:\n");
    reverse(in);
    return 0;
}
void reverse(char* s) {
    int l = strlen(s);
    for (int i = l - 1; i >= 0; i--) {
        putchar(s[i]);
    }
}
