#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[20], wt[20], tat[20], p[20];
    int temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");

    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    /* Sort processes according to burst time */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    /* Waiting time of first process */
    wt[0] = 0;

    /* Calculate waiting time */
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    /* Calculate turnaround time */
    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    /* Calculate averages */
    for (i = 0; i < n; i++)
    {
        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}