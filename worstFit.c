#include <stdio.h>
int main() {
    int m, n;    
    printf("Enter the number of blocks: ");scanf("%d", &m);
    printf("Enter the number of processes: ");scanf("%d", &n);
    int blockSize[m], processSize[n], allocation[n];
    printf("Enter the sizes of %d blocks:\n", m);
    for (int i = 0; i < m; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the sizes of %d processes:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int worstIdx = -1; 
        int maxDiff = -1; 
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) { 
                int diff = blockSize[j] - processSize[i]; 
                if (diff > maxDiff) { 
                    worstIdx = j;
                    maxDiff = diff;
                }
            }
        }
        if (worstIdx != -1) { 
            allocation[i] = worstIdx; 
            blockSize[worstIdx] -= processSize[i]; 
        } else {
            printf("Process %d could not be allocated to any block\n", i + 1); 
        }
    }
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
        }
    }
    return 0;
}