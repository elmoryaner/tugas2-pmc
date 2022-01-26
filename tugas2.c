// Nama: Elmo Ryaner Panggabean
// NIM : 13220012
// Tugas 2 EL2008

#include<stdio.h>

void main()
{
    int i, proc, x, quantum, total = 0, count = 0;
    int t_queue = 0, t_turnaround = 0, t_arrival[10], t_burst[10], temp[10];
    float avg_t_queue, avg_t_turnaround;

    printf("Round Robin Scheduler\n");

    printf("\nTotal Number of Processes: ");
    scanf("%d", &proc);
    x = proc;

    for(i = 0; i < proc; i++)
    {
        printf("\nProcess %d details", i + 1);
        printf("\nArrival Time: ");
        scanf("%d", &t_arrival[i]);
        printf("Burst Time: ");
        scanf("%d", &t_burst[i]);
        temp[i] = t_burst[i];
    }

    printf("\nTime Quantum: ");
    scanf("%d", &quantum);
    printf("\nProcess ID\t\tBurst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");

    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= quantum && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if(temp[i] > 0)
        {
            temp[i] = temp[i] - quantum;
            total = total + quantum;
        }
        if(temp[i] == 0 && count == 1)
        {
            x--;
            printf("Process[%d]\t\t%d\t\t %d\t\t\t %d\t\t\t %d\n", i + 1, t_burst[i], total, total - t_arrival[i], total - t_arrival[i] - t_burst[i]);
            t_queue = t_queue + total - t_arrival[i] - t_burst[i];
            t_turnaround = t_turnaround + total - t_arrival[i];
            count = 0;
        }
        if(i == proc - 1)
        {
            i = 0;
        }
        else if(t_arrival[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    avg_t_queue = t_queue * 1.0 / proc;
    avg_t_turnaround = t_turnaround * 1.0 / proc;
    printf("\nAverage Waiting Time: %f", avg_t_queue);
    printf("\nAverage Turnaround Time: %f", avg_t_turnaround);
    return 0;
}
