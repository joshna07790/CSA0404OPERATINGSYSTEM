#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];
    long position;

    fp = fopen("foo.txt", "w+");

    if (fp == NULL) {
        printf("File opening failed\n");
        return 1;
    }

    fprintf(fp, "Operating System Lab");
    printf("Data written successfully\n");

    fseek(fp, 0, SEEK_SET);
    fgets(text, sizeof(text), fp);
    printf("File content: %s\n", text);

    position = ftell(fp);
    printf("File position: %ld\n", position);

    fclose(fp);
    return 0;
}