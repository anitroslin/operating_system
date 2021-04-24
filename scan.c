#include<stdio.h>
#include<stdlib.h>
int main(){
int queue[15],i,j,head,n,diff,i1,j1,queueR[15],queueL[15],c,element,size,seektime=0;
float avgtime;
printf("enter the size of the queue, the read/write head and range of disk");
scanf("%d%d%d",&n,&head,&size);
for(i=1;i<n+1;i++){
    printf("enter  the disk positions");
    scanf("%d",&element);
    if(element>=head)
    {
      queueR[i1]=element;
      i1++;
    }
    else
    {
      queueL[j1]=element;
      j1++;
    }
 }
for(i=0;i<i1-1;i++)
{
   for(j=i+1;j<i1;j++)
      {
      if(queueR[i]>queueR[j])
        {
       element=queueR[i];
       queueR[i]=queueR[j];
       queueR[j]=element;
        }
     }
}
for(i=0;i<j1-1;i++)
   {
   for(j=i+1;j<j1;j++)
     {
     if(queueL[i]<queueL[j])
       {
        element=queueL[i];
        queueL[i]=queueL[j];
        queueL[j]=element;
       }
    }
}
printf("enter your choice");
scanf("%d",&c);
switch(c){
        case 1:{
         for(i=1,j=0;j<i1;i++,j++)
              queue[i]=queueR[j];
              queue[i]=size;
         for(i=i1+2,j=0;j<j1;i++,j++)
              queue[i]=queueL[j];
              queue[i]=0;
              queue[0]=head;
               }
           break;
        case 2:{
            for(i=1,j=0;j<i1;i++,j++)
                queue[i]=queueR[j];
                queue[i]=size;
                queue[i+1]=0;
            for(i=i1+3,j=0;j<j1;i++,j++)
                queue[i]=queueL[j];
                queue[0]=head;
        }
        break;
        default:
            printf("invalid choice");
    }
 for(j=0;j<=n+2;j++)
        {
        diff=abs(queue[j+1]-queue[j]);
        seektime+=diff;
        }
        printf("track movement will be");
        for(j=0;j<n+3;j++)
            printf("%d --> ",queue[j]);
        printf("Total seek time is %d\n",seektime);
        avgtime=seektime/(float)n;
        printf("Average seek time is %f\n",avgtime);
        return 0;
}

