#include<stdio.h>
#include<stdlib.h>

int mtex=1,full=0,empty=3,x=0;
 
void main()
{
	int c;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:	if((mtex==1)&&(empty!=0))
						producer();
					else
						printf("Buffer is full!!");
					break;
			case 2:	if((mtex==1)&&(full!=0))
						consumer();
					else
						printf("Buffer is empty!!");
					break;
			case 3:
					exit(0);
					break;
		}
	}
	
	return 0;
}
 
int wait(int s)
{
	return (--s);
}
 
int signal(int s)
{
	return(++s);
}
 
void producer()
{
	mtex=wait(mtex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\nProducer produces the item %d",x);
	mtex=signal(mtex);
}
 
void consumer()
{
	mtex=wait(mtex);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumes item %d",x);
	x--;
	mtex=signal(mtex);
}

