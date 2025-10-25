#include <stdio.h>
void main() {
    int n, quantum, i, t = 0, done;
    float awt = 0, atat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int p[n], bt[n], rbt[n], wt[n], tat[n], ct[n];
    int timeline[100], index = 0;

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter the burst time of process P%d: ", p[i]);
        scanf("%d", &bt[i]);
        rbt[i] = bt[i];
        wt[i] = 0;
    }
 
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("\nGantt Chart:\n ");
    while (1) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (rbt[i] > 0) {
                done = 0;
                printf("    P%d\t", p[i]);
                if (rbt[i] > quantum) {
                    t += quantum;
                    rbt[i] -= quantum;
                } else {
                    t += rbt[i];
                    ct[i] = t;
                    rbt[i] = 0;
                }
                timeline[index++] = t;
            }
        }
        if (done == 1) break;
    }

    printf("\n0");
    for (i = 0; i < index; i++) {
        printf("\t\t%d", timeline[i]);
    }

    printf("\n\nProcess ID\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], tat[i], wt[i]);
    }
    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", atat / n);
}