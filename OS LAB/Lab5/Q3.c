#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>
#include<stdlib.h>
#define MAX 15

int main(void)
{
	printf("Enter the number of strings to read: ");
	int n;
	scanf("%d",&n);
	getchar();
	char strs[MAX][MAX];
	for(int i = 0; i<n; i++)
	{
		printf("Enter string %d: ",i);
		fgets(strs[i],MAX,stdin);
	}
	pid_t fork1 = fork();
	if(fork1==0) 
	{
		printf("SORTED STRINGS USING BUBBLESORT: \n");
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n-i-1; j++)
			{
				if(strcmp(strs[j],strs[j+1])>0)
				{
					char temp[20];
					strcpy(temp,strs[j]);
					strcpy(strs[j],strs[j+1]);
					strcpy(strs[j+1],temp);
				}
			}
		} 
		for(int i = 0; i<n; i++)
			puts(strs[i]);
	}
	else
	{
		int status1;
		wait(&status1);
		pid_t fork2 = fork();
		if(fork2==0) 
		{
			int min_idx;
			printf("SORTED STRINGS USING SELECTIONSORT: \n");
		    for(int i = 0; i< n; i++)
		    {
		    	min_idx = i;	
		    	strcpy(minStr,strs[i]);
		    	for(int j = i+1; j<n; j++)
		    	{
		    		if(strcmp(strs[j],strs[min_idx])>1)
		    		{
		    			strcpy(minStr, strs[j]);
		    			min_idx = j;
		    		}
		    		if(min_idx != i)
		    		{
		    			char temp[20];
		    			strcpy(temp,strs[min_idx]);
		    			strcpy(strs[min_idx],strs[i]);
		    			strcpy(strs[i],strs[min_idx]);
		    		}
		    	}
		    }
		  	for(int i = 0; i<n; i++)
				puts(strs[i]);
			printf("after SELECTIONSORT\n");
		}
	}
}
