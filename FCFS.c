#include <stdio.h>
void main(){
	int n;
	float awt=0,atat=0;
	printf("enter the number of process: ");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n],i;
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of process p%d : ",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	printf("\nprocess id\tburst time\tTurn around time\twaiting time\n");
	for(i=0;i<n;i++)
	{
		if(i!=0){
			wt[i] = wt[i-1]+bt[i-1];
			awt+=wt[i];
		}
		tat[i] = bt[i]+wt[i];
		atat+=tat[i];
		printf("p%d\t\t%d\t\t%d\t\t\t%d\n",(i+1),bt[i],tat[i],wt[i]);
	}
	printf("\nAverage Waiting Time: %.2f\n", awt / n);
    printf("Average Turnaround Time: %.2f\n", atat / n);
	printf("\nGant Chart\n");
	for(i=0;i<n;i++)
	{
		printf("   p%d\t",i+1);
	}
	printf("\n");
	printf("0");
	for(i=0;i<n;i++)
	{
		printf("\t%d",tat[i]);
	}
	printf("\n");
}