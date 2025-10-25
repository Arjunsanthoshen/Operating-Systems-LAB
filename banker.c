#include <stdio.h>
int main(){
	int p,c,i,j,count=0,terminate=0;
	printf("Enter the number of processes and resources : ");
	scanf("%d %d",&p,&c);
	int alloc[p][c],max[p][c],need[p][c],avail[c],safe[p],done[p];
	printf("Enter the allocation matrix(%d x %d):\n",p,c);
	for(i=0;i<p;i++){
		for(j=0;j<c;j++){
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter the max matrix:\n");
	for(i=0;i<p;i++){
		for(j=0;j<c;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the available resouce:\n");
		for(i=0;i<c;i++){
			scanf("%d",&avail[i]);
		}
	printf("NEED MATRIX\n");
	for(i=0;i<p;i++){
		done[i]=0;
		for(j=0;j<c;j++){
			need[i][j]= max[i][j]-alloc[i][j];
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}
	while(count<p){
		for(i=0;i<p;i++){
			if(!done[i]){
				for(j=0;j<c;j++){
					if(need[i][j]>avail[j])  
						break;
				}
				if(j==c){
					safe[count++]=i;
					done[i]=1;
					for(j=0;j<c;j++){
						avail[j]+=alloc[i][j];		
					}
					terminate=0;
				}
				else{
					terminate++;
				}
			}
		}
		if(terminate== p-1){
			printf("Not safe\n");
			return 0;
		}
	}
	printf("\n Available resources after completion : \n");
	for(i=0;i<c;i++){
		printf("%d\t",avail[i]);
	}
	printf("\nSafe Sequence : \n");
	for(i=0;i<p;i++){
		printf("p%d\t",safe[i]);
	}
	printf("\n");
	return 0;
}
