#include <stdio.h>
#include <math.h>

int main(){
    int logAdd, pno, off, pSize;
    printf("Enter the size of logical address space (in bytes): ");
    scanf("%d", &logAdd);
    printf("Enter the page size (in bytes): ");
    scanf("%d", &pSize);

    int m,n;
    m = log(logAdd)/log(2); //virtual add in bits
    n = log(pSize)/log(2); //page size in bits 
    printf("m=%d  n =%d", m,n);

    pno = m-n;
    printf("\nNumber of pages: %d", pno);
    off = n;
    printf("\nOffset: %d", off);

    int phyMem, fNo;
    printf("\nEnter the physical memory size (in KB): ");
    scanf("%d", &phyMem);
    phyMem = phyMem*1024; //converted to bits
    printf("\nPhysical memory in bits is: %d", phyMem);

    fNo = phyMem/pSize;
    printf("\nThe number of frames in the physicial memory is: %d", fNo);

    int page[100];
    printf("\nEnter the frame number of the pages: ");
    for(int i=0; i<(logAdd/pSize); i++){
        printf("\nPage \tFrame");
        printf("\n%d\t", i);
        scanf("%d", &page[i]);
    }

    int virAdd;
    printf("\nEnter the virtual address for which you need the physical address for: ");
    scanf("%d", &virAdd);

    int arr[m];
    for(int i=m-1;i>=0;i--){
        if (virAdd !=0){
            arr[i] = virAdd%2;
            virAdd/=2;
        }
        else{
            arr[i]=0;
        }
    }

    printf("\n");
    for(int i=0;i<m;i++){
        printf("%d", arr[i]);
    }
    int pageNo=0;
    int t = m-n;
    for( int i=t-1; i>=0; i--){
        pageNo += arr[i] * pow(2,t-i-1);
    }
    printf("\nPage number: %d", pageNo);

    int offset=0,c=0;
    for(int i=(m-1); i>=(m-n); i--){
        offset +=arr[i]*pow(2,c++);
    }
    printf("\nOffset: %d", offset);

    int phyAdd;
    phyAdd = (page[pageNo] * pSize) + offset;
    printf("\nPhysical Address is: %d", phyAdd);

    return 0;
}


// phyadd = (base[x] * psize) + m;
// printf("\nThe physical address is : %d ",phyadd);