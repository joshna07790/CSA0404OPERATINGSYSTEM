#include <stdio.h>

void firstFit(int memory[], int process[], int n, int m)
{
    int allocation[m];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (memory[j] >= process[i])
            {
                allocation[i] = j;
                memory[j] -= process[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");

    for (int i = 0; i < m; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d (%d) -> Partition %d\n",
                   i + 1, process[i], allocation[i] + 1);
        else
            printf("Process %d (%d) -> Not Allocated\n",
                   i + 1, process[i]);
    }
}

void bestFit(int memory[], int process[], int n, int m)
{
    int allocation[m];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int best = -1;

        for (int j = 0; j < n; j++)
        {
            if (memory[j] >= process[i])
            {
                if (best == -1 || memory[j] < memory[best])
                    best = j;
            }
        }

        if (best != -1)
        {
            allocation[i] = best;
            memory[best] -= process[i];
        }
    }

    printf("\nBest Fit Allocation:\n");

    for (int i = 0; i < m; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d (%d) -> Partition %d\n",
                   i + 1, process[i], allocation[i] + 1);
        else
            printf("Process %d (%d) -> Not Allocated\n",
                   i + 1, process[i]);
    }
}

void worstFit(int memory[], int process[], int n, int m)
{
    int allocation[m];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int worst = -1;

        for (int j = 0; j < n; j++)
        {
            if (memory[j] >= process[i])
            {
                if (worst == -1 || memory[j] > memory[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            allocation[i] = worst;
            memory[worst] -= process[i];
        }
    }

    printf("\nWorst Fit Allocation:\n");

    for (int i = 0; i < m; i++)
    {
        if (allocation[i] != -1)
            printf("Process %d (%d) -> Partition %d\n",
                   i + 1, process[i], allocation[i] + 1);
        else
            printf("Process %d (%d) -> Not Allocated\n",
                   i + 1, process[i]);
    }
}

int main()
{
    int n, m, choice;
    int memory[20], process[20];
    int tempMemory[20];

    printf("Number of memory partitions: ");
    scanf("%d", &n);

    printf("Number of processes: ");
    scanf("%d", &m);

    printf("Enter the memory partitions:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &memory[i]);
    }

    printf("Enter process sizes:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &process[i]);
    }

    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Copy original memory partitions
    for (int i = 0; i < n; i++)
    {
        tempMemory[i] = memory[i];
    }

    switch (choice)
    {
        case 1:
            firstFit(tempMemory, process, n, m);
            break;

        case 2:
            bestFit(tempMemory, process, n, m);
            break;

        case 3:
            worstFit(tempMemory, process, n, m);
            break;

        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}