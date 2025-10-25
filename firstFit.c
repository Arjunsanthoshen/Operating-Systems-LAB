#include <stdio.h>
void main(){
	int i,j,n,m;
	printf("Enter the no. of block : ");
	scanf("%d",&n);
	int block[n];
	for(i=0;i<n;i++){
		printf("Enter the size of block %d : ",i+1);
		scanf("%d",&block[i]);	
	}
	printf("Enter the no. of process : ");
	scanf("%d",&m);
	int pro[m],allocation[m];
	for(i=0;i<m;i++){
		printf("Enter the size of process %d : ",i+1);
		scanf("%d",&pro[i]);
		allocation[i]=-1;
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(block[j]>=pro[i]){
				allocation[i]=j;
				block[j]-=pro[i];
				break;
			}
		}
	}
	printf("\nProcess No\tProcess Size\tBlock no\tRemaining Block Size\n");
	
	for(i=0;i<m;i++){
		if(allocation[i]!=-1){
			printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,pro[i],allocation[i]+1,block[allocation[i]]);
		}else{
			printf("%d\t\t%d\t\tNot allocated\n ",i+1,pro[i]);
		}
	}
}
