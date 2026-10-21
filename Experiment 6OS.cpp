#include <stdio.h>

int main()
{
    int n, i, time = 0;
    int at[20], bt[20], rt[20], priority[20];
    int ct[20], wt[20], tat[20];
    int completed = 0;
    int highest, min_priority;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter Priority for P%d: ", i + 1);
        scanf("%d", &priority[i]);

        rt[i] = bt[i];
    }

    while (completed < n)
    {
        highest = -1;
        min_priority = 9999;

        /* Find highest priority process */
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] > 0)
            {
                if (priority[i] < min_priority)
                {
                    min_priority = priority[i];
                    highest = i;
                }
            }
        }

        /* If no process has arrived */
        if (highest == -1)
        {
            time++;
        }
        else
        {
            /* Execute process for one unit of time */
            rt[highest]--;
            time++;

            /* Process completed */
            if (rt[highest] == 0)
            {
                ct[highest] = time;
                completed++;
            }
        }
    }

    /* Calculate Turnaround Time and Waiting Time */
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\nProcess\tArrival\tBurst\tPriority\tCompletion\tWaiting\tTurnaround\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n",
               i + 1, at[i], bt[i], priority[i],
               ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}