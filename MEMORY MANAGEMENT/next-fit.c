#include <stdio.h> 
int main(){
    int memSize[10][2], procesSize[10][3];
	int i, j, tProcess = 0, tMem = 0;
	printf("\nEnter the Total Number of Processes:\t");
	scanf("%d", &tProcess);
	printf("\nEnter the Size of Each Process\n");
	for(int i = 0; i < tProcess; i++){
		printf("Enter Size of Process %d:\t", i + 1);
		scanf("%d", &procesSize[i][0]);
		procesSize[i][1] = 0;
		procesSize[i][2] = i;
	}
	printf("\nEnter Total Memory Blocks:\t");
	scanf("%d", &tMem);
	printf("\nEnter the Size of Each Block:\n");
	for(i = 0; i < tProcess; i++){
	    printf("Enter Size of Block %d:\t", i + 1);
	    scanf("%d", &memSize[i][0]);
		memSize[i][1] = 0;
	}
	for(i = 0; i < tProcess; i++){
		while(j < tMem){
			if(memSize[j][1] == 0 && procesSize[i][0] <= memSize[j][0]){
				procesSize[i][1] = 1;
				memSize[j][1] = 1;
				printf("\nProcess [%d] Allocated to Memory Block:\t%d", i + 1, j + 1);
				break;
			}
			j++;
		}
	}
	for(i = 0; i < tMem; i++){
		if(procesSize[i][1] == 0){
			printf("\nProcess [%d] Unallocated\n", i + 1);
		}
	}
	printf("\n");
	return 0;
}
