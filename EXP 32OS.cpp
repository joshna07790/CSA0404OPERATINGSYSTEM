#include <stdio.h>

int main() {
    int pages[20], frames[10], recent[10];
    int n, f, i, j, k, found, pos, faults = 0, time = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        frames[i] = -1;
        recent[i] = 0;
    }

    for (i = 0; i < n; i++) {
        found = 0;
        time++;

        for (j = 0; j < f; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                recent[j] = time;
                break;
            }
        }

        if (!found) {
            pos = -1;

            for (j = 0; j < f; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) {
                pos = 0;
                for (j = 1; j < f; j++)
                    if (recent[j] < recent[pos])
                        pos = j;
            }

            frames[pos] = pages[i];
            recent[pos] = time;
            faults++;
        }

        printf("Page %d: ", pages[i]);
        for (k = 0; k < f; k++) {
            if (frames[k] == -1)
                printf("- ");
            else
                printf("%d ", frames[k]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}