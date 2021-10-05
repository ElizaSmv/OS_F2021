#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 15; // s is hello world has 15 symbols
    char **s = malloc(n * sizeof(char *));
    for (int i=0; i < n; i++){
        s[i] = malloc(n * sizeof(char));
    }
    char foo[] = "Hello World";

    printf("s is ");
    for (int i = 0; i < n && foo[i] != '\0'; i++) {
        s[i][0] = foo[i];
        putchar(s[i][0]);
    }
    putchar('\n');
    strcpy(s[0], foo);
    printf("s[0] is %s\n", s[0]);
    for (int i = 0; i < n; i++) {
        printf("%s\n", s[i]); // Check array
    }
    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
    return(0);
}
