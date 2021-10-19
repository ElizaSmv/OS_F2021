#include <stdio.h>
#include <stdlib.h>

#define BUFFER 10

FILE *input;

int my_atoi(char* s) {
    int res = 0;
    int i = 0;
    while (s[i] != '\0') {
        res = res * 10 + (s[i++] - '0');
    }
    return res;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("No parameter error\n");
        exit(1);
    }
    int size = my_atoi(argv[1]);
    int page_frames[size];
    unsigned char count[size];
    for (int i = 0; i < size; i++) {
        page_frames[i] = 0;
        count[i] = 0;
    }
    input = fopen("Lab 09 input.txt", "r");
    char a;
    char s[BUFFER];
    int k = 0;
    int page;
    int pointer = 0;
    int hit = 0;
    int miss = 0;
    while ((a = fgetc(input)) != EOF) {
        if (a == ' ' || a == '\n') {
            // Read number
            s[k] = '\0';
            k = 0;
            page = my_atoi(s);
            int in_memory = 0;
            for (int i = 0; i < size; i++) {
                if (page_frames[i] == page) {
                    count[i] = count[i] / 2;
                    count[i] += 128;  
                    in_memory = 1;
                    hit++;
                }
                else {
                    count[i] = count[i] / 2;
                }
            }

            if (!in_memory) {
                if (pointer < size) {
                    page_frames[pointer++] = page;
                }
                else {
                    unsigned char min = count[0];
                    int index = 0;
                    for (int j = 0; j < size; j++) {
                        if (count[j] < min) {
                            min = count[j];
                            index = j;
                        }
                    }
                    page_frames[index] = page;
                    count[index] = 128;
                }
                miss++;
            }
        }
        else {
            s[k++] = a;
        }
    }
    fclose(input);
    printf("Hit ratio %.3f\nMiss ratio %.3f\n", (hit*1.0f)/(hit + miss), (miss*1.0f)/(hit + miss));
    return 0;

}
