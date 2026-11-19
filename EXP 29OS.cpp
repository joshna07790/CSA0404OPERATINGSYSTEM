#include <stdio.h>

int mutex = 1, full = 0, empty = 5, item = 0;

int main() {
    int choice;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (mutex == 1 && empty > 0) {
                mutex = 0;
                item++;
                full++;
                empty--;
                printf("Producer produces item %d\n", item);
                mutex = 1;
            } else {
                printf("Buffer is full\n");
            }
        } else if (choice == 2) {
            if (mutex == 1 && full > 0) {
                mutex = 0;
                printf("Consumer consumes item %d\n", item);
                item--;
                full--;
                empty++;
                mutex = 1;
            } else {
                printf("Buffer is empty\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}