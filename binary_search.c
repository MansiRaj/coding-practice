#include <stdio.h>

void binary_serach(int arr[], int low, int high,int val){
    int mid=0;
    while(low<=high){
        (mid=low+high)/2;
        if(arr[mid]==val){
            printf("found at position %d",mid);
            return;
        }
        else if(arr[mid]>val){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    printf("not found");
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
   binary_serach(array,0,4,v);
}