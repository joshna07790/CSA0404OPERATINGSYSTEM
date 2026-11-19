#include <stdio.h>

int main() {
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int m = 5, n = 4;
    int i, j, best;

    for (i = 0; i < n; i++) {
        best = -1;

        for (j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if (best != -1) {
            printf("Process %d allocated to block %d\n",
                   i + 1, best + 1);
            block[best] -= process[i];
        } else {
            printf("Process %d not allocated\n", i + 1);
        }
    }

    return 0;
}