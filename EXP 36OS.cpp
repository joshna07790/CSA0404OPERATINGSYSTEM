#include <stdio.h>

int main() {
    int blocks[20], n, i;

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("Linked file allocation:\n");

    for (i = 0; i < n - 1; i++)
        printf("%d -> ", blocks[i]);

    printf("%d -> NULL\n", blocks[n - 1]);

    printf("First block: %d\n", blocks[0]);
    printf("Last block: %d\n", blocks[n - 1]);

    return 0;
}