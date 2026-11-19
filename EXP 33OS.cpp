#include <stdio.h>

int main() {
    int pages[20], frames[10];
    int n, f, i, j, k, found, pos, farthest, next, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < f; j++)
            if (frames[j] == pages[i])
                found = 1;

        if (!found) {
            pos = -1;

            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) {
                farthest = -1;
                pos = 0;

                for (j = 0; j < f; j++) {
                    next = n;

                    for (k = i + 1; k < n; k++) {
                        if (pages[k] == frames[j]) {
                            next = k;
                            break;
                        }
                    }

                    if (next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        printf("Page %d: ", pages[i]);
        for (j = 0; j < f; j++) {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}