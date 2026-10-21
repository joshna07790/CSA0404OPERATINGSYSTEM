#include <stdio.h>

int main()
{
    int n, i;
    int bt[20], rt[20], wt[20], tat[20];
    int quantum;
    int time = 0;
    int done;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter burst time for each process:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        wt[i] = 0;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);

    /* Round Robin execution */
    do
    {
        done = 1;

        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0)
            {
                done = 0;

                if (rt[i] > quantum)
                {
                    time = time + quantum;
                    rt[i] = rt[i] - quantum;
                }
                else
                {
                    time = time + rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }

    } while (done == 0);

    /* Calculate Turnaround Time */
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];

        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}