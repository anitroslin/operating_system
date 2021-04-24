#include <stdio.h>
int fcfs ( int a[] , int head , int n )
 { int i=0,tst,g;
   tst=a[i]-head;
   for(i=1;i<n;i++)
        { if(a[i]<=a[i-1])
                g=a[i-1]-a[i];
          else
               g=a[i]-a[i-1];
          tst=tst+g;}
   printf("Total seek time is : %d\n",tst);
   return 0;
}
int smallest( int a[], int n)
{ int i,smallest;
  smallest=a[0];
  for(i=1;i<n;i++)
     {if(a[i]<smallest)
           smallest=a[i];
          }
  return smallest;
}
int largest( int a[], int n)
{ int i,largest;
  largest=a[0];
  for(i=1;i<n;i++)
     {if(a[i]>largest)
           largest=a[i];
          }
  return largest;
}
int scan ( int a[], int head, int n )
{int size,tst,la,sma,ch; 
 printf("Enter size of disk:");
 scanf("%d",&size);
 printf("\n1.Towards larger value\n2.Towards smaller value\n");
 printf("Enter choice:");
 scanf("%d",&ch);

 switch(ch)
     { case 1:
            sma=smallest(a,n);
            
            tst=(2*(size-1))-head-sma;
            break;
       case 2:
             la=largest(a,n);
             tst=head+la;
             
             break;
           }
  printf("Total seek time is : %d\n",tst);
 return 0;

 }
int closest(int a[], int head ,int k, int n)
 {  int cl,i,d,l;
    if(a[0]>head)
        d=-(head-a[0]);
    else
        d=head-a[0];
    cl=a[0];
    if(k==1)
     { 
       for(i=1;i<n;i++)
             {if(head>a[i])
                  { l=head-a[i];
                    if(l<d)
                          { d=l;
                            cl=a[i];}
                                 }
                                     }
                                       }
    else if(k==2)
     {for(i=1;i<n;i++)
             {if(head<a[i])
                  { l=a[i]-head;
                    if(l<d)
                          { d=l;
                            cl=a[i];}
                                 }
                                     }
                                       }
  
    return cl;}
int cscan (int a[] , int head , int n)
{ int size,tst,k,cl; 
 printf("Enter size of disk:");
 scanf("%d",&size);
 printf("\n1.Towards larger value\n2.Towards smaller value\n");
 printf("Enter choice:");
 scanf("%d",&k);

 switch(k)
     { case 1:
            cl=closest(a,head,k,n);
            
            tst=(2*(size-1))-head+cl;
            break;
       case 2:
             cl=closest(a,head,k,n);
             tst=head+(2*(size-1))-cl;
             
             break;
           }
  printf("Total seek time is : %d\n",tst);
 return 0;

 }



int main()
{  int a[100];
   int i=0,n,head,k,ch; 
   printf("Enter requests in order: ");
   while(k!=5) 
        { scanf("%d",&a[i]);
          i=i+1;
          printf("Enter 5 to stop :");
          scanf("%d",&k);
          if(k==5)
                  {break;}
          printf("Enter next request:"); 
                            }
   n=i;
   printf("Enter head:");
   scanf("%d",&head);
   printf("MENU \n  1.FCFS\n  2.SCAN\n  3.CSCAN\n  ");
    printf("Enter choice:");
    scanf("%d",&ch);
    while(ch!=0)
    {if(ch==1)
          { fcfs(a,head,n);
            ch=6;  }
    else if(ch==2)
           {scan(a,head,n);
            ch=6;}
    else if(ch==3)
          {  
             cscan(a,head,n);
             ch=6;
              }
    
    else{ printf("Please enter valid choice or enter 0 to exit:");
          scanf("%d",&ch); 
             } }   
     
   return 0; 
}
