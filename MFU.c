#include<stdio.h>
#include<stdlib.h>
void main(){
	int hit=0,miss=0,pno,fno,min;
	int frames[10],pages[20];
	int frameAge[50],frameFreq[50];

	printf("Enter number of frames\n");
	scanf("%d",&fno);
	printf("Enter number of pages\n");
	scanf("%d",&pno);
	printf("Enter the page string: ");
	for(int i=0;i<pno;i++){
		scanf("%d",&pages[i]);
	}
	for(int i=0;i<fno;i++){
		frames[i]=-1;
		frameAge[i]=-1;
	}
    int flag=0,flag1=0,flag2=0;
	int flagFound=0, count=0;
    
	for(int j=0;j<fno;j++)
		frameFreq[j]=0; 
	for(int j=0;j<pno;j++){ 
		int index;
		printf("page:%d   ",pages[j] );
		flagFound=0,flag=0,flag2=0;
		for(int i=0;i<fno;i++){
		    if(frames[i]==pages[j]){	
		    	flagFound=1;
		    	flag=1;
		    	index=i;
		    	printf("HIT");   
		     	hit++;
				break;
		    }
        } 					          
		if(flagFound==0){          //if frame not found and empty frame avalible
		    for(int i=0;i<fno;i++){			        
			    if(frames[i]==-1){       
					frames[i]=pages[j];
					flag=1;
					count++;
				    frameAge[i]=count;
				    miss++;
				    frameFreq[i]=1;
    	            printf("miss ");
				    break;    
				}  
    	    } 
		   if(flag==0){
				int bestmfu=0;
				for(int i=0;i<fno;i++){
					if(frameFreq[i]>frameFreq[bestmfu])
						bestmfu=i;
				}
				frames[bestmfu]=pages[j];
    	        miss++;
				printf("miss ");
				frameFreq[bestmfu]=1;
    	   }

		}  //FLAG FOUND ends
		else{
			frameFreq[index]++;
			for(int i=0;i<fno;i++){
				printf("   %d ",frames[i] );
			}       
			printf("\n");
		}
    	printf("number of hits %d\n",hit );
		printf("number of miss %d\n",miss );

	}
}
