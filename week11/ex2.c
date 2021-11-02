#include <stdio.h>
#include <dirent.h>

int main (void)
{
    DIR *a;
    struct dirent *dir_iter;
    a = opendir("/");
    while ((dir_iter = readdir(a)) != NULL) {
        puts(dir_iter->d_name);
    }
    closedir(a);
    return 0;
}
