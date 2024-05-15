#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
int main()
{
	int status;
	int pid;
	pid=fork();
	if(pid<0)
	{
		printf("error");
		exit(1);
	}
	else if(pid==0)
	{
		printf("in child\n");
		printf("pid: %d ppid: %d \n",getpid(),getppid());
		exit(0);
	}
	else
	{
		printf("in parent\n");
		printf("pid: %d ppid: %d \n",getpid(),getppid());
		exit(1);
	}
}
