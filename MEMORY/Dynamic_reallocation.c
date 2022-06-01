#include <stdio.h>
int main(){
    int baseAdd, addSpace, virAdd;
    printf("Enter the base address and address spcae (in KB): ");
    scanf("%d %d", &baseAdd, &addSpace);
    printf("\nEnter the virtual address (in Bytes): ");
    scanf("%d", &virAdd);
    virAdd = (virAdd)/1024;
    if(virAdd<=addSpace){
        printf("%d\n", virAdd+addSpace);
    }
    else{
        printf("\nVirtual address is out of bound");
    }
    return 0;
}