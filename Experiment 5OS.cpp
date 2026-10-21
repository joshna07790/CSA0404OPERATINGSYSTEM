#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[20], wt[20], tat[20];
    int priority[20], p[20];
    int temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter burst time and priority for each process:\n");

    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;

        printf("\nP%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        printf("P%d Priority: ", i + 1);
        scanf("%d", &priority[i]);
    }

    /* Sort according to priority */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (priority[i] > priority[j])
            {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    /* Waiting time */
    wt[0] = 0;

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    /* Turnaround time */
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

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i], bt[i], priority[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}