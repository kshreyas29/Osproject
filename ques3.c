#include<stdio.h>
int main()
{
	int k=0,W=1,counter=-1;
	int time,arrtime=0,bursttime=0,small1=100,small=100,point=0,totturn=0,totwait=0,l,x=0;
	int processno[100],arrarray[100],burst[100],turnarray[100],waitarray[100];
	float avgturn,avgwait;
	while(W!=0)
	{
		printf("arrival and burst time\n");
		scanf("%d",&arrtime);
		scanf("%d",&bursttime);
		
		if(arrtime!=0)
		{
			counter++;
			processno[counter]=k;
			arrarray[counter]=arrtime;
			burst[counter]=bursttime;
			k++;
		}
		else
		{
		k++;
		}
		printf("press 0 to stop\n");
		scanf("%d",&W);
				
	}
	
	
	
	for(k=0;k<=counter;k++)
	{
		if(arrarray[k]<small1)
		{
			small1=arrarray[k];
		}
	}
	
	time=small1;
	
	
	for(k=0;k<=counter;k++)
	{
		for(l=0;l<=counter;l++)
		{
			if(burst[l]<small && arrarray[l]<=time && burst[l]!=0)
			{
				small=burst[l];
				point=l;
				x=1;
			}
		}
		if(x==1)
		{
			time=time+burst[point];
			turnarray[point]=time-arrarray[point];
			waitarray[point]=turnarray[point]-burst[point];
			burst[point]=0;
		}
		
		time=time+2;
	x=0;
		small=100;
	}
	time=time-2;
	printf("\n\nTno.\turnaround\twaiting\n");
	
	for(l=0;l<=counter;l++)
	{
		printf("T%d\t%d\t%d\n",processno[l],turnarray[l],waitarray[l]);
		totturn=totturn+turnarray[l];
		totwait=totwait+waitarray[l];
	}		
	avgturn=totturn/(counter+1);
	avgwait=totturn/(counter+1);
	
	printf("\ntotal time taken = %d\n",time);
	printf("average turnaround time = %f\n",avgturn);
	printf("average waiting time = %f\n",avgwait);
	
			
}
