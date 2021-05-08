#include <stdio.h>

void linear_serach(int *arr, int size, int val){
    for(int i=0;i<size;i++){
        if(*arr==val){
            printf("Found at position %d",i);
            return;
        }
        arr++;
    }
    printf("Not found");
}

int main()
{
   int array[5], v;
   printf("enter the elements");
   for(int i=0;i<5;i++){
       scanf("%d",&array[i]);
   }
   printf("enter the value you want to search");
   scanf("%d",&v);
   linear_serach(array,5,v);
}