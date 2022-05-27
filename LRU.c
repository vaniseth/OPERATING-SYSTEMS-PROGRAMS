#include<stdio.h>

int findLRU(int time[], int n){
    int min = time[0], pos=0;
    for(int i=1; i<n; ++i){
        if(time[i]<min){
            min=time[i];
            pos=1;
        }
    }
    return pos;
}

int main(){
    int fno, pno, frames[10], pages[30],time[10],pos, faults=0;
    printf("Enter number of frames: "); 
	scanf("%d", &fno);
	printf("Enter number of pages: ");
	scanf("%d", &pno);
	printf("Enter reference string: ");
    for(int i = 0; i < pno; ++i){
		 scanf("%d", &pages[i]);
	}		    
	for(int i = 0; i < fno; ++i){
		frames[i] = -1;
	}

    int flag1, flag2, counter =0;
	for(int i = 0; i < pno; ++i){
        flag1 = flag2 = 0;
        for(int j = 0; j < fno; ++j){
			if(frames[j] == pages[i]){
			    counter++;
			    time[j] = counter;
			    flag1 = flag2 = 1;
    		    break;
			}
		}
        if(flag1 == 0){
			for(int j = 0; j < fno; ++j){
			    if(frames[j] == -1){
					counter++;
		 	        faults++;
					frames[j] = pages[i];
					time[j] = counter;
				    flag2 = 1;
				    break;
		        }
		    }
		}
        if(flag2 == 0){
	        pos = findLRU(time, fno);
		    counter++;
	        faults++;
	        frames[pos] = pages[i];
			time[pos] = counter;
        }
	    printf("\n"); 
	    for(int j = 0; j < fno; ++j){
			printf("%d\t", frames[j]);
        }
	}
    printf("\n\nTotal Page Faults = %d", faults);
    return 0;
}