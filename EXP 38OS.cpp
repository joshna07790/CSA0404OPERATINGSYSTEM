#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[20], n, head, size, i, j, temp;
    int seek = 0, current;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    current = head;
    printf("Seek sequence: %d", head);

    for (i = 0; i < n; i++) {
        if (a[i] >= head) {
            seek += abs(current - a[i]);
            current = a[i];
            printf(" -> %d", current);
        }
    }

    seek += abs(current - (size - 1));
    current = size - 1;
    printf(" -> %d", current);

    for (i = n - 1; i >= 0; i--) {
        if (a[i] < head) {
            seek += abs(current - a[i]);
            current = a[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal Seek Time: %d\n", seek);
    return 0;
}