#include<stdio.h>
int main() {
   int max[20][20],allocation[20][20],need[20][20],available[20],finish[20],safe[20],i,j,p,r;
   printf("Enter the no of processes and resources");
   scanf("%d%d",&p,&r);
   printf("Enter values of Allocation matrix:");
   for(i=0;i<p;i++)
      {
          for(j=0;j<r;j++)
           {
               scanf("%d",&allocation[i][j]);
           }
      }
   printf("Enter values of Max Matrix:");
   for(i=0;i<p;i++)
      {
          for(j=0;j<r;j++)
           {
               scanf("%d",&max[i][j]);
            }
      }
   printf("Enter available resources");
   for(i=0;i<r;i++)
       {
           scanf("%d",&available[i]);
       }
      for(i=0;i<p;i++)
      {
          for(j=0;j<r;j++)
           {
               need[i][j]=max[i][j]-allocation[i][j];
           }
      }
   for (i=0;i<p;i++) {
        finish[i]=0;
        safe[i]=0;
    } 
   int set=0;

   while(safe[p-1]==0)
     {  
        for(i=0;i<p;i++)
           { 
            if(finish[i]==0)
                 {   
                  int flag = 0; 
                  for (j = 0; j < r; j++) {
                    if (need[i][j] > available[j]){ 
                        flag = 1; 
                         break; 
                    } 
                } 
  
                if (flag == 0) { 
                    safe[set++]=i+1;
                    for(j=0;j<r;j++)
                        available[j] += allocation[i][j];
                    finish[i] = 1;
                }
             }
           }
     }
   printf("Safe Sequence is \n");
    for (i=0; i<p-1;i++)
        printf("P%d -> ",safe[i]-1);
     printf("P%d", safe[p - 1]-1); 
    
}
