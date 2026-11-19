#include <stdio.h>
#include <stdlib.h>

int main() {
    int request[20], n, head, i, seek = 0, distance;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Seek sequence: %d", head);

    for (i = 0; i < n; i++) {
        distance = abs(head - request[i]);
        seek += distance;
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time: %d\n", seek);
    return 0;
}