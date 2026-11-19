#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char text[100];

    fp = fopen("sample.txt", "w");
    if (fp == NULL) {
        printf("File creation failed\n");
        return 1;
    }

    fprintf(fp, "Hello, Operating Systems!");
    fclose(fp);
    printf("File created and data written successfully.\n");

    fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("File opening failed\n");
        return 1;
    }

    fgets(text, sizeof(text), fp);
    printf("File content: %s\n", text);
    fclose(fp);

    if (remove("sample.txt") == 0)
        printf("File deleted successfully.\n");

    return 0;
}