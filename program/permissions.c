#include "functions.h"
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

void permissions(const char *args) {
    struct dirent *de; // Pointer for directory entry
    struct stat fileStat;
    char fullpath[256];

    DIR *dr = opendir(args);
    while ((de = readdir(dr)) != NULL) {
        strcpy(fullpath, args);
        strcat(fullpath, "/");
        strcat(fullpath, de->d_name);
        if (!stat(fullpath, &fileStat)) {
            printf((S_ISDIR(fileStat.st_mode)) ? "(d" : "(-");
            printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
            printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
            printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
            printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
            printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
            printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
            printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
            printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
            printf((fileStat.st_mode & S_IXOTH) ? "x)" : "-)");
        }
        printf(" => [UID: %i] [GID: %i]", fileStat.st_uid, fileStat.st_gid);
        printf(" => %s\n", de->d_name);
    }
    closedir(dr);
    return;
}