#include <stdio.h>
void main(){
	int n,temp1,temp2;
	float awt=0,atat=0;
	printf("enter the number of process: ");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n],sbt[n],i,j,pro[n];
	for(i=0;i<n;i++)
	{
		pro[i]=i+1;
		printf("Enter the burst time of process p%d : ",i+1);
		scanf("%d",&bt[i]);
	}
	printf("\nprocess id\tburst time\n");
	for(i=0;i<n;i++)
	{
		printf("p%d\t\t%d\n",pro[i],bt[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(bt[j]>bt[j+1]){
				temp1=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp1;
				temp2=pro[j];
				pro[j]=pro[j+1];
				pro[j+1]=temp2;
			}
		}
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
		printf("p%d\t\t%d\t\t%d\t\t\t%d\n",pro[i],bt[i],tat[i],wt[i]);
	}
	printf("\nAverage waiting time: %.2f\n",awt/n);
	printf("Average Turn around time: %.2f\n\n",atat/n);
	printf("\nGant Chart\n");
	
	for(i=0;i<n;i++)
	{
		printf("   p%d\t",pro[i]);
	}
		printf("\n");
		printf("0");
	for(i=0;i<n;i++)
	{
		printf("\t%d",tat[i]);
	}
	printf("\n");
}