#include<stdio.h>
#include<stdlib.h>
int main(){
 int queue[15],n,head,i,j,diff,seektime=0;
 float avgtime;
 printf("enter the disk head value");
 scanf("%d",&head);
 printf("enter the size of queue");
 scanf("%d",&n);
 for(i=1;i<n+1;i++){
   printf("enter the disk position");
   scanf("%d",&queue[i]);
 }
queue[0]=head;
for(j=0;j<n;j++){
 diff=abs(queue[j+1]-queue[j]);
 seektime+=diff;
}
printf("track movement will be");
for(j=0;j<n+1;j++){
 printf("%d --> ",queue[j]);
}
printf("Total seek time is %d\n",seektime);
avgtime=seektime/(float)n;
printf("Average seek time is %f\n",avgtime);
return 0;
}
