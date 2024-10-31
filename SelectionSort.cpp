#include <iostream>
void SelectionSort(int *arr,int size){
    for(int i=0;i<size-1;i++){
        int minIndex=i,temp;
        for(int j=i+1;j<size;j++){
            int maxIndex=j;
            if (arr[minIndex]>arr[maxIndex]){     
                temp=arr[minIndex];
                arr[minIndex]=arr[maxIndex];
                arr[maxIndex]=temp;             
            }else{
                continue;
            }
        }
    }
}

int main() {
    int arr[5]={1,2,4,5,0};
    SelectionSort(arr,5);
    for(int i=0;i<5;i++){
        std::cout<<arr[i]<<" ";
    }
    
    return 0;
}