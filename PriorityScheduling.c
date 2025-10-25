#include <stdio.h>
void main(){
	int n;
	float awt=0,atat=0;
	printf("enter the number of process: ");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n],i,p[n],prio[n],j;
	
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of process p%d : ",i+1);
		scanf("%d",&bt[i]);
		printf("Enter the priority of p%d : ",i+1);
		scanf("%d",&prio[i]);
		p[i]=i+1;
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if (prio[j]> prio[j+1]){
				int temp =bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=prio[j];
				prio[j]=prio[j+1];			
				prio[j+1]=temp;
			}
		} 
	}
	
	wt[0]=0;
	printf("\nprocess id\tburst time\tPriority\tTurn around time\twaiting time\n");
	for(i=0;i<n;i++)
	{
		if(i!=0){
			wt[i] = wt[i-1]+bt[i-1];
			awt+=wt[i];
		}
		tat[i] = bt[i]+wt[i];
		atat+=tat[i];
		printf("p%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[i],bt[i],prio[i],tat[i],wt[i]);
	}

	printf("\nAverage waiting time: %f\n",awt/n);
	printf("Average Turn around time: %f\n\n",atat/n);
	printf("\nGant Chart\n");
	for(i=0;i<n;i++){
		printf("   p%d\t",p[i]);
	}
	printf("\n");
	printf("0");
	for(i=0;i<n;i++){
		printf("\t%d",tat[i]);
	}
	printf("\n");
}