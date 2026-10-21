#include <stdio.h>

int main()
{
    int n, i, j;
    int at[20], bt[20], wt[20], tat[20];
    int ct[20], completed[20];
    int time = 0, count = 0;
    int shortest;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        completed[i] = 0;
    }

    while (count < n)
    {
        shortest = -1;

        /* Find the process with shortest burst time */
        for (i = 0; i < n; i++)
        {
            if (completed[i] == 0 && at[i] <= time)
            {
                if (shortest == -1 || bt[i] < bt[shortest])
                {
                    shortest = i;
                }
            }
        }

        /* If no process has arrived */
        if (shortest == -1)
        {
            time++;
        }
        else
        {
            /* Execute the selected process completely */
            time = time + bt[shortest];

            ct[shortest] = time;

            tat[shortest] = ct[shortest] - at[shortest];

            wt[shortest] = tat[shortest] - bt[shortest];

            completed[shortest] = 1;
            count++;
        }
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i],
               wt[i], tat[i]);

        avg_wt = avg_wt + wt[i];
        avg_tat = avg_tat + tat[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}