#include<stdio.h>
  
void waitingTime(int processes[], int n,int bt[], int wt[])
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}
  
void turnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
  
void avgTime( int processes[], int n, int bt[])
{
    int wt[1000], tat[1000], total_wt = 0, total_tat = 0;
  
    waitingTime(processes, n, bt, wt);
  
    turnAroundTime(processes, n, bt, wt, tat);
  
    printf("Processes   Burst time   Waiting time  Turn around time\n");
  
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("  %d \t\t %d \t %d \t\t %d \n", i+1, bt[i],wt[i], tat[i]) ;
    }
  
    printf("Average waiting time = %f",(float)total_wt / (float)n,"\nAverage turn around time = %f",(float)total_tat / (float)n);
}
  
int main()
{
    int processes[] = { 1, 2, 3};
    int n = sizeof(processes) / sizeof (processes[0]);
  
    int  burst_time[] = {10, 5, 8};
  
    avgTime(processes, n,  burst_time);
    return 0;
}