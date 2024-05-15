#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>   
#include <unistd.h>   
	
typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
    int rem_time;
    int priority;
}Process;
	
Process* Entry()
{
    printf("No. of Processes:");
    int n;
    scanf("%d", &n);
    Process* p = (Process*) malloc( n+1 * sizeof(Process) );
    printf("Enter PID, Arrival Time, Burst Time, Priority\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d :",i+1);
        scanf("%d %d %d %d", &p[i].pid, &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].rem_time=p[i].burst_time;
    }
    p[n].pid=-1;
    return p;
}
void FCFS()
{
  Process *p= Entry();
  int n=0;
    while(p[n].pid!=-1)
        n++;
    int timer=0;
    float TAT=0;
    float WAT=0;
    for(int i=0;i<n;i++)
    {
      int start=timer;
     while(p[i].arrival_time<=timer && p[i].rem_time>0)
     { 
       timer++;
       p[i].rem_time--;
     }
