#include<stdio.h>
int main(){
int i,n,wt[20],bt[20],tat[20],at[20],sumwt=0,sumtat=0,comp[20],total;
printf("enter the no.of processes");
scanf("%d",&n);
for(i=0;i<n;i++){
   printf("enter the burst time");
   printf("P[%d]=",i);
   scanf("%d",&bt[i]);
   printf("enter the arrival time");
   printf("P[%d]=",i);
   scanf("%d",&at[i]);
}
for(i=0;i<n;i++){
    total+=bt[i];
    comp[i]+=total;
}
for(i=0;i<n;i++)
{
  tat[i]=comp[i]-at[i];
  wt[i]=tat[i]-bt[i];
  sumwt+=wt[i];
  sumtat+=tat[i];
}
printf("\n\n process \t Burst Time \t arrival time \t Waiting Time \t Turn Around Time  \n");
for(i=0;i<n;i++)
    printf("\n  p[%d] \t\t %d  \t\t %d \t\t %d \t\t %d \t\t ",i,bt[i],at[i],wt[i],tat[i]);
    printf("\n Average Waiting Time : %f \n",(float)sumwt/(float)n);
    printf("\n Average Turn Around Time : %f \n",(float)sumtat/(float)n);
    return 0;
}
