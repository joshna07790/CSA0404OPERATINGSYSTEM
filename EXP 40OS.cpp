#include <stdio.h>
#include <sys/stat.h>

int main() {
    FILE *fp;
    char filename[] = "file.txt";

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("File creation failed\n");
        return 1;
    }

    fprintf(fp, "Linux file permissions");
    fclose(fp);

    if (chmod(filename, S_IRUSR | S_IWUSR |
              S_IRGRP | S_IROTH) == 0) {
        printf("File created successfully\n");
        printf("File permissions changed successfully\n");
        printf("Owner: Read and Write\n");
        printf("Group: Read only\n");
        printf("Others: Read only\n");
    } else {
        perror("chmod");
        return 1;
    }

    return 0;
}