#include<stdio.h>

int main()
{
    int n, q, BT[100], CT[100], TT[100], temp[100], WT[100];
    float t = 0;
    float w = 0;
    int i = 0, j = 0, count = 0, sum = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter time quantum: ");
    scanf("%d", &q);
    printf("\nEnter the Burst Time of each process:\n");

    for (i = 0; i < n; i++) 
    {
        scanf("%d", &BT[i]);
        temp[i] = BT[i];
    }

    i = 0;

    while (1) 
    {
        for (i = 0, count = 0; i < n; i++) 
        {
            if (BT[i] > q) 
            {
                break;
            }
        }
        if (count == n) 
        {
            break;
        }
    }

    for (i = 0; i < n; i++) 
    {
        TT[i] = CT[i];
        WT[i] = TT[i] - temp[i];
        w += WT[i];
        t += TT[i];
    }

    float avgWT = w / n;
    float avgTAT = t / n;

    printf("\n");
    printf("\nProcess\t\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++) 
    {
        printf("\nP%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, temp[i], CT[i], TT[i], WT[i]);
    }
    printf("\nAverage Turn Around Time: %.2f\n", avgTAT);
    printf("\nAverage Waiting Time: %.2f\n", avgWT);

    return 0;
}
