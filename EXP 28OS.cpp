#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], word[50], line[200];

    printf("Enter file name: ");
    scanf("%99s", filename);

    printf("Enter search word: ");
    scanf("%49s", word);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word) != NULL)
            printf("%s", line);
    }

    fclose(fp);
    return 0;
}