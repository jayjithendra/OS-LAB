#include<stdio.h>
#include<stdlib.h>
void print(int x[][10],int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<m;j++){
			printf("%d\t",x[i][j]);
		}
	}	
}
void res_req(int A[][10],int R[10][10],int W[1][10],int pid,int *m)
{
   printf("enter request to be made for p%d ",pid);
   for(int j=0;j<*m;j++)
     scanf("%d",&R[pid][j]);
     }
int detection(int A[][10],int R[10][10],int W[1][10],int *n,int *m)
{
  int flag=0;
  int count =0;
  int F[10];
  for(int i=0;i<*n;i++)
     F[i]=0;
   for (int check=0;check<*n;check++)
   { 
     for(int i=0;i<*n;i++)
     {
       for(int j=0;j<*m;j++)
       {  
          if(R[i][j]>W[0][j])
             flag=1;
         }
         if(F[i] ==0 && flag==0)
          {  
             count++;
             printf(" p%d ",i+1);
             F[i]=1;
             flag=0;
             for(int k=0;k<*m;k++)
                W[0][k]+=A[i][k];
            }
         }
       if(count==*n)
        return 1;
    }
    return 0; 
    }     
void accept(int A[][10],int R[10][10],int W[1][10],int *n,int *m){
	int i,j;
	printf("\n Enter total no. of processes : ");
	scanf("%d",n);
	printf("\n Enter total no. of resources : ");
	scanf("%d",m);
	for(i=0;i<*n;i++){
		printf("\n Process %d\n",i+1);
		for(j=0;j<*m;j++){
			printf(" Allocation for resource %d : ",j+1);
			scanf("%d",&A[i][j]);
			printf(" Request for resource %d : ",j+1);
			scanf("%d",&R[i][j]);
		}
	}
	printf("\n Available resources : \n");
	for(i=0;i<*m;i++){
		printf(" Resource %d : ",i+1);
		scanf("%d",&W[0][i]);
	}

	

	printf("\n Allocation Matrix");
	print(A,*n,*m);
	printf("\n Maximum Request Matrix");
	print(R,*n,*m);
	

}
int main(){
	int ret;
	int A[10][10];
	int R[10][10];
	int W[1][10];
	int n,m,pid,ch;
	printf("\n DEADLOCK DETECTION ALGORITHM\n");
	accept(A,R,W,&n,&m);
	ret=detection(A,R,W,&n,&m);
	if(ret !=0 ){
		printf("\n Do you want make an additional request ? (1=Yes|0=No)");
		scanf("%d",&ch);
		if(ch == 1){
			printf("\n Enter process no. : ");
			scanf("%d",&pid);
			res_req(A,R,W,pid-1,&m);
			ret=detection(A,R,W,&n,&m);
			if(ret == 0 )
				exit(0);
		}
	}else
	printf("deadlock has occured");
		exit(0);
	return 0;
}

