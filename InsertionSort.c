#include <stdio.h>

void InsertionSort(int *arr,int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main() {
    int arr[6]={50,30,10,70,40,60};
    InsertionSort(arr,5);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}