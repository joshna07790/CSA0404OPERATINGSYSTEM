#include <stdio.h>

int main() {
    int start, length, i;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks: ");
    scanf("%d", &length);

    printf("File allocated sequentially:\n");

    for (i = 0; i < length; i++)
        printf("Block %d\n", start + i);

    return 0;
}