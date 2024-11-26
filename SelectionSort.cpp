#include <iostream>
void swap(int* a, int* b) {
    int temp = *a; // Store the value of a in temp
    *a = *b;       // Assign the value of b to a
    *b = temp;     // Assign the value of temp to b
}
void SelectionSort(int *arr,int size){
    for(int i=0;i<size-1;i++){
        int minIndex=i,temp;
        for(int j=i+1;j<size;j++){
            if (arr[j]<arr[minIndex]){     
               minIndex=j;          
            }            
        }swap(&arr[minIndex],&arr[i]);
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