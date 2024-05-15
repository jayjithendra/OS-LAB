#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char* args[])
{
	int n = argc;
	char strings[20][20];
	for(int i = 0; i<argc; i++)
	{
		strcpy(strings[i],args[i]);
	}
	pid_t fork_id;
	fork_id = fork();
	if(fork_id==0) 
	{
		printf("Number of strings:%d \n",n);
		for(int i = 1; i<n ;i++)
			puts(strings[i]);
		printf("BEFORE SORTING\n");
		printf("SORTED STRINGS: \n");
		for(int i = 1; i<=n; i++)
		{
			for(int j = 1; j<n-i; j++)
			{
				if(strcmp(strings[j],strings[j+1])>0)
				{
					char temp[20];
					strcpy(temp,strings[j]);
					strcpy(strings[j],strings[j+1]);
					strcpy(strings[j+1],temp);
				}
			}
		} 

		for(int i = 1; i<n ;i++)
			puts(strings[i]); 
	}

	else if(fork_id>0) 
	{
		int status;
		wait(&status);
		printf("UNSORTED STRINGS: \n");
		for(int i = 1; i<n ;i++)
			puts(strings[i]);
	}
}
