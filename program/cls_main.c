//
// Created by joao.chamine on 25/01/2021.
//

#include <stdio.h>
#include <dirent.h>
#include <string.h>

void permissions(const char *args);

int main(int argc, const char **argv) {
    char error[256];

    if (argc != 2)
    {
        argv[1] = ".";
    }
    // opendir() returns a pointer of DIR type.
    DIR *dr = opendir(argv[1]);
    if (dr == NULL)
    {
        strcpy(error, "Folder -> ");
        strcat(error, argv[1]);
        perror(error);
        return 1;
    }
    permissions(argv[1]);
    return 0;
}