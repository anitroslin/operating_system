#include<stdio.h>
int main(){
int p[20],bt[20],wt[20],at[20],tat[20],temp,n,i,j,sumwt=0,sumtat=0,tot=0,total=0,k=1,min,sum=0;
printf("enter the no.of processes");
scanf("%d",&n);
for(i=0;i<n;i++){
 printf("enter the burst time of p[%d] = ",i);
 scanf("%d",&bt[i]);
 printf("enter the arrival time of p[%d] = ",i);
 scanf("%d",&at[i]);
}
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(at[i]<at[j])
            {
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                temp=at[j];
                at[j]=at[i];
                at[i]=temp;
                temp=bt[j];
                bt[j]=bt[i];
                bt[i]=temp;
            }
        }
    }

    for(j=0;j<n;j++)
    {
        total=total+bt[j];
        min=bt[k];
        for(i=k;i<n;i++)
        {
            if (total>=at[i] && bt[i]<min)
            {
                temp=p[k];
                p[k]=p[i];
                p[i]=temp;
                temp=at[k];
                at[k]=at[i];
                at[i]=temp;
                temp=bt[k];
                bt[k]=bt[i];
                bt[i]=temp;
            }
        }
        k++;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        sum=sum+bt[i-1];
        wt[i]=sum-at[i];
        sumwt=sumwt+wt[i];
    }
    for(i=0;i<n;i++)
    {
        tot=tot+bt[i];
        tat[i]=tot-at[i];
        sumtat=sumtat+tat[i];
    }
printf("\n\n process \t Burst Time \t Arrival Time \t Waiting Time \t Turn Around Time  \n");
for(i=0;i<n;i++)
    printf("\n  p[%d] \t\t %d \t\t %d \t\t %d \t\t %d \t\t ",i,bt[i],at[i],wt[i],tat[i]);
    printf("\n Average Waiting Time : %f \n",(float)sumwt/(float)n);
    printf("\n Average Turn Around Time : %f \n",(float)sumtat/(float)n);
    return 0;
}


