#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>

int main(){
        FILE *in_file;
        in_file = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
        struct input_event str;
        if(in_file == NULL)
        {
        fprintf(stderr, "\nCan't open the given file\n");
        exit(1);
        }
        while(fread(&str, sizeof(struct input_event), 1, in_file)) {
        if (str.type == EV_KEY && (str.value == 0 || str.value == 1)) {
            if (str.value == 1) {
                printf("PRESSED ");
            } else if (str.value == 0) {
                printf("RELEASED ");
            }
            printf("0x%04X (%d)\n", str.code, str.code);
        }
    }
    return 0;
};
