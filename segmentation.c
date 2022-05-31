#include<stdio.h>
#include<math.h>

int bits(int no){
   return (int)log2(no);
}

int main(){
   int code[2];
   int heap[2];
   int stack[2];
   int logAdd, virAdd;

   printf("\nEnter the logical address space (in KB): ");
   scanf("%d", &logAdd);
   printf("\nEnter the virtual address (in bytes): ");
   scanf("%d", &virAdd);

   printf("\nMake the entires for the segment table");
   printf("\nCode segemnt");
   printf("\nBase\tSize\n");
   scanf("%d\t%d", &code[0], &code[1]);
   printf("\nHeap segemnt");
   printf("\nBase\tSize\n");
   scanf("%d\t%d", &heap[0], &heap[1]); 
   printf("\nStack segemnt");
   printf("\nBase\tSize\n");
   scanf("%d\t%d", &stack[0], &stack[1]);

   int n = bits(logAdd)+10;
   int virMem[n];
   int j = n-1;

   while(j>=0){
      if(virAdd!=0){
         virMem[j]=virAdd%2;
         virAdd=virAdd/2;
      }
      else{
         virMem[j]=0;
         j--;
      }
   }
   int segment=0, count=0;
   for(int i=1; i>=0; i--){
      segment=segment+virMem[i]*pow(2,1-i);
   }
   int off=0;
   for(int i=n-1; i>=2; i--){
      off = off +virMem[i]*pow(2,n-1-i);
   }
   if(segment==0){
      if(off>=code[1]*1024){
         printf("Segmentation Fault");
      }
      else{
         printf("The Physical Address is: %d", (code[0]*1024 + off));
      }
   }
   else if(segment==1){
      if(off>=heap[1]*1024){
         printf("Segementation Fault");
      }
      else{
         printf("The physical Address is: %d", (heap[0]*1024 + off));
      }
   }
   // segement == 2 is empty for free space
   else if(segment==3){
         if(off>=stack[1]*1024){
            printf("Segmentation Fault");
         }
         else{
            printf("The Physical Address is: %d", (stack[0]*1024 + off));
         }
   }
   return 0;
}


//while compiling worte the command  gcc segmentation.c -o segmentation.o -lm
