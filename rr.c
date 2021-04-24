#include<stdio.h>
int main(){
int p[10],bt[10],wt[10],flag,t=0,tat[10],rembt[10],i,j,n,sumwt=0,sumtat=0,timeslice;
printf("Enter the number of Processes \n"); 
scanf("%d",&n);
printf("Enter the Timeslice"); 
scanf("%d",&timeslice); 
for(i=0;i<=n-1;i++)
{
printf("Enter the Burst Time for the process p[%d]",i);
scanf("%d",&bt[i]);
rembt[i]=bt[i];
}
for(i=0;i<n;i++){
    wt[i]=0;
    while(n!=0){
    flag=1;
    for(i=0;i<n;i++){
       if(rembt[i]>0){
       flag=0; 
       if(rembt[i]>timeslice){
         t+=timeslice;
         rembt[i]-=timeslice;
       }
       else{
         t+=rembt[i];
         rembt[i]=0;
         wt[i]=t-bt[i];
       }
    }
  }
 if(flag==1)
 break;
}
}
for(i=0;i<n;i++)
{
  tat[i]=bt[i]+wt[i];
  sumwt+=wt[i];
  sumtat+=tat[i];
}
printf("\n\n process \t Burst Time \t Waiting Time \t Turn Around Time  \n");
for(i=0;i<n;i++)
    printf("\n  p[%d] \t\t %d  \t\t %d \t\t %d \t\t ",i,bt[i],wt[i],tat[i]);
    printf("\n Average Waiting Time : %f \n",(float)sumwt/(float)n);
    printf("\n Average Turn Around Time : %f \n",(float)sumtat/(float)n);
    return 0;
}
