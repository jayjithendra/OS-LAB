#include <stdio.h>
#include <stdlib.h>
void sort(int queue[],int n)
{  
    int temp;
   for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(queue[j]>queue[j+1]){
                temp=queue[j];
                queue[j]=queue[j+1];
                queue[j+1]=temp;
            }
        }
    }
}

int find(int queue[],int n,int key){
    for(int i=0;i<n;i++){
        if(queue[i]==key){
            return i;
        }
    }
    return -1;
}


int FCFS(int queue[],int n,int header){
    int otime=0;
    int prev=header;
    for(int i=0;i<n;i++){
        printf("%d -> %d    ",prev,queue[i]);
        int temp =(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        otime+=temp;
        prev=queue[i];
    }
    return otime;
}
int SSTF(int queue[],int n,int header){
    int visited[n];
    for(int i=0;i<n;i++)
      visited[i]=0;
    int sum=0;
    for(int i=0;i<n;i++){
        int min=999;
        int pos=-1;
        for(int j=0;j<n;j++){
            int dist=(header-queue[j]);
            if(dist<0){
                dist*=-1;
            }
            if(dist<min && !visited[j]){
                min=dist;
                pos=j;
            }
        }
        printf("%d -> %d    ",header,queue[pos]);
        visited[pos]=1;
        header=queue[pos];
        sum+=min;
    }
    return sum;
}

int SCAN(int queue[],int n,int header){
    sort(queue,n);
    int pos = find(queue,n,header);
    int prev=header;
    int sum=0;
    for(int i=pos;i>=0;i--){
        printf("%d -> %d    ",prev,queue[i]);
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    for(int i=pos+1;i<n;i++){
        printf("%d -> %d    ",prev,queue[i]);
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    return sum;
}
int CSCAN(int queue[],int n,int header){
    sort(queue,n);
    int pos = find(queue,n,header);
    int prev=header;
    int sum=0;
    for(int i=pos;i>=0;i--){
        printf("%d -> %d    ",prev,queue[i]);
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    //prev=queue[n-1];
    for(int i=n-1;i>=pos+1;i--){
        printf("%d -> %d    ",prev,queue[i]);
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    return sum;
}
int LOOK(int queue[],int n,int header){
    sort(queue,n);
    int pos = find(queue,n,header);
    int prev=header;
    int sum=0;
    for(int i=pos;i>=0;i--){
        printf("%d -> %d    ",prev,queue[i]);
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    for(int i=pos+1;i<n;i++){
        printf("%d -> %d    ",prev,queue[i]);
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    return sum;
}

int CLOOK(int queue[],int n,int header){
    sort(queue,n);
    int pos = find(queue,n,header);
    int prev=header;
    int sum=0;
    for(int i=pos;i>=0;i--){
        printf("%d -> %d    ",prev,queue[i]);
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    prev=queue[n-1];
    for(int i=n-2;i>=pos+1;i--){
        printf("%d -> %d    ",prev,queue[i]);
        int temp=(queue[i]-prev);
        if(temp<0){
            temp*=-1;
        }
        sum+=temp;
        prev=queue[i];
    }
    return sum;
}

int main(){
    int n;
    printf("Enter number of tracks: ");
    scanf("%d",&n);
    int queue[100];
    printf("Enter tracks: ");
    for(int i=0;i<n;i++){
        scanf("%d",&queue[i]);
    }
    int header,ch;
   printf("Enter header: ");
   scanf("%d",&header);
   printf("chose algorithm: 1.FCFS 2.SSTF 3.SCAN 4.C-SCAN 5.LOOK 6.C-LOOK \n");
   scanf("\n %d",&ch);
   switch(ch)
   {
   case 1 :
   printf("->\n Overhead time: %d ",FCFS(queue,n,header));
   break;
   case 2 :
   printf("->\n Overhead time: %d ",SSTF(queue,n,header));
   break;
   case 3 :
   queue[n]=header;
    queue[n+1]=0;
   printf("->\n Overhead time: %d ",SCAN(queue,n+2,header));
   break;
   case 4 :
   queue[n]=header;
    queue[n+1]=0;
   queue[n+2]=199;
   printf("->\n Overhead time: %d ",CSCAN(queue,n+3,header));
   break;
   case 5 :
   queue[n]=header;
   printf("->\n Overhead time: %d ",LOOK(queue,n+1,header));
   break;
   case 6:
   queue[n]=header;
     printf("->\n Overhead time: %d ",CLOOK(queue,n+1,header));
   break;
   }
   
    return 0;
}
//add seek time and sequence
