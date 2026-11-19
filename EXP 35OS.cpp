#include <stdio.h>

int main() {
    int indexBlock, n, blocks[20], i;

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter file block numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("Index Block: %d\n", indexBlock);
    printf("File block allocation:\n");

    for (i = 0; i < n; i++)
        printf("Index[%d] -> Block %d\n", i, blocks[i]);

    return 0;
}