#include<stdio.h>
#define max 25 
    void main(){
    int frag[max],b[max],f[max],blockNo,fileno,temp,low=10000; 
    static int bf[max],ff[max];
    printf("\nEnter the number of blocks:"); 
    scanf("%d",&blockNo);
    printf("Enter the number of files:"); 
    scanf("%d",&fileno);
    printf("\nEnter the size of the blocks:-\n"); 
    for(int i=1;i<=blockNo;i++){
        printf("Block %d:",i);
        scanf("%d",&b[i]);
    }
    printf("Enter the size of the files :-\n"); 
    for(int i=1;i<=fileno;i++){
        printf("File %d:",i);
        scanf("%d",&f[i]);
    }
    for(int i=1;i<=fileno;i++){
        for(int j=1;j<=blockNo;j++){
            if(bf[j]!=1){
                temp=b[j]-f[i]; 
                if(temp>=0) 
                if(low>temp){
                    ff[i]=j;
                    low=temp;
                }
            }
        }
        frag[i]=low; 
        bf[ff[i]]=1; 
        low=10000;
    }
    printf("\nFile No\tFile Size \tBlock No\tBlock Size\tFragment"); 
    for(int i=1;i<=fileno && ff[i]!=0;i++) 
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]); 
    return 0;
}
